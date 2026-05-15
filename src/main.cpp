/***************************************************
 * ESP8266 NTC Temperature Test Code
 * 10k NTC (B=3950), 10k Series Resistor
 * Works with NodeMCU / ESP-12
 ***************************************************/

#include <Arduino.h>

// ---------- USER CONFIG ----------
#define ADC_PIN A0

const float VCC = 3.3;        // Supply voltage
const float R_FIXED = 10000;  // 10k resistor
const float R_NTC_25 = 10000; // NTC resistance at 25°C
const float BETA = 3950;      // Beta value of NTC
// ---------------------------------

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nESP8266 NTC Temperature Test Started");
}

void loop() {

  // 1️⃣ Read ADC
  int adcRaw = analogRead(ADC_PIN);   // 0–1023

  // 2️⃣ Convert ADC to voltage
  float voltage = (adcRaw / 1023.0) * VCC;

  // 3️⃣ Calculate NTC resistance
  float rNTC = R_FIXED * voltage / (VCC - voltage);

  // 4️⃣ Temperature calculation (Beta equation)
  float tempK = 1.0 / (
    (1.0 / 298.15) +
    (1.0 / BETA) * log(rNTC / R_NTC_25)
  );

  float tempC = tempK - 273.15;

  // 5️⃣ Print results
  Serial.print("ADC: ");
  Serial.print(adcRaw);

  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V");

  Serial.print(" | NTC: ");
  Serial.print(rNTC, 0);
  Serial.print(" Ohm");

  Serial.print(" | Temp: ");
  Serial.print(tempC, 2);
  Serial.println(" °C");

  delay(1000);
}
