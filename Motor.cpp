#include <Motor.h>


/* Motor::Motor(){
  
} */

void Motor::stepForward(){ 
  digitalWrite(dir1, LOW); //dir pins to move forward
  digitalWrite(dir2, HIGH); //This is so that the motors move the same direction relative to each other
  //for(int x=1; x<2; x++)
  //{
    digitalWrite(stp1, LOW); //Step low first
	digitalWrite(stp2, LOW);
    delay(1);
    digitalWrite(stp1, HIGH);
	digitalWrite(stp2, HIGH);
    delay(1);
  //}
}

void Motor::stepReverse(){
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  for(int x=1; x<1000; x++)
  {
    digitalWrite(stp1, HIGH);
	digitalWrite(stp2, HIGH);
    delay(0.5);
    digitalWrite(stp1, LOW);
	digitalWrite(stp2, LOW);
    delay(0.5);
  }
}

void Motor::enable_mot(){
	digitalWrite(EN1, LOW);
	digitalWrite(EN2, LOW);
}

void Motor::disable_mot(){
	digitalWrite(EN1, HIGH);
	digitalWrite(EN2, HIGH);
}
