

#include <EEPROM.h>

int time;                     //keeps track of time for 50 days
int prev = 0;

void setup() {
  Serial.begin(9600);
  EEPROM.get(0, prev);     
}
void loop() {
  
  
  time = millis()/1000;
  EEPROM.update(0, prev);
  
  if(prev != time)
  {
    prev+=1;
    EEPROM.put(0, prev);
    delay(996);
    Serial.println(prev);
  }
  if(prev>=1000)
  {
    Serial.println("TIME UP");
    delay(5000);
    for (int i = 0 ; i < EEPROM.length() ; i++) 
    EEPROM.write(i, 0);
    
  }
  

}
