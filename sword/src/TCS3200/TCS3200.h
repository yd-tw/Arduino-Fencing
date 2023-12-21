#ifndef TCS3200_h
#define TCS3200_h

#include <Arduino.h>

class TCS3200 {
public:
  TCS3200(int s0, int s1, int s2, int s3, int out);
  void begin();
  int red();
  int green();
  int blue();

private:
  int _s0;
  int _s1;
  int _s2;
  int _s3;
  int _out;
};

#endif