Repository overview

This repo contains example firmware for ESP8266 / ESP32 and host-side scripts (Python) used to receive sensor data via MQTT, Bluetooth RFCOMM or BLE. The original layout mixes firmware sketches (.ino), host scripts (.py) and data/plots.

Goal

- Organize the code into logical components (firmware, host, examples, datasets).
- Document how each component is used, dependencies and entry points.
- Provide a minimal guide for running the Raspberry Pi host and flashing ESP devices.

Suggested high-level structure (non-destructive — files are currently in place):

- `firmware/`  : ESP32/ESP8266 sketches and Arduino-compatible examples (BLE, MQTT, Serial)
- `host/`      : Raspberry Pi / PC host scripts (MQTT subscribers, RFCOMM server/client, serial helpers)
- `arduino/`   : Misc Arduino / NRF examples (if not ESP)
- `dataset/`   : CSV data, plotting code and analysis scripts
- `docs/`      : This documentation and per-component READMEs

What I created

- `docs/README.md` (this file)
- `docs/FIRMWARE.md` (firmware summary)
- `docs/HOST.md` (host scripts summary)
- `docs/ARDUINO.md` (Arduino/NRF examples summary)
- `docs/DATASET.md` (dataset notes)

Next steps (I can do these for you):
- Move files into the proposed folders and update paths in scripts, or
- Leave files in place and add clearer READMEs + a CONTRIBUTING note about where to put new sketches.

Tell me whether you want me to actually move files into the new structure, or only add documentation.