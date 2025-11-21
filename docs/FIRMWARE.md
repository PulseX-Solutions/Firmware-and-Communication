Firmware (ESP8266 / ESP32) summary

Detected sketches (existing locations):
- `both_Tx_RX/both_Tx_RX.ino` — ESP32 BLE UART service (bidirectional)
- `mqtt_esp8266/mqtt_esp8266.ino` — ESP8266 MQTT example
- `final/esp_mqtt_datasent/esp_mqtt_datasent.ino` — ESP32 publishing to MQTT broker
- `esp8266_to_server/esp8266_to_server.ino` — ESP8266 -> server example
- `day1/esp32_BT/esp32_BT.ino` — early ESP32 Bluetooth sketches
- `day1/BLE_server/BLE_server.ino` — BLE server example
- `Sender_D2_1/Sender_D2_1.ino` — BLE notify/read example
- `Mqtt_1/Mqtt_1.ino` and `Mqtt1/Mqtt1.ino` — additional MQTT sketches

Notes and recommendations

- Many sketches are Arduino/PlatformIO-compatible. State the target board (ESP32 or ESP8266) at the top of each sketch and list required libraries (e.g., `PubSubClient`, `ESP8266WiFi`, `WiFi.h`, `BLEDevice`).
- Add a short comment header in each `.ino` describing: purpose, target board, required libraries, broker IP (if applicable), and pins used.
- Consider grouping all ESP sketches under a `firmware/esp32/` and `firmware/esp8266/` folder for clarity. This is optional; I can move them for you.