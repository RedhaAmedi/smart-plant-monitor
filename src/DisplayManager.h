
#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class DisplayManager
{
  Adafruit_SSD1306 display;

public:
  DisplayManager() : display(128, 64, &Wire) {}
  void begin()
  {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
  }
  void update(float t, float h, int m, uint16_t l)
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.printf("T: %.1fC\nH: %.0f%%\nM: %d%%\nL: %d lx", t, h, m, l);
    display.display();
  }
};

#endif
