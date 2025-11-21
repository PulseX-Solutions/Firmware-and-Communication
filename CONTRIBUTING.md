# Contributing Guidelines

## Repository Organization

This repository is organized by component type:

### Adding New Firmware

- **ESP32 sketches** → `firmware/esp32/[project_name]/`
- **ESP8266 sketches** → `firmware/esp8266/[project_name]/`

Each sketch should include:
1. A descriptive folder name
2. A `.ino` file with the same name as the folder
3. Header comment block with:
   - Purpose/description
   - Target board (ESP32/ESP8266)
   - Required libraries
   - Pin assignments
   - Configuration notes (WiFi SSID, broker IP, etc.)

### Adding New Host Scripts

- **Python scripts** → `host/[script_name].py`

Each script should include:
1. Docstring at the top describing purpose
2. Dependencies listed in comments
3. Usage example in comments or separate README

### Adding Examples or Legacy Code

- **Arduino/NRF examples** → `arduino_examples/`
- **Experimental/old code** → `arduino_examples/legacy/`

### Adding Data or Analysis

- **Datasets, CSVs, plots** → `data/`

## Code Style

### Arduino/ESP Sketches
- Use meaningful variable names
- Add comments for non-obvious logic
- Keep WiFi credentials as constants at the top
- Use `Serial.println()` for debugging output

### Python Scripts
- Follow PEP 8 style guidelines
- Use Python 3 syntax
- Add type hints where helpful
- Include error handling for network operations

## Testing

Before submitting:
1. Test firmware on actual hardware
2. Verify host scripts connect successfully
3. Update documentation if adding new features
4. Check that `requirements.txt` includes any new dependencies

## Documentation

When adding significant features:
1. Update relevant files in `docs/`
2. Add usage examples to README.md
3. Document any hardware requirements
4. Include wiring diagrams if applicable

## Questions?

See existing examples in the repository for reference.
