#ifndef CAMERA_H
#define CAMERA_H

#include "MotorDriver.h"

class camera {
  private:
    MotorDriver x;
    MotorDriver y;

  public:
    void Camera(MotorDriver val_x, MotorDriver val_y)
    void begin();
    void move(float x, float y);
};


#endif
