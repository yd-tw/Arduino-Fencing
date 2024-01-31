#include <SPI.h>
#include <RF24.h>
#include "src/TCS3200/TCS3200.h"

#define switchPin 2

TCS3200 tcs(4, 5, 6, 7, 8);
RF24 rf24(7, 8);  // CE腳, CSN腳

const byte addr[] = "1Node";
char T[] = "1";
char F[] = "0";

int red;
int green;
int blue;
int i = 0;

void setup() {
  tcs.begin();

  rf24.begin();
  rf24.setChannel(83);             // 設定頻道編號
  rf24.openWritingPipe(addr);      // 設定通道位址
  rf24.setPALevel(RF24_PA_MIN);    // 設定廣播功率
  rf24.setDataRate(RF24_250KBPS);  // 設定傳輸速率
  rf24.stopListening();            // 停止偵聽；設定成發射模式

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
    i = 1;
  } else {
    i = 0;
  }

  if (i == 1) {
    rf24.write(&T, sizeof(T));
  } else {
    rf24.write(&F, sizeof(F));
  }

  Serial.println(i);

  delay(100);
}
