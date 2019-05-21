int time;                     //keeps track of time for 50 days
int prev = 0;                 //kepps track of time after reset
void setup() {
  pinMode(10,OUTPUT);         //Connected to Reset pin
  pinMode(2,INPUT);           //Input from External trigger
  Serial.begin(9600);
}
void loop() {
  
  
  time = millis()/1000;
  int state = digitalRead(2);
  digitalWrite(10, LOW);
  if(state)                   // if button is true then reset
  {
    digitalWrite(10, HIGH);   // Set Reset pin to LOw to Restart the Arduino
    delay(100);
    digitalWrite(10, LOW);    // Return back the reset to High
  }
  
  
  if(prev != time)
  {
    prev+=1;
    Serial.print(state);
    Serial.print(" ");
    Serial.println(prev);
  }
  if(prev>=1000)
  {
    Serial.println("TIME UP");
    delay(5000);
    Serial.println("RESET TIME");
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
    
  }
  

}
