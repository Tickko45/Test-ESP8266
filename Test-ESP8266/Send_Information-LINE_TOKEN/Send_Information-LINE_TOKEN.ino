/*ไลบรารี่ TridentTD_LineNotify version 2.1
ใช้สำหรับ ส่ง แจ้งเตือนไปยัง LINE สำหรับ ESP8266 และ ESP32
สามารถส่งได้ทั้ง ข้อความ , สติกเกอร์ และรูปภาพ(ด้วย url)
---------------------------------------------------- -
ให้ save เป็น file ต่างหากก่อนถึงจะส่ง Line Notify ภาษาไทยได้
*/
#include <TridentTD_LineNotify.h>
#define SSID "KUNGKO" // บรรทัดที่ 11 ให้ใส่ ชื่อ Wifi ที่จะเชื่อมต่อ
#define PASSWORD "t0631361663" // บรรทัดที่ 12 ใส่ รหัส Wifi
#define LINE_TOKEN "Go5SDokvCgWJQZccQSyaY8gqIK4VJgf54dDsdlkRXqW" // บรรทัดที่ 13 ใส่ รหัส TOKEN ที่ได้มาจากข้างบน
void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n", SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);
  // ตัวอย่างส่งข้อความ
  LINE.notify("ทดสอบส่งข้อความ");
  LINE.notify("ArduinoAll.com");
  // ตัวอย่างส่งข้อมูล ตัวเลข
  LINE.notify(2342); // จำนวนเต็ม
  LINE.notify(212.43434, 5); // จำนวนจริง แสดง 5 หลัก
  // เลือก Line Sticker ได้จาก https://devdocs.line.me/files/sticker_list.pdf
  LINE.notifySticker(3, 240); // ส่ง Line Sticker ด้วย PackageID 3 , StickerID 240
  LINE.notifySticker("Hello", 1, 2); // ส่ง Line Sticker ด้วย PackageID 1 , StickerID 2 พร้อมข้อความ
  // ตัวอย่างส่ง รูปภาพ ด้วย url
  LINE.notifyPicture("https://i.lnwfile.com/_/i/_raw/ro/0n/ly.jpg");
  LINE.notifyPicture("เล่น NodeMCU ESP8266 ALL", "https://i.lnwfile.com/_/i/_raw/ro/0n/ly.jpg");
}
void loop() {
  delay(1);
}
