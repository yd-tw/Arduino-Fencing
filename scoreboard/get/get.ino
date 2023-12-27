#include <SPI.h>
#include "RF24.h"

RF24 rf24(7, 8); // CE腳, CSN腳

const byte addr[] = "1Node";
const byte pipe = 1;  // 指定通道編號

void setup() {
  Serial.begin(9600);
  rf24.begin();
  rf24.setChannel(83);  // 設定頻道編號
  rf24.setPALevel(RF24_PA_MIN);
  rf24.setDataRate(RF24_250KBPS);
  rf24.openReadingPipe(pipe, addr);  // 開啟通道和位址
  rf24.startListening();  // 開始監聽無線廣播
  Serial.println("nRF24L01 ready!");
}

void loop() {
  if (rf24.available(&pipe)) {
    char msg[32] = "";
    rf24.read(&msg, sizeof(msg));
    Serial.println(msg); // 顯示訊息內容 
  }
}
