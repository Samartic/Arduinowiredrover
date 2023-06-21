#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

class MotorDriver{
  private:
    uint8_t speed;
    uint8_t in1;
    uint8_t in2;

  public:
  void MotorDriver(uint8_t Speed, uint8_t In1, uint8_t In2);
  void begin();
  void move(float forces);
};


#endif
