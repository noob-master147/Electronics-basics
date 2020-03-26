const int lamp = 6;
boolean x = true;

void setup() {
  Serial.begin(9600);
  pinMode(lamp , OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  int c = analogRead(A0) - 90;
  Serial.print("Light Intensity: ");
  Serial.println(c);

}
// Gives a Light Intensity range from 0 to 50 
