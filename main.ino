#include "TCS_3200.h"

TCS_3200 tcs(4, 5, 6, 7, 8);

void setup() {
  tcs.begin();
  Serial.begin(9600);
}

void loop() {
  int redValue = tcs.red();
  Serial.print(" R = ");
  Serial.print(redValue);

  int greenValue = tcs.green();
  Serial.print(" G = ");
  Serial.print(greenValue);

  int blueValue = tcs.blue();
  Serial.print(" B = ");
  Serial.println(blueValue);

  if (greenValue > blueValue && greenValue < redValue) {
    Serial.println("ya!");
  }
}
