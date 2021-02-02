#ifndef LightSensor_H
#define LightSensor_H
typedef class LightSensor {
    private:
      const int threshold = 10;
      const int sensorPin = A0;
      void Greeting() {
        Serial.println(F("Light Sensor"));
        Serial.println(F("------------------------------------"));
      }
    public:
      LightSensor() {
        Greeting();
      }
      float Report() {
        int value = analogRead(sensorPin); 
        float resistance = (float)(1023-value)*10/value;
        Serial.print  (F("Light Sensor Reading:  ")); Serial.println(value);
        Serial.print  (F("Resistance:  ")); Serial.println(resistance);
        return resistance;
      }
} LightSensor;
#endif
