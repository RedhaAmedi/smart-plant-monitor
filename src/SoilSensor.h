
#ifndef SOIL_SENSOR_H
#define SOIL_SENSOR_H

class SoilSensor {
  int pin;
public:
  SoilSensor(int p): pin(p) {}
  void begin() { }
  int getMoisture() {
    int value = analogRead(pin);
    return map(value, 4095, 1500, 0, 100);
  }
};

#endif
