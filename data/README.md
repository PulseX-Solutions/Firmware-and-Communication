# Data

Datasets, CSV files, and data analysis scripts.

## Contents

### `dataset/`
**Sensor Data Collection**
- `Book1.csv` - Dataset (content TBD)
- `voltage_data.txt` - Raw voltage readings
- `vd.txt` - Additional voltage data
- `plot.py` - Plotting script for data visualization

### `eog_cleaned2.csv`
**EOG (Electrooculography) Data**
- Cleaned EOG sensor readings
- Used by `host/eog.py` for analysis

## Using the Plotting Script

```bash
cd data/dataset
python3 plot.py
```

**Dependencies:** `matplotlib`, `pandas`

Install with:
```bash
pip3 install matplotlib pandas
```

## Data Collection Notes

Data appears to be collected from:
- ESP32/ESP8266 sensors via MQTT or Serial
- EOG (eye movement) sensors
- Voltage/analog sensors

## Adding New Data

When adding new datasets:
1. Place CSV files in `data/` or `data/dataset/`
2. Add a brief description in this README
3. Include any analysis scripts alongside the data
4. Document column headers and units
5. Note the source device/sensor

## Analysis

For EOG analysis, see:
```bash
python3 host/eog.py
```

This processes the cleaned EOG data from `data/eog_cleaned2.csv`.
