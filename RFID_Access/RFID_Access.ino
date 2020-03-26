#include "SPI.h" // SPI library
#include "MFRC522.h" // RFID library (https://github.com/miguelbalboa/rfid)
const int pinRST = 9;
const int pinSDA = 10;
MFRC522 mfrc522(pinSDA, pinRST); // Set up mfrc522 on the Arduino
void setup() {
  SPI.begin(); // open SPI connection
  mfrc522.PCD_Init(); // Initialize Proximity Coupling Device (PCD)
  Serial.begin(9600); // open serial connection
}
void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) { 
    if(mfrc522.PICC_ReadCardSerial()) {
      for (byte i = 0; i < 4; i++) { 
        Serial.print(mfrc522.uid.uidByte[i], HEX);
      }
      Serial.println();
      delay(2000);
    }
  }
}
