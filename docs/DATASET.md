Datasets and plotting

Files:
- `dataset/Book1.csv` — (unknown contents)
- `dataset/plot.py` — plotting helper
- `dataset/vd.txt`, `dataset/voltage_data.txt` — raw logs
- `eog_cleaned2.csv`, `eog.py` at repo root — EOG processing/analysis scripts

Notes

- `dataset/plot.py` should include a short README header describing required packages (e.g., `matplotlib`, `pandas`).
- Consider moving `eog.py` into `dataset/` for cohesion.

I can:
- Add `requirements.txt` listing Python packages detected (e.g., `paho-mqtt`, `matplotlib`, `pandas`, `pybluez`).
- Move `eog.py` into `dataset/` and update imports if you want.