#ifndef VECTORJH
#define VECTOR_H


class Vector {
  private:

  public:
    Vector(float Angle, float Forces);
    float angle;
    float force;
    void set(float a, float f);
};

#endif
