# Host Scripts

Python scripts for Raspberry Pi or PC to communicate with ESP32/ESP8266 devices.

## Scripts

### `server.py`
**MQTT Subscriber**
- Connects to local MQTT broker (`localhost:1883`)
- Subscribes to sensor data topics from ESP devices
- **Topics monitored:**
  - `/esp8266/temperature`
  - `/esp8266/humidity`
- **Dependencies:** `paho-mqtt`
- **Usage:**
  ```bash
  python3 server.py
  ```

### `rfcomm-server.py`
**Bluetooth RFCOMM Server**
- Creates a Bluetooth Serial Port Profile (SPP) server
- Waits for incoming Bluetooth Classic connections
- Receives and prints data from connected devices
- **Dependencies:** `pybluez`
- **Usage:**
  ```bash
  python3 rfcomm-server.py
  ```

### `rfcomm-client.py`
**Bluetooth RFCOMM Client**
- Connects to a Bluetooth RFCOMM server
- Can search for nearby Bluetooth devices
- Sends data over Bluetooth Serial
- **Dependencies:** `pybluez`
- **Usage:**
  ```bash
  python3 rfcomm-client.py [bluetooth_address]
  ```

### `serialBT.py`
**Serial Bluetooth Helper**
- Utility for serial Bluetooth communication
- **Dependencies:** `pybluez`

### `eog.py`
**EOG Data Processing**
- Processes EOG (Electrooculography) sensor data
- Works with `eog_cleaned2.csv` in `data/` folder
- **Dependencies:** `pandas`, `matplotlib`

### `bothTxRx.py`
**Placeholder**
- Currently empty, reserved for future BLE bidirectional script

## Setup

### Install Dependencies
```bash
pip3 install -r requirements.txt
```

### Install MQTT Broker (Mosquitto)
**Raspberry Pi / Debian / Ubuntu:**
```bash
sudo apt-get update
sudo apt-get install mosquitto mosquitto-clients
```

**macOS:**
```bash
brew install mosquitto
```

### Start MQTT Broker
```bash
mosquitto -d  # Run as daemon
```

Or run in foreground with verbose output:
```bash
mosquitto -v
```

## Testing MQTT

### Subscribe to a topic
```bash
mosquitto_sub -d -t testing
```

### Publish to a topic
```bash
mosquitto_pub -d -t testing -m "Hello from Raspberry Pi!"
```

## Bluetooth Notes

- Bluetooth Classic (RFCOMM) requires a Bluetooth adapter
- ESP32 supports both BLE and Bluetooth Classic
- ESP8266 does not have Bluetooth capabilities
- For BLE on ESP32, consider using `bleak` library (Python) instead of PyBluez

## Common Issues

**MQTT Connection Refused:**
- Check that mosquitto is running: `sudo systemctl status mosquitto`
- Verify firewall allows port 1883
- Ensure ESP device has correct broker IP

**Bluetooth Pairing:**
- Some devices require pairing before RFCOMM connection
- Use system Bluetooth settings to pair first
- Check device visibility settings

## Running at Startup (Raspberry Pi)

To auto-start MQTT subscriber on boot:
```bash
sudo systemctl enable mosquitto
# Add python3 /path/to/server.py to /etc/rc.local
```
