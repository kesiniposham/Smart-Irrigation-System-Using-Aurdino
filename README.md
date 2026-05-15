# 🌱 Smart Irrigation System Using Arduino

An IoT-based automatic irrigation system that monitors soil moisture, weather conditions, and water tank levels to control a motor pump — with real-time SMS alerts sent to the farmer.

---

## 📌 About

India's growing population demands increased agricultural output. This project addresses water wastage in traditional irrigation by automating the process using low-cost sensors and an Arduino Uno R3. The system turns the motor ON when soil is dry and OFF when sufficient moisture is detected — no manual intervention needed.

---

## ✨ Features

- 🌿 Automatic motor ON/OFF based on soil moisture levels
- 🌦️ Weather-aware logic — skips irrigation if rain is expected (DHT sensor)
- 💧 Water tank level monitoring — shuts motor off if tank is low
- 📱 Real-time SMS alerts to farmer via GSM module
- 🖥️ Live status display on 16×2 LCD
- 📡 Serial monitor logging for debugging

---

## 🛠️ Hardware Required

| Component | Quantity |
|---|---|
| Arduino Uno R3 | 1 |
| DHT11 sensor (temperature + humidity) | 1 |
| Soil moisture sensor (analog) | 1 |
| Water level sensor (analog) | 1 |
| SIM800L / SIM900 GSM module | 1 |
| 5V relay module (1-channel) | 1 |
| 16×2 LCD with I2C backpack | 1 |
| Submersible pump + motor | 1 |
| 10 kΩ resistor (DHT pull-up) | 1 |
| Breadboard + jumper wires | — |

---

## 🔌 Wiring

| Component | Arduino Pin |
|---|---|
| DHT11 DATA | D2 |
| Soil moisture sensor (AO) | A0 |
| Water level sensor (AO) | A1 |
| Relay IN (motor control) | D7 |
| GSM TX → Arduino | D10 |
| GSM RX ← Arduino | D11 |
| LCD SDA | A4 |
| LCD SCL | A5 |

> ⚠️ **Power note:** The GSM module draws up to 2A in bursts. Power it from a separate 5V 2A supply — not from the Arduino 5V pin.

---

## ⚙️ How It Works

1. The **soil moisture sensor** continuously checks moisture levels in the soil.
2. The **DHT11 sensor** reads temperature and humidity to detect weather conditions.
3. The **water level sensor** monitors the tank to prevent dry running.
4. If soil is **dry** and no rain is expected → motor turns **ON** → SMS sent to farmer.
5. If soil is **wet** or rain is likely → motor turns **OFF** → SMS sent to farmer.
6. All status updates are shown on the **LCD display** in real time.

---

## 📊 Block Diagram

```
Power Supply
     │
     ▼
Arduino Uno R3
     │
     ├──── DHT11 Sensor          (weather detection)
     ├──── Soil Moisture Sensor  (moisture level)
     ├──── Water Level Sensor    (tank monitoring)
     ├──── GSM Module            (SMS alerts to farmer)
     ├──── Relay → Motor ON/OFF  (pump control)
     └──── 16×2 LCD Display      (status display)
```

---

## 📚 Libraries Used

Install these via Arduino IDE → Tools → Manage Libraries:

| Library | Author |
|---|---|
| DHT sensor library | Adafruit |
| Adafruit Unified Sensor | Adafruit |
| LiquidCrystal_I2C | Frank de Brabander |

---

## 🚀 Getting Started

### 1. Clone the repository
```bash
git clone https://github.com/kesiniposham/Smart-Irrigation-System-Using-Aurdino.git
```

### 2. Open in VS Code
- Install the **Arduino extension** (by Microsoft)
- Open the `smart_irrigation.ino` file
- Select board: **Arduino Uno**
- Select your COM port

### 3. Configure
Edit these lines in `smart_irrigation.ino`:
```cpp
const char FARMER_NUMBER[] = "+91XXXXXXXXXX";  // your number here

#define SOIL_DRY_THRESHOLD   500  // calibrate for your sensor
#define SOIL_WET_THRESHOLD   300  // calibrate for your sensor
#define WATER_LEVEL_LOW      200  // calibrate for your sensor
```

### 4. Upload
Press `Ctrl+Shift+P` → **Arduino: Upload**

### 5. Calibrate
Open Serial Monitor at **9600 baud** and dip the soil sensor in dry/wet soil to find your threshold values.

---

## 🔍 Serial Monitor Output (example)

```
Smart Irrigation System Ready.
Soil: 620 | Water: 450 | Humidity: 55% | Temp: 29°C
Soil dry, motor ON.
Sending SMS: Smart Irrigation: Soil is DRY. Motor turned ON.
Soil: 280 | Water: 440 | Humidity: 56% | Temp: 29°C
Soil wet / rain likely, motor OFF.
Sending SMS: Smart Irrigation: Sufficient moisture. Motor turned OFF.
```

---

## 🔮 Future Enhancements

- [ ] Farmer remote override — reply SMS to manually control motor
- [ ] Cloud dashboard via Blynk or ThingSpeak
- [ ] Crop-specific moisture threshold presets
- [ ] Animal/human intrusion detection using PIR sensor
- [ ] Solar power integration for off-grid deployment
- [ ] Upgrade to ESP32 for Wi-Fi connectivity

---


