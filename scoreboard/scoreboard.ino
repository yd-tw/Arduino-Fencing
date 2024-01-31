#include <SPI.h>
#include <RF24.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

RF24 rf24(7, 8);  // CE腳, CSN腳

const byte addr[] = "1Node";
const byte pipe = 1;  // 指定通道編號
const char a[] = "1";

int mode = 0;
int score = 0;

void setup() {
  Serial.begin(9600);
  rf24.begin();
  rf24.setChannel(83);  // 設定頻道編號
  rf24.setPALevel(RF24_PA_MIN);
  rf24.setDataRate(RF24_250KBPS);
  rf24.openReadingPipe(pipe, addr);  // 開啟通道和位址
  rf24.startListening();             // 開始監聽無線廣播
  Serial.println("nRF24L01 ready!");

    // 偵測是否安裝好OLED了
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 一般1306 OLED的位址都是0x3C
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // 清除畫面
  display.clearDisplay();
  testdrawstyles();    // 測試文字
}

void loop() {
  count();
  testdrawstyles();

  Serial.print("score:");
  Serial.println(score);
}

void count() {
  int i = 0;
  while (i < 5) {
    if (rf24.available(&pipe)) {
      char msg[32] = "";
      rf24.read(&msg, sizeof(msg));
      Serial.println(msg);  // 顯示訊息內容

      if (msg[0] == a[0]) {
        if (mode == 0) {
          score++;
        }

        mode = 1;
        return;
      } else {
        delay(50);
        i++;
      }
    }
  }
  if (mode == 1) {
    mode = 0;
    score++;
  }
}

void testdrawstyles(void) {
  display.clearDisplay();
  display.setTextSize(8);             // 設定文字大小
  display.setTextColor(1);        // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
  display.setCursor(40,8);             // 設定起始座標
  display.print(score);        // 要顯示的字串
  display.display();                  // 要有這行才會把文字顯示出來
  delay(1000);
}