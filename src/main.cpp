
#include "SoilSensor.h"
#include "DHTSensor.h"
#include "LightSensor.h"
#include "DisplayManager.h"
#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>

const char *ssid = "wifi_ssid";
const char *password = "wifi_password";
const char *botToken = "BOT_TOKEN";
const char *chatID = "CHAT_ID";

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

SoilSensor soilSensor(34);
DHTSensor dhtSensor(4);
LightSensor lightSensor;
DisplayManager display;

unsigned long lastTime = 0;
unsigned long interval = 60000;

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  client.setInsecure();
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
  }

  soilSensor.begin();
  dhtSensor.begin();
  lightSensor.begin();
  display.begin();
}

void loop()
{
  if (millis() - lastTime > interval)
  {
    lastTime = millis();

    float temp = dhtSensor.getTemperature();
    float humidity = dhtSensor.getHumidity();
    int soil = soilSensor.getMoisture();
    uint16_t lux = lightSensor.getLightLevel();

    String message = "🌿 Bougainvillea Monitor 🌿\n";
    message += "🌡 Temp: " + String(temp) + " °C\n";
    message += "💧 Humidity: " + String(humidity) + "%\n";
    message += "🌿 Soil Moisture: " + String(soil) + "%";
    if (soil < 30)
      message += " (⚠️ Dry)";
    message += "\n";
    message += "☀️ Light: " + String(lux) + " lux";
    if (lux < 500)
      message += " (⚠️ Low)";

    bot.sendMessage(chatID, message, "");
    display.update(temp, humidity, soil, lux);
  }
}
