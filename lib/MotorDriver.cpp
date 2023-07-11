#include "MotorDriver.h"
#include <Arduino.h>


//for L298N motordriver
MotorDriver::MotorDriver(uint8_t Speed, uint8_t In1, uint8_t In2){
  speed = Speed;
  in1 = In1;
  in2 = In2;
}

void MotorDriver::begin(){
  pinMode(speed, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}


//if inverted change the signe in the if statement and minus where needed
void MotorDriver::move(float force){
  if (force < 0){ 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(speed, map(force, -100, 0, 0, 255));
  }
  else {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(speed, map(force, 0,100, 0, 255));
  }
}
