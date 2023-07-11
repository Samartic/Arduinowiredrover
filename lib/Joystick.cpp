#include "joystick.h"
#include <math.h>

#include <Arduino.h>

Joystick::Joystick(uint8_t pinX, uint8_t pinY, uint8_t pinP){
  pinx = pinX;
  piny = pinY;
  pinp = pinP;
  float x;
  float y;
  float angle;
  float forces;
}

void Joystick::begin(){
  pinMode(pinx, INPUT);
  pinMode(piny, INPUT);
  pinMode(pinp, INPUT);
}

void Joystick::update(){
  x = map(analogRead(pinx),0,1023,100,-100);
  y = map(analogRead(piny),0, 1023, -100, 100);
  p = analogRead(pinp);
  get_angle();
  get_forces();
}
void Joystick::get_angle(){

  const long CONV = 180 / 3.14159265358979323846; // convert radian to degree

  if (x > 0 && y > 0){
    // first cadrant o = y, a = x
    float angle = atan(y / x) * CONV ;
    angle = 90 - angle;
  }
  else if (x > 0 && y < 0) {
    // a = x, y = o
    y = y * -1;
    angle = 90 + atan( y / x) * CONV;
  }
  else if (x < 0 && y < 0){
  // a = y, o = x
    x = x * -1;
    y = y * -1;
    angle = 180 + atan(x / y) * CONV;
  }
  else if (x < 0 && y >0){
  // a = y, o = x
  x = x * -1;
  angle = 270 + atan(x/y) * CONV;
  }
  else if (x == 0 && y > 0){
    angle = 0;
  }
  else if (x == 0 && y < 0 ){
    angle = 180;
  }
  else if (y == 0 && x > 0){
    angle = 90;
  }
  else if (y == 0 && x == 0){
    angle = 0;
  }
  else {
    angle = 270;
  }


}

void Joystick::get_forces(){
  float a;
  float b;
  if (x < 0) {
    a = x * -1;
  }
  else{
    a = x;
  }
  if (y < 0){
    b = y * -1;
  }
  else {
    b = y;
  }
  if (b > a) {
    forces = b * 2;
    }
  else {
    forces = a * 2;
    }
}

bool Joystick::ispressed(){
  return (p != HIGH);
}
