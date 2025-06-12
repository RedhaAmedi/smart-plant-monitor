
#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Wire.h>
#include <BH1750.h>

class LightSensor
{
  BH1750 lightMeter;

public:
  void begin()
  {
    Wire.begin();
    lightMeter.begin();
  }
  uint16_t getLightLevel()
  {
    return lightMeter.readLightLevel();
  }
};

#endif
