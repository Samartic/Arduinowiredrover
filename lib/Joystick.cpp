#include "Joystick.h"
#include <math.h>

#include <Arduino.h>
float get_axis(float x, float y);

Joystick::Joystick(uint8_t pinX, uint8_t pinY, uint8_t pinP){
  pinx = pinX;
  piny = pinY;
  pinp = pinP;
  float x;
  float y;
  float angle;
  float forces;
  int clicked;
}


void Joystick::begin(){
  pinMode(pinx, INPUT);
  pinMode(piny, INPUT);
  pinMode(pinp, INPUT);
  clicked = 0; 
}

void Joystick::update(){
  x = analogRead(pinx);
  y = analogRead(piny);
  p = analogRead(pinp);
  get_angle();
  get_forces();
  clicked = (p == LOW) ? clicked++: clicked;

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
  float mappedx = map(x, 0, 1023, -100, 100);
  float mappedy = map(y, 0, 1023, -100, 100);
  a = (mappedx < 0) ? abs(mappedx): mappedx;
  b = (mappedy < 0) ? abs(mappedy): mappedy;
  forces = (b > a) ? b: a;
    
}

bool Joystick::ispressed(){
  return (p != HIGH);
}

bool Joystick::isengaged(){
  return clicked % 2 != 0;
}

int Joystick::countclick(){
  return clicked;
}
void Joystick::resetclick(){
  clicked = 0;
}


