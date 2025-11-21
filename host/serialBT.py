import serial
import json

x = serial.Serial('/dev/rfcomm0', 115200)

while True:
    try:
        esp32_data = x.readline().decode('ascii')
        if esp32_data.strip():  # Check if the received data is not empty
            data_dict = json.loads(esp32_data)  # Parse the JSON data
            print("Received data:", data_dict)
    except json.JSONDecodeError:
        print("Invalid JSON data received:", esp32_data)
    except Exception as e:
        print("An error occurred:", e)
