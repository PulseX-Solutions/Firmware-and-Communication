#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristic = NULL;
bool deviceConnected = false;

#define SERVICE_UUID "94f39d29-7d6d-437d-973b-fba39e49d4ee"
#define CHARACTERISTIC_UUID "94f39d29-7d6d-437d-973b-fba39e49d4ee"

class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

void setup() {
  Serial.begin(115200);
  
  // Create the BLE Device
  BLEDevice::init("ESP32_BLE_Server");
  
  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
                    
  pCharacteristic->addDescriptor(new BLE2902());

  // Start the service
  pService->start();
  
  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a connection...");
}

void loop() {
  if (deviceConnected) {
    // Send data to the client
    pCharacteristic->setValue("Hello from ESP32");
    pCharacteristic->notify();
    delay(1000); // Delay for 1 second
  }
}
