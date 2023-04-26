#define LED_PIN D4
void setup() {
  pinMode(LED_PIN,OUTPUT);    //กำหนด PIN D4 เป็น OUTPUT
}

void loop() {
  digitalWrite(LED_PIN,!digitalRead(LED_PIN));     //กำหนด OUTPUT ของ PIN D4
  delay(500);           //หน่วงเวลา 500ms หรือเท่ากับ 0.5 วินาที
}
