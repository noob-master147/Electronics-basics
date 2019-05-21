
byte state = LOW;

void setup() {
  pinMode(13, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), link,CHANGE);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13, state);
  Serial.println(state);
}

void link() {
  state = !state;
}
