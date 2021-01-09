void setup() {
  Serial.begin(9600);
  Greeting();
  StartAirSensor();
}

void loop() {
  ReportAir();
}

void Greeting() {
  Serial.println(F("------------------------------------"));
  Serial.println(F("TLALOC"));
  Serial.println(F("Created By: Matthew Stone"));
  Serial.println(F("Version: 1.0"));
  Serial.println(F("------------------------------------"));
}
