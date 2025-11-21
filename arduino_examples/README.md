# Arduino Examples

Legacy Arduino and NRF24L01 radio communication examples.

## NRF Examples (`nrf/NRF/`)

Examples for nRF24L01+ 2.4GHz wireless modules:

### `ARD_Rec/`
**Arduino Receiver**
- Receives data from nRF24L01 transmitter
- **Target:** Arduino (Uno, Nano, Mega, etc.)
- **Libraries:** RF24

### `ARD_Tx/`
**Arduino Transmitter**
- Transmits data via nRF24L01
- **Target:** Arduino
- **Libraries:** RF24

### `send/`
**Simple Send Example**
- Basic transmission test
- **Target:** Arduino

### `sendreceive/`
**Bidirectional Communication**
- Two-way radio communication example
- **Target:** Arduino

## Legacy Examples (`legacy/day1/`)

Early development and test sketches:

### `BLE_server/`
**ESP32 BLE Server**
- Basic BLE server implementation
- **Target:** ESP32

### `BT_sender/`
**Bluetooth Sender**
- Classic Bluetooth transmission
- **Target:** ESP32

### `Btcom2/`
**Bluetooth Serial Communication**
- Serial port over Bluetooth
- Includes MAC address printing
- **Target:** ESP32
- **Device name:** ESP32test

### `Blink_intoCOMBT/`
**Blink with Bluetooth**
- LED blink controlled via Bluetooth
- **Target:** ESP32

### `dht_sensor/`
**DHT Sensor Reading**
- Temperature and humidity sensor example
- **Target:** ESP32/ESP8266
- **Libraries:** DHT sensor library

### `esp32_BT/`
**ESP32 Bluetooth Example**
- Basic Bluetooth functionality
- **Target:** ESP32

## Notes

These examples are kept for reference and learning purposes. For production use:
- Refer to organized examples in `firmware/esp32/` and `firmware/esp8266/`
- Check `docs/` for detailed protocol documentation
- Use examples in `host/` for corresponding host-side code

## Hardware Requirements

### For NRF24L01
- Arduino board (Uno, Nano, Mega, etc.)
- nRF24L01+ module
- Wiring: CE → D9, CSN → D10, MOSI/MISO/SCK → SPI pins

### For ESP32 Examples
- ESP32 development board
- USB cable
- Sensors as needed (DHT11/22, etc.)
