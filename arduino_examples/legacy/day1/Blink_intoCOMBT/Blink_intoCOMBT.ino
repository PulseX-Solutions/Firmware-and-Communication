#include "BluetoothSerial.h"
#include <ArduinoJson.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); // Bluetooth device name
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  // Calculate the capacity for the JSON document
  // This value might need to be adjusted based on the actual content
  const size_t capacity = JSON_OBJECT_SIZE(3) + 60;
  StaticJsonDocument<capacity> doc;
  
  doc["id"] = "ALAT01";
  doc["suhu"] = random(20, 30); // Random temperature value between 20-30
  doc["kelembaban"] = random(60, 80); // Random humidity value between 60-80
  
  serializeJson(doc, SerialBT); // Send the JSON document over Bluetooth
  SerialBT.println(); // Print a new line to separate messages
  
  delay(500); // Wait for half a second
}
