int redLed = D1;
int greenLed = D2;
int buzzer = D8;
int smoke = A0;
int motor = D6;
int power = D3;
int digital = D5;
// Your threshold value for smoke
int sensorThres = 600;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(power, OUTPUT);
  pinMode(digital, OUTPUT);
  pinMode(smoke, INPUT);
  Serial.begin(115200);
}

void loop() {
  int Sensor = analogRead(smoke);
  int DSensor = digitalRead(digital);
  Serial.println(Sensor);
  Serial.println(DSensor);
  Serial.println();
  
  // Checks if it has reached the threshold value
  if (Sensor >= sensorThres || DSensor == 1)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(motor, HIGH);
    digitalWrite(power, HIGH);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(motor, LOW);
    digitalWrite(power, LOW);
    noTone(buzzer);
  }
  delay(100);
}
