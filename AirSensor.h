#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define PIN 3
#define TYPE DHT11

#ifndef AirSensor_H
#define AirSensor_H
typedef class AirSensor {
    private:
      sensor_t sensor;
      DHT_Unified* pointer;
      uint32_t airDelay;
      int convert;
    public:
      AirSensor() {
        this->convert = 0;
        static DHT_Unified air(PIN,TYPE);
        pointer = &air;
        air.begin();
        air.temperature().getSensor(&sensor);
        air.humidity().getSensor(&sensor);
        this->airDelay = sensor.min_delay / 1000;
      }
      double ReportTemp() {
        delay(airDelay);
        // Get temperature event and print its value.
        sensors_event_t event;
        pointer->temperature().getEvent(&event);
        if (isnan(event.temperature)) {
          Serial.println(F("Error reading temperature!"));
          return -1;
        } else {
          double temp = event.temperature;
          Serial.print(F("Temperature: "));
          Serial.print(temp);
          Serial.println(F("°C"));
          return temp;
        }
      }
      double ReportHumid() {
        sensors_event_t event;
        // Get humidity event and print its value.
        pointer->humidity().getEvent(&event);
        if (isnan(event.relative_humidity)) {
          Serial.println(F("Error reading humidity!"));
          return -1;
        } else {
          double humid = event.relative_humidity;
          Serial.print(F("Humidity: "));
          Serial.print(event.relative_humidity);
          Serial.println(F("%"));
          return humid;
        }
      }
} AirSensor;
#endif
