#include "TCS_3200.h"

TCS_3200::TCS_3200(int s0, int s1, int s2, int s3, int sensorOut) {
  _s0 = s0;
  _s1 = s1;
  _s2 = s2;
  _s3 = s3;
  _sensorOut = sensorOut;
}

void TCS_3200::begin() {
  pinMode(_s0, OUTPUT);
  pinMode(_s1, OUTPUT);
  pinMode(_s2, OUTPUT);
  pinMode(_s3, OUTPUT);
  pinMode(_sensorOut, INPUT);

  digitalWrite(_s0, HIGH);
  digitalWrite(_s1, LOW);
}

int TCS_3200::red() {
  digitalWrite(_s2, LOW);
  digitalWrite(_s3, LOW);

  _redFrequency = pulseIn(_sensorOut, LOW);
  delay(100);

  return _redFrequency;
}

int TCS_3200::green() {
  digitalWrite(_s2, HIGH);
  digitalWrite(_s3, HIGH);

  _greenFrequency = pulseIn(_sensorOut, LOW);
  delay(100);

  return _greenFrequency;
}

int TCS_3200::blue() {
  digitalWrite(_s2, LOW);
  digitalWrite(_s3, HIGH);

  _blueFrequency = pulseIn(_sensorOut, LOW);
  delay(100);

  return _blueFrequency;
}
