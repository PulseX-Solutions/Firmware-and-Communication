Host scripts (Raspberry Pi / PC)

Detected host scripts at repository root:
- `server.py` — MQTT client subscribing to `/esp8266/temperature` and `/esp8266/humidity` (uses `paho-mqtt`). Entry point: `main()`
- `rfcomm-server.py` — PyBluez RFCOMM server example (accepts incoming Bluetooth RFCOMM connections)
- `rfcomm-client.py` — PyBluez RFCOMM client example
- `serialBT.py` — (likely helper around serial Bluetooth; inspect before running)
- `bothTxRx.py` — currently empty (placeholder)

Dependencies & install notes

- Python packages: `paho-mqtt`, `pybluez` (if using RFCOMM). Install with `pip install paho-mqtt pybluez`.
- For MQTT broker, the README recommends `mosquitto` (install via apt on Raspberry Pi).

How to run the MQTT host

1. Start a broker (on the Pi): `mosquitto -d`
2. Run `python3 server.py` — it will connect to `localhost:1883` and subscribe to topics.

Bluetooth (RFCOMM) notes

- `rfcomm-server.py` and `rfcomm-client.py` are examples intended for use with a Bluetooth adapter and PyBluez. They are not specific to ESP32 BLE (ESP32 uses BLE or Classic BT depending on the sketch).

I can:
- Move these scripts to `host/` and add small wrapper scripts to launch them, or
- Keep them at repo root and add more detailed usage notes. Let me know which you prefer.