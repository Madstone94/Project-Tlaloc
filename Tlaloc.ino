#include "AirSensor.h"
#include "LightSensor.h"
#include "Display.h"

LightSensor light;
AirSensor air;
Display pDisplay;

void setup() {
  Serial.begin(9600);
  Greeting();
}

void loop() {
  light.Report();
  air.ReportTemp();
  air.ReportHumid();
}
void Greeting() {
  Serial.println(F("------------------------------------"));
  Serial.println(F("TLALOC"));
  Serial.println(F("Created By: Matthew Stone"));
  Serial.println(F("Version: 1.0"));
  Serial.println(F("------------------------------------"));
}
