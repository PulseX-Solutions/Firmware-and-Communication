# Firmware

ESP32 and ESP8266 Arduino sketches for various communication protocols.

## ESP32 Sketches

### `both_Tx_RX/`
**BLE Bidirectional UART Service**
- Uses BLE (Bluetooth Low Energy) for wireless communication
- Implements UART service with TX and RX characteristics
- Can send and receive data simultaneously
- **Target:** ESP32
- **Libraries:** BLEDevice, BLEServer, BLEUtils, BLE2902
- **Service UUID:** `4fafc201-1fb5-459e-8fcc-c5c9c331914b`

### `Sender_D2_1/`
**BLE Notify/Read Example**
- Sends data via BLE notifications
- Reads input from Serial Monitor and broadcasts over BLE
- **Target:** ESP32
- **Libraries:** BLEDevice, BLEServer, BLEUtils, BLE2902

### `esp_mqtt_datasent/`
**MQTT Publisher with WiFi**
- Connects to WiFi network
- Publishes sensor data to MQTT broker
- Subscribes to control topics for LED control
- **Target:** ESP32
- **Libraries:** WiFi, PubSubClient
- **Default broker:** `broker.mqtt-dashboard.com` (public test broker)
- **Topics:** `CurrentEOGValue` (publish), `led_control` (subscribe)

## ESP8266 Sketches

### `mqtt_esp8266/`
**Basic MQTT Client**
- Example MQTT client for ESP8266
- Publishes and subscribes to test topics
- **Target:** ESP8266
- **Libraries:** ESP8266WiFi, PubSubClient
- **Default broker:** `192.168.108.47` (configure to your broker IP)

### `esp8266_to_server/`
**ESP8266 to Server Example**
- Sends sensor data to a server
- **Target:** ESP8266

### `Mqtt1/` and `Mqtt_1/`
**Additional MQTT Examples**
- Variations of MQTT client implementations
- **Target:** ESP8266

## Configuration

Before flashing any sketch:

1. **Update WiFi credentials:**
   ```cpp
   const char* ssid = "your_SSID";
   const char* password = "your_PASSWORD";
   ```

2. **Update MQTT broker IP:**
   ```cpp
   const char* mqtt_server = "192.168.x.x";  // Your Raspberry Pi IP
   ```

3. **Install required libraries** via Arduino Library Manager

## Flashing Instructions

### Using Arduino IDE
1. Open sketch folder
2. Select correct board: Tools → Board → ESP32/ESP8266
3. Select correct port: Tools → Port
4. Click Upload

### Using PlatformIO
1. Create `platformio.ini` in project folder
2. Run `pio run -t upload`

## Serial Monitor

Most sketches output debug information at 115200 baud. Open Serial Monitor to see connection status and data flow.
