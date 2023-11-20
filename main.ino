#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// 儲存由光電二極體讀取的值
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int redvalue = 0;
int greenvalue = 0;
int bluevalue = 0;

void setup() {
  // 設定S0~S4為輸出
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // 設定 sensorOut 為輸出
  pinMode(sensorOut, INPUT);

  // 設定頻率尺度(frequency scaling)為 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // 開始串列通訊
  Serial.begin(9600);
}

void loop() {
  redvalue = red();
  Serial.print(" R = ");
  Serial.print(redvalue);
  
  greenvalue = green();
  Serial.print(" G = ");
  Serial.print(greenvalue);
  
  bluevalue = blue();
  Serial.print(" B = ");
  Serial.println(bluevalue);

  if(greenvalue>bluevalue && greenvalue<redvalue){
    Serial.println("ya!");
  }
}

int red() {
  // 設定光電二極體讀取濾過的紅色值
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // 讀取輸出頻率
  redFrequency = pulseIn(sensorOut, LOW);
  delay(100);

  return redFrequency;
}

int green() {
  // 設定光電二極體讀取濾過的綠色值
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // 讀取輸出頻率
  greenFrequency = pulseIn(sensorOut, LOW);
  delay(100);

  return redFrequency;
}

int blue() {
  // 設定光電二極體讀取濾過的藍色值
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // 讀取輸出頻率
  blueFrequency = pulseIn(sensorOut, LOW);
  delay(100);

  return redFrequency;
}
