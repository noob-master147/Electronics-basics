
void setup() {

  Serial.begin(9600);
}

void loop() {
 
  int a = millis()/1000;
  Serial.println(a);
  
  while(a>=10)
  {
    int b = millis()/1000;
    Serial.println(b*a);
    
    while(b>10)
    {
      int c = millis()/1000;
      Serial.println(a*b*c);
    }
  
  }
  

}
