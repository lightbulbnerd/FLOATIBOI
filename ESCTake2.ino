
/*
 * This code is used for manual control of the propellor motor mounted on the back of the FLOATIBOI
 * robot. It was uploaded to an Arduino Mega, which was connected to the Electronic Speed Controller
 * (ESC) for the motor. 
 */
#include <Servo.h>

#define MAX_SIGNAL 2000         //maximum pulse time in microseconds
#define MIN_SIGNAL 1000         //minimum pulse time in microseconds
#define MOTOR_PIN 9             //input pin to the arduino
int DELAY = 1000;

Servo motor;                    //to be able to use the Servo library

void setup() {
  Serial.begin(9600);           //baud rate for serial communication
  delay(1500);
  Serial.println("Program begin...");
  motor.attach(MOTOR_PIN);     //using a function from the servo library to initialize
  motor.writeMicroseconds(MIN_SIGNAL); //for initialization
}

void loop() {
  
  if (Serial.available() > 0)         //as long as serial communications are available,
  {                                   //the input from serial (number between 1000-2000)
    int DELAY = Serial.parseInt();    //is the pulsewidth of the signal, adjusting the speed of
    if (DELAY > 999)                  //the motor.
    {
      motor.writeMicroseconds(DELAY);
    }     
  }
}
