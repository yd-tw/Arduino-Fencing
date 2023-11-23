#include "TCS_3200.h"

TCS_3200 tcs(4, 5, 6, 7, 8);

int red;
int green;
int blue;

void setup() {
  tcs.begin();
  Serial.begin(9600);
}

void loop() {
  red = tcs.red();
  Serial.print(" R = ");
  Serial.print(red);

  green = tcs.green();
  Serial.print(" G = ");
  Serial.print(green);

  blue = tcs.blue();
  Serial.print(" B = ");
  Serial.println(blue);

  if ((green > blue) && (green > red)) {
    Serial.println("detected");
  }
}
