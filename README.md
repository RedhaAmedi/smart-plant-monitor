# 🌿 Smart Plant Monitor for Bougainvillea

A little project I made to keep an eye on my bougainvillea plant using an ESP32. It measures soil moisture, temperature, humidity, and light, then sends updates straight to my Telegram so I don’t have to guess when it needs water or more sun.

I had a spare DHT22 sensor from an old project lying around, so I put it to good use here for temperature and humidity.

---

## What’s inside

- **ESP32 board** running C++ with the Arduino framework  
- Soil moisture sensor  
- DHT22 sensor (temperature & humidity)  
- BH1750 light sensor  
- Optional OLED display to see readings right on the spot  
- Telegram bot to get messages on my phone every minute 📲  

---

## How it works

The ESP32 wakes up every minute, checks the sensors, and sends a message with the plant’s status. If the soil is dry or it’s too dark, it adds a little warning so I know to check on the plant ⚠️.

---

## Why this project?

I wanted something simple that doesn’t need fancy equipment - just sensors I already had and my phone to keep an eye on the plant. Perfect for indoor or outdoor potted bougainvillea 🌸.

---

## Hardware

| Component                  | Note                         |
|---------------------------|------------------------------|
| ESP32 Development Board   | Wi-Fi enabled, runs the code  |
| Capacitive Soil Moisture   | Tougher than resistive type   |
| DHT22 Sensor              | Used from an old project      |
| BH1750 Light Sensor       | Measures sunlight intensity   |
| OLED Display (optional)   | See live data on the device   |

---

## Wiring overview

- Soil Moisture → Analog pin (GPIO 34)  
- DHT22 → Digital pin (GPIO 4)  
- BH1750 → I2C (SDA: GPIO 21, SCL: GPIO 22)  
- OLED → Shares the same I2C pins  

---

## Setup

1. Create a Telegram bot via [@BotFather](https://telegram.me/BotFather) and get the bot token 🎫.  
2. Message [@userinfobot](https://telegram.me/userinfobot) to get your chat ID 📩.  
3. Put both values into the code (`BOT_TOKEN` and `CHAT_ID`).  
4. Upload the code to your ESP32 using PlatformIO.  
5. Watch your plant’s updates come to Telegram every minute.


