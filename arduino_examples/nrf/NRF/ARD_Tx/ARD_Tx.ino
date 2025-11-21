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
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH); // Try a lower power level
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello World"; // message to be transmitted
  bool success = radio.write(&text, sizeof(text));
  if (success) {
    Serial.println("Sent successfully");
  } else {
    Serial.println("Sending failed");
  }
  delay(1500); // increased delay to 1.5 seconds
}
