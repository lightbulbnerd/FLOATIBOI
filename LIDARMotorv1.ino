/* This code combines LIDAR and motor functionality to adjust the speed of the propeller based on distance from
 * and object.
 * Larger distance --> higher speed
 * Smaller distance --> lower speed     
 */
// Libraries
#include <Servo.h>
#include <LIDARLite.h>
#include <LIDARLite_v3HP.h>
#include <Wire.h>

//globals, constants and objects 
#define MAX_SIGNAL 2000
#define MIN_SIGNAL 1000
#define MOTOR_PIN 9
int DELAY = 1000;
Servo motor;
LIDARLite lidarLite;
int cal_cnt = 0;

void setup() {

  //start the lidar code 
  lidarLite.begin(0, true); // Set configuration to default, and I2C to 400 kHz
  lidarLite.configure(0);   // can change this number from zero to something else 
  
  Serial.begin(9600); // Initialize serial connection to display distance readings
  delay(150);
  Serial.println("Program begin...");   //start the motor code
  motor.attach(MOTOR_PIN);
  motor.writeMicroseconds(MAX_SIGNAL);

}

void loop() {
  int dist;
  // lidar
  if ( cal_cnt == 0 ) {
    dist = lidarLite.distance();      // With bias correction
    if(dist < 30){
            motor.writeMicroseconds(1100);     //10%
    } else if ( 31 < dist < 60){
            motor.writeMicroseconds(1200);     //20%
    } else if (61 < dist < 90){
            motor.writeMicroseconds(1300);     //30%
    } else{
            motor.writeMicroseconds(1400);     //40%
    }
  } else {
    dist = lidarLite.distance(false); // Without bias correction
  }
  cal_cnt++;                  // Increment reading counter
  cal_cnt = cal_cnt % 100;
  Serial.print(dist);           // Display distance
  Serial.println(" cm");
  delay(10);
if (Serial.available() > 0)
  {
    int DELAY = Serial.parseInt();
    if (DELAY > 999)
    {
      
      motor.writeMicroseconds(1000);

    }     
  }  
}
