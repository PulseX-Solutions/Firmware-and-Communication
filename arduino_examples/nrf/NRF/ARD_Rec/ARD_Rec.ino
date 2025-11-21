#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001"; // address for the NRF24L01 module

void setup() {
  Serial.begin(9600);
  if (!radio.begin()) {
    Serial.println("Radio hardware not responding");
  }
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH); // Try a lower power level
  radio.startListening();
}

void loop() {
  if (radio.available()) { // check if data is available
    char text[32] = ""; // buffer to store the incoming data
    radio.read(&text, sizeof(text)); // read the data
    Serial.println("Received: ");
    Serial.println(text); // print the data to the serial monitor
  } else {
    Serial.println("No data received");
  }
  delay(1000); // small delay to prevent flooding the serial output
}
