//Motor Header

#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

//Motor 1
#define stp1 28 //Any transition on this pin from LOW to HIGH will trigger the motor to step forward one step. Direction and size of step is controlled by DIR and MSx pin settings.
#define dir1 30 //This pin determines the direction of motor rotation. Changes in state from HIGH to LOW or LOW to HIGH only take effect on the next rising edge of the STEP command.
#define MS1_1 24
#define MS2_1 26
#define EN1  22 //Enables the FET functionality within the motor driver. If set to HIGH, the FETs will be disabled, and the IC will not drive the motor. If set to LOW, all FETs will be enabled, allowing motor control.
//Motor 2
#define stp2 29
#define dir2 31
#define MS1_2 25
#define MS2_2 27
#define EN2 23

class Motor {
  public:
        //Motor();
        //~Motor();
        void stepForward(); //Will step motors in the forward direction
        void stepReverse(); //Will step motors in the reverse direction
    void enable_mot(); //Pushes the enable pin on the motor drivers LOW to allow motor control
    void disable_mot(); //Pushes the enable pin in the motor drivers HIGH to disable motor control
        void halt(); //Emergency stop WIP
};
#endif
