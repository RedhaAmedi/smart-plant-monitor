
#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <DHT.h>
#define DHTTYPE DHT22

class DHTSensor {
  int pin;
  DHT dht;
public:
  DHTSensor(int p): pin(p), dht(p, DHTTYPE) {}
  void begin() { dht.begin(); }
  float getTemperature() { return dht.readTemperature(); }
  float getHumidity() { return dht.readHumidity(); }
};

#endif
