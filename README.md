# ESP32/ESP8266 Communication Protocol Examples

This repository contains firmware examples for ESP32/ESP8266 microcontrollers and host-side scripts (Raspberry Pi/PC) demonstrating various communication protocols including MQTT, Bluetooth (BLE & Classic), and Serial communication.

## 📁 Repository Structure

```
├── firmware/
│   ├── esp32/              # ESP32 sketches (BLE, MQTT)
│   └── esp8266/            # ESP8266 sketches (MQTT, WiFi)
├── host/                   # Raspberry Pi/PC Python scripts
├── arduino_examples/       # Arduino and NRF examples
│   ├── nrf/                # nRF24L01 radio examples
│   └── legacy/             # Early experiments and test code
├── data/                   # Datasets, CSV files, and plotting scripts
├── docs/                   # Additional documentation
├── requirements.txt        # Python dependencies
├── setup_host.sh           # Quick setup script for host environment
└── README.md               # This file
```

## 🚀 Quick Start

### For Host (Raspberry Pi / PC)

1. **Install dependencies:**
   ```bash
   ./setup_host.sh
   ```
   Or manually:
   ```bash
   pip3 install -r requirements.txt
   sudo apt-get install mosquitto mosquitto-clients  # For MQTT
   ```

2. **Start MQTT broker:**
   ```bash
   mosquitto -d
   ```

3. **Run MQTT subscriber:**
   ```bash
   python3 host/server.py
   ```

4. **Run Bluetooth RFCOMM server (optional):**
   ```bash
   python3 host/rfcomm-server.py
   ```

### For ESP32/ESP8266 Firmware

1. **Install Arduino IDE** or **PlatformIO**

2. **Install required libraries:**
   - `PubSubClient` (for MQTT)
   - `ESP8266WiFi` or `WiFi.h` (for network connectivity)
   - ESP32 BLE libraries (built-in for ESP32)

3. **Configure WiFi and MQTT settings** in each sketch:
   - Update `ssid` and `password`
   - Update `mqtt_server` IP address to your Raspberry Pi IP

4. **Flash to your board** using Arduino IDE or PlatformIO

## 📡 Communication Protocols

### MQTT (Message Queuing Telemetry Transport)
- **Firmware:** `firmware/esp32/esp_mqtt_datasent/`, `firmware/esp8266/mqtt_esp8266/`
- **Host:** `host/server.py`
- Publishes sensor data from ESP to Raspberry Pi broker
- Topics: `/esp8266/temperature`, `/esp8266/humidity`, `CurrentEOGValue`

### BLE (Bluetooth Low Energy)
- **Firmware:** `firmware/esp32/both_Tx_RX/`, `firmware/esp32/Sender_D2_1/`
- Bidirectional UART service over BLE
- Use nRF Connect app or custom Python scripts to connect

### Bluetooth Classic (RFCOMM)
- **Host:** `host/rfcomm-server.py`, `host/rfcomm-client.py`
- Serial Port Profile (SPP) communication
- Requires PyBluez library

## 📚 Documentation

See the `docs/` folder for detailed information:
- `docs/FIRMWARE.md` - Firmware sketches overview
- `docs/HOST.md` - Host scripts and dependencies
- `docs/ARDUINO.md` - Arduino/NRF examples
- `docs/DATASET.md` - Data analysis and plotting

## 🔧 Hardware Requirements

- **ESP32** or **ESP8266** development board
- **Raspberry Pi** (or any Linux/macOS/Windows PC)
- Sensors (DHT, analog sensors for EOG, etc.)
- USB cable for programming
- WiFi network or Bluetooth adapter

## 📝 Example Workflow

1. Flash `firmware/esp32/esp_mqtt_datasent/` to ESP32
2. Configure broker IP in sketch to match Raspberry Pi
3. Start `mosquitto` on Raspberry Pi
4. Run `python3 host/server.py` to subscribe
5. ESP32 publishes sensor data every few seconds
6. Host receives and processes data

## 🏆 Competition & Projects

![Competition](docs/images/Competition.jpeg)
![Competition](docs/images/Brainstrom.jpeg)
This project has been used in IEEE Circuit challange and BRAINSTROM competitions showcasing communication protocols and sensor data collection systems.

## 🤝 Contributing

- Place new ESP32 sketches in `firmware/esp32/`
- Place new ESP8266 sketches in `firmware/esp8266/`
- Place new host scripts in `host/`
- Add a header comment to each sketch describing purpose, board, and required libraries

## 📄 License

See individual file headers for attribution and licensing information.
