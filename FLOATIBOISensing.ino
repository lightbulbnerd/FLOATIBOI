/*
 * This code contains the color tracking algorithm for the pixycam that is the basis of our plastic
 * identification system. The color tracking program is uploaded to an Arduino uno, which is then connected
 * to the pixycam, installed on top of a pan and tilt servo. The pan and tilt servos respond to the 
 * output of the program and track the colorful object based on what color signatures the pixy has been
 * trained on. 
 */

#include <Pixy2.h>
#include <PIDLoop.h>

Pixy2 pixy;
PIDLoop panLoop(400, 0, 400, true);
PIDLoop tiltLoop(500, 0, 500, true);
int position = 150;

//----------- trackBlock function

int TrackBlock(int blockCount)      //the trackblock function is the basis of the color tracking
{                                   //functionality - it uses the color blocks that pixy detects 
  int trackedBlock = 0;             //(the color signatures) to track the moving objects based on 
  long maxSize = 0;                 //how the signatures change in the blocks.

  int oldSignature = pixy.ccc.blocks[trackedBlock].m_signature;
  int oldX = pixy.ccc.blocks[trackedBlock].m_x;                 //setting the old signature in the system
  int oldY = pixy.ccc.blocks[trackedBlock].m_y;


  for (int i = 0; i < blockCount; i++)                        //this loop runs as long as pixy has detected
  {                                                           //more than one block - that is, as long
    if ((oldSignature == 0) || (pixy.ccc.blocks[i].m_signature == oldSignature)) //as there is a colored
    {                                                         //object in the frame
      long newSize = pixy.ccc.blocks[i].m_height * pixy.ccc.blocks[i].m_width;
      if (newSize > maxSize)
      {                                                     //the values are then updated with the height
        trackedBlock = i;                                   //and with of the "new block size" - the 
        maxSize = newSize;                                  //changed position of the colored object.
      }
    }
  }


  pixy.setServos(panLoop.m_command, tiltLoop.m_command);

  oldX = pixy.ccc.blocks[trackedBlock].m_x;                   //update the values
  oldY = pixy.ccc.blocks[trackedBlock].m_y;
  oldSignature = pixy.ccc.blocks[trackedBlock].m_signature;
  return trackedBlock;
}

void setup()
{
  Serial.begin(230400);                 //specified baud rate for Pixy
  Serial.print("Starting...\n");
 
  // Initialize the pixy object 
  pixy.init();
  // Change to "color connected components" pixy program
  pixy.changeProg("color_connected_components");
  
}

void loop(){  
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[64]; 
  int32_t panOffset, tiltOffset;          //these variables will control the movement of the serovs
  
  // get active blocks from Pixy
  blocks = pixy.ccc.getBlocks();
  
  if (blocks)
  {        
   
      for (i=0; i<pixy.ccc.blocks[i].m_age; i++){       //as long as blocks are detected,
        Serial.print("Detected ");                      //we will recieve this information about them 
        Serial.print(pixy.ccc.blocks[i].m_age);
        Serial.print(" block. ");
        Serial.print("Coordinates: ");
        Serial.println(pixy.ccc.blocks[i].m_x);
        Serial.println(pixy.ccc.blocks[i].m_y);
        //Serial.println(pixy.ccc.blocks[i].m_age);
      }
   
    
    // calculate pan and tilt "errors" with respect to first block object (blocks[0]), 
    // which is the biggest object (they are sorted by size).  
    panOffset = (int32_t)pixy.frameWidth/2 - (int32_t)pixy.ccc.blocks[0].m_x;
    tiltOffset = (int32_t)pixy.ccc.blocks[0].m_y - (int32_t)pixy.frameHeight/2;  
  
    // update loops
    panLoop.update(panOffset);
    tiltLoop.update(tiltOffset);
  
    // set pan and tilt servos  
    pixy.setServos(panLoop.m_command, tiltLoop.m_command);
   
#if 0 // for debugging
    sprintf(buf, "%ld %ld %ld %ld", rotateLoop.m_command, translateLoop.m_command, left, right);
    Serial.println(buf);   
#endif

  }  
  }
