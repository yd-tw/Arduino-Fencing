// TCS_3200.h

#ifndef TCS_3200_h
#define TCS_3200_h

#include <Arduino.h>

class TCS_3200 {
public:
  TCS_3200(int s0, int s1, int s2, int s3, int sensorOut);
  void begin();
  int red();
  int green();
  int blue();

private:
  int _s0;
  int _s1;
  int _s2;
  int _s3;
  int _sensorOut;
  int _redFrequency;
  int _greenFrequency;
  int _blueFrequency;
};

#endif
