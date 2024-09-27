#include "DHT.h"

#define LED_PIN 26  // ขาที่ต่อกับ LED
#define DHTPIN 21   // ขาที่ต่อเซนเซอร์ DHT11
#define DHTTYPE DHT11
#define LDR_PIN 32  // ขาที่ต่อกับ LDR (ขา ADC)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT); // ตั้งค่า LDR เป็น INPUT
  dht.begin();
}

void loop() {
  // อ่านค่าจาก DHT
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // ตรวจสอบค่าที่อ่านจาก DHT
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  } else {
    Serial.print("Humidity: ");
    Serial.println(h);
    Serial.print("Temperature: ");
    Serial.println(t);
     delay(1000);
  }

  // อ่านค่าจาก LDR
  int ldrValue = analogRead(LDR_PIN);
  Serial.print("LDR: ");
  Serial.println(ldrValue);
  delay(1000);
}
