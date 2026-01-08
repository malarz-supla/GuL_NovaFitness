#include <Arduino.h>
#include <SDS011.h>

GuL::SDS011 sds(Serial2);

#define RX2 1
#define TX2 38

void setup()
{
  Serial.begin(9600);

  Serial2.begin(9600, SERIAL_8N1, RX2, TX2);

  sds.setToPassiveReporting();
}

void loop()
{
  sds.poll();
  delay(20);
  sds.read();

  Serial.print("PM2.5 (Std): \t");
  Serial.println(sds.getPM2_5());
  Serial.print("PM10 (Std): \t");
  Serial.println(sds.getPM10());
  Serial.println();
  delay(1000);
}