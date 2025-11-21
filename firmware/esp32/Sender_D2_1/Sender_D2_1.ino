#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLEServer* pServer;
BLECharacteristic* pCharacteristic;

#define SERVICE_UUID        "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID "6E400002-B5A3-F393-E0A9-E50E24DCCA9E" 

void setup() {
  Serial.begin(115200);

  BLEDevice::init("ESP32 BLE");
  pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_READ
                    );
  pCharacteristic->addDescriptor(new BLE2902());

  pService->start();
  // Make the ESP32 discoverable by advertising the service
  pServer->getAdvertising()->start();
  Serial.println("Waiting for client connection to notify...");
}

void loop() {
  if (Serial.available()) {
    // There's data coming from the serial monitor
    String value = Serial.readStringUntil('\n'); // Read the input until newline
    value.trim(); // Trim any whitespace
    
    if (value.length() > 0) {
      // Only proceed if the string is not empty
      Serial.println("Sending: " + value); // Echo back to Serial Monitor
      pCharacteristic->setValue(value.c_str());
      pCharacteristic->notify();
    }
  }
  delay(10); // Small delay to be responsive but use less CPU
}
