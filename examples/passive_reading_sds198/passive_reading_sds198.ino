#include <Arduino.h>
#include <SDS198.h>

GuL::SDS198 sds(Serial2);

#define RX2 1
#define TX2 38

void setup()
{
  Serial.begin(9600);

  Serial2.begin(9600, SERIAL_8N1, RX2, TX2);

  sds.setToPassiveReporting();
  sds.pollFirmwareVersion();
}

void loop()
{
  sds.poll();
  delay(20);
  sds.read();

  Serial.print("PM100 (Std): \t");
  Serial.println(sds.getPM100());
  Serial.print("Firmware Version: \t");
  Serial.print(sds.getVersion().year);
  Serial.print(".");
  Serial.print(sds.getVersion().month);
  Serial.print(".");
  Serial.println(sds.getVersion().day);
  Serial.println();
  delay(1000);
}