int time;
int prev = 0;
void setup() {
  pinMode(8,INPUT);
  Serial.begin(9600);
}
void loop() {
  //Serial.print("Time: ");
  time = millis()/1000;
  
  //Serial.println(time); //prints time since program started
  if(prev != time)
  {
    prev+=1;
    Serial.println(prev);
  }
}
