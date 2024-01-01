#include "TCS_3200.h"

TCS3200::TCS3200(int s0, int s1, int s2, int s3, int out) {
  _s0 = s0;
  _s1 = s1;
  _s2 = s2;
  _s3 = s3;
  _out = out;
}

void TCS3200::begin() {
  pinMode(_s0, OUTPUT);
  pinMode(_s1, OUTPUT);
  pinMode(_s2, OUTPUT);
  pinMode(_s3, OUTPUT);
  pinMode(_out, INPUT);
}

int TCS3200::red() {
  digitalWrite(_s2, LOW);
  digitalWrite(_s3, LOW);

  delay(100);
  return pulseIn(_out, LOW);
}

int TCS3200::green() {
  digitalWrite(_s2, HIGH);
  digitalWrite(_s3, HIGH);

  delay(100);
  return pulseIn(_out, LOW);
}

int TCS3200::blue() {
  digitalWrite(_s2, LOW);
  digitalWrite(_s3, HIGH);

  delay(100);
  return pulseIn(_out, LOW);
}
