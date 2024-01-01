#define switchPin 2

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(2);  //讀取按鍵的狀態
  Serial.println(buttonState);

  if(buttonState == LOW){          //如果按鍵按了
    //
  }else{                           //如果按鍵是未按下
    //
  }

  delay(100);
}
