#include "joystick.h"
#include <math.h>

Joystick::Joystick(float axisX, float axisY){
  pinMode(axisX, INPUT);
  pinMode(axisY, INPUT);
  float x = map(analogRead(axisX), 0, 1023, 100, 100);  // dont update dont knoe why
  float y = map(analogRead(axisY), 0, 1023, -100, 100);
  this -> angle = get_angles(this->x, this->y);
  this -> forces = get_forces(this->x, this->y);
}
  


float Joystick::get_angles(float x, float y){
  
// get an angle from noon (or y axis) with logic tan0 = opposit / adjacent

  const long CONV = 180 / 3.14159265358979323846; // convert radian to degree

  if (x > 0 && y > 0){
    // first cadrant o = y, a = x
    float angle = atan(y / x) * CONV ;
    return 90 - angle;
  }
  else if (x > 0 && y < 0) {
    // a = x, y = o
    y = y * -1;
    return 90 + atan( y / x) * CONV;
  }
  else if (x < 0 && y < 0){
  // a = y, o = x
    x = x * -1;
    y = y * -1;
    return 180 + atan(x / y) * CONV;
  }
  else if (x < 0 && y >0){
  // a = y, o = x
  x = x * -1;
  return 270 + atan(x/y) * CONV;
  }
  else if (x == 0 && y > 0){
    return 0;
  }
  else if (x == 0 && y < 0 ){
    return 180;
  }
  else if (y == 0 && x > 0){
    return 90;
  }
  else {
    return 270;
  }
}

float Joystick::get_forces(float x, float y){
  
  // simple average of absolute value
if (x < 0){
  x = -1 * x;
}
if (y < 0){
  y = -1 * y;
}
return (x + y) / 2;
}
