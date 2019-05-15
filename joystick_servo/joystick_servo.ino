
void setup() {
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int x=analogRead(A1);
  int y=analogRead(A2);

  int dx = map(x,0,1024,0,180);
  int dy = map(y,0,1024,0,180);
  Serial.println(dx);
  Serial.println(dy);

}
