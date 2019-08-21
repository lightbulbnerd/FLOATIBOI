#define input_pin1 A0
#define input_pin2 A1 

//motor 3 - right motor
#define stp3 38
#define dir3 40           
#define MS1_3 34
#define MS2_3 36
#define EN3 32 

//motor 4
#define stp4 39
#define dir4 41           //left motor, labeled on boi 
#define MS1_4 35
#define MS2_4 37
#define EN3 33

void enable_mot(){
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, LOW);
}

void setup() {
  pinMode(input_pin1, INPUT);
  pinMode(input_pin2, INPUT);
  //Motor 3
  pinMode(stp3, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(MS1_3, OUTPUT);
  pinMode(MS2_3, OUTPUT);
  pinMode(EN3, OUTPUT);

  //Motor 4
  pinMode(stp3, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(MS1_3, OUTPUT);
  pinMode(MS2_3, OUTPUT);
  pinMode(EN3, OUTPUT);

}

void loop() {
  enable_mot();
  if(analogRead(input_pin1) > 0){
    for(int x = 1; x = 20; x++){
      digitalWrite(dir3, HIGH);
      digitalWrite(dir4, LOW);
      delay(1);
      digitalWrite(stp3, LOW);
      delay(1);
    } else if(analogRead(input_pin1)==0) {
      for(int x = 1; x<20; x++){
        digitalWrite(dir3, LOW);
        digitalWrite(dir4, LOW);
        digitalWrite(stp3, HIGH);
        delay(1);
        digitalWrite(stp3, LOW);
        delay(1);
      }
    } else {
      digitalWrite(38, LOW);
      digitalWrite(40, LOW);
      digitalWrite(39, LOW);
      digitalWrite(41, LOW);

      
    }
  }
}
