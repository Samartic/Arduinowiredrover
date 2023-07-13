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

  float mappedx = map(x, 0, 1023, -100, 100);
  float mappedy = map(y, 0, 1023, -100, 100);

  if (mappedx > 0 && mappedy > 0){
    // first cadrant o = y, a = mappedx
    float angle = 90 - atan(mappedy / mappedx) * CONV;
  }
  else if (mappedx > 0 && mappedy < 0) {
    // a = x, y = o
    angle = 90 + atan(abs(mappedy) / mappedx) * CONV;
  }
  else if (mappedx < 0 && mappedy < 0){
  // a = y, o = x
    angle = 180 + atan(abs(mappedx) / abs(mappedy)) * CONV;
  }
  else if (mappedx < 0 && mappedy >0){
  // a = y, o = x
  angle = 270 + atan(abs(mappedx)/mappedy) * CONV;
  }
  else if (mappedx == 0 && mappedy >= 0){
    angle = 0;
  }
  else if (mappedx == 0 && mappedy < 0 ){
    angle = 180;
  }
  else if (mappedy == 0 && mappedx > 0){
    angle = 90;
  }
  else {
    angle = 270;
  }


}

void Joystick::get_forces(){
  float a;
  float b;
  float mappedx = map(x, 0, 1023,-100,100);
  float mappedy = map(y, 0, 1023, -100, 100);
  a = abs(mappedx);  
  b = abs(mappedy);
  forces = (b >= a) ? b: a; // bigger of a or b;
    
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


