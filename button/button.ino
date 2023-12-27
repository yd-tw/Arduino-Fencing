#include <SPI.h>
#include <RF24.h>

#define switchPin 2

RF24 rf24(7, 8); // CE腳, CSN腳

const byte addr[] = "1Node";
const char msg[] = "Happy Hacking!";

int score = 0;

void setup() {
  rf24.begin();
  rf24.setChannel(83);            // 設定頻道編號
  rf24.openWritingPipe(addr);     // 設定通道位址
  rf24.setPALevel(RF24_PA_MIN);   // 設定廣播功率
  rf24.setDataRate(RF24_250KBPS); // 設定傳輸速率
  rf24.stopListening();           // 停止偵聽；設定成發射模式

  Serial.begin(9600);
}

void loop() {
  int i = digitalRead(switchPin);
  Serial.println(i);
  
  if(i){
    rf24.write(&score, sizeof(score));
    Serial.println(msg);

    score++;
  }
  
  delay(100);
}
