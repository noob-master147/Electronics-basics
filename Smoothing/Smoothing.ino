const int numReadings = 5;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int readtotal = 0;                  // the running total
int readaverage = 0;                // the average

int Analog_in = A0;              //analogReference(EXTERNAL);

void setup() {
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  readtotal = readtotal - readings[readIndex];
  readings[readIndex] = analogRead(Analog_in);
  readtotal = readtotal + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  readaverage = readtotal / numReadings;
  Serial.println(readaverage);
  delay(1);        
}
