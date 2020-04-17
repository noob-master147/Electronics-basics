int resetPin = 2;
int motor = 13;
unsigned long currentTime;
static unsigned long resetInterval = 86400000UL; // 24 H
static unsigned long readInterval =  43200000UL;     // 12 H

void setup()
{ 
  pinMode(motor, OUTPUT);
  pinMode(resetPin, OUTPUT);
  digitalWrite(motor, HIGH);
  digitalWrite(resetPin, HIGH);
  Serial.begin(9600);
}


void loop()
{
  static unsigned long ResetstartTime = 0;
  static unsigned long startTime = 0;
  currentTime = millis();

  // Read all the values here
  if (startTime == 0)
  {
    digitalWrite(motor, LOW);
    delay(1800000);
    digitalWrite(motor, HIGH);
    startTime = currentTime;
  }

  /* This checks for every 20 min and triggers to take
    input in the next iteration of the loop
  */
  if (currentTime - startTime >= readInterval) // Data Read Interval
  {
    startTime = 0;
  }

  //Code for Restarting the Micro Controller
  if (ResetstartTime == 0)
  {
    // Serial.println("Resetting");
    digitalWrite(resetPin, LOW); // Pull the Hardware RESET
    ResetstartTime = currentTime;
  }
  if (currentTime - ResetstartTime >= resetInterval) //20 Min
  {
    ResetstartTime = 0;
  }
}
