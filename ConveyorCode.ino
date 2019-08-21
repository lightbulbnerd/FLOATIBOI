/*This code drives two stepper motors responsible for controlling our conveyor system*/
#include <Motor.h>

Motor conv_mot1; //First conveyor motor
Motor conv_mot2; //Second conveyor motor

Motor mot_on;
Motor mot_off;

#define pixy_in 48
void setup() {

  digitalWrite(stp1, HIGH);
  digitalWrite(stp2, HIGH);

  digitalWrite(MS1_1, LOW); //Can change these to either have full, half, quarter, or 1/8th stepping
  digitalWrite(MS1_2, LOW); // MS1      MS2
  digitalWrite(MS2_1, LOW); // L        L     FullStep
  digitalWrite(MS2_2, LOW); // H        L     HalfStep
                            // L        H     QuaterStep
                            // H        H     1/8th Step
  
  //motor 1 pin setup
  pinMode(stp1, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(MS1_1, OUTPUT);
  pinMode(MS2_1, OUTPUT);
  pinMode(EN1, OUTPUT);
  //motor 2 pin setup
  pinMode(stp2, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(MS1_2, OUTPUT);
  pinMode(MS2_2, OUTPUT);
  pinMode(EN2, OUTPUT);
  
  Serial.begin(9600); //Open Serial connection for debugging  
}


void loop() {

//  if(pixy_in)
//  {
//      mot_on.enable_mot();
//    for(int i=1;i<1000;i++)
//    {
//      conv_mot1.stepForward();
//    }
//  }
  
  mot_on.enable_mot();
  for(int i=1;i<1000;i++)
  {
  conv_mot1.stepForward();
  
  }
  //delay(10);
  //conv_mot2.stepForward();}
