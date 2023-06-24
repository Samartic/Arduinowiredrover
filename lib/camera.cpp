#include "Camera.h"
#include "MotorDriver.h"

Camera::Camera(MotorDriver val_x, MotorDriver val_y){
  MotorDriver x = val_x;
  MotorDriver y = val_y;
}

void Camera::begin(){
  x.begin();
  y.begin();
}

void Camera::move(float fx, float fy){
  x.move(fx);
  y.move(fy);
}

