#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#ifndef Display_H
#define Display_H
typedef class Display {
    private:
        Adafruit_SSD1306* pDisplay;
    public:
      Display() {
        static Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
        if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { //Ive changed the address //already chill
          Serial.println(F("SSD1306 allocation failed"));
        } else {
          display.display();
          delay(2000); // Pause for 2 seconds
          // Clear the buffer
          display.clearDisplay();
        }
      }
} Display;
#endif
