#!/bin/bash
# Quick setup script for host environment

echo "Installing Python dependencies..."
pip3 install -r requirements.txt

echo ""
echo "Checking for mosquitto MQTT broker..."
if command -v mosquitto &> /dev/null; then
    echo "✓ mosquitto is installed"
else
    echo "✗ mosquitto not found. Install with:"
    echo "  sudo apt-get install mosquitto mosquitto-clients  # Debian/Ubuntu/Raspberry Pi"
    echo "  brew install mosquitto  # macOS"
fi

echo ""
echo "Setup complete! You can now:"
echo "  1. Start MQTT broker: mosquitto -d"
echo "  2. Run MQTT subscriber: python3 host/server.py"
echo "  3. Run Bluetooth RFCOMM server: python3 host/rfcomm-server.py"
