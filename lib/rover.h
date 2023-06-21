#ifndefine ROVER_H
#define ROVER_H
#include "MotorDriver.h"
#include "Vector.h"

class Rover(MotorDriver left, MotorDriver right){
  public:
    void move(Vector v, bool p);
  private:
    MotorDriver l;
    MotorDriver r;
};

#endif
