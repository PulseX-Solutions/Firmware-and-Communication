#include <SPI.h>
#include <RF24.h>

// ce, csn pins
RF24 radio(9, 10);

void setup(void) {
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(0x76);
  radio.openWritingPipe(0xF0F0F0F0E1LL);

  const uint64_t pipe = 0xF0F0F0F0E1LL;
  radio.openReadingPipe(1,pipe);
  radio.enableDynamicPayloads();
  radio.powerUp();
}

void loop() {
  radio.startListening();
  Serial.println("Starting loop. Radio on");
  char receiveMessage[32] = {0};
  if (radio.available()) {
    Serial.println("Looks like they want a string!");
    radio.read(receiveMessage, sizeof(receiveMessage));
    Serial.println(receiveMessage);
    radio.stopListening();
    String stringMessage = "GETSTRING";
    if (stringMessage == receiveMessage) {
      const char text[] = "Hello World!";
      radio.write(text, sizeof(text));
      Serial.println("We sent our message.");
    }
  }

  delay(1000);
}