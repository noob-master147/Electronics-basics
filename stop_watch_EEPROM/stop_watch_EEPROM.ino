

#include <EEPROM.h>

int prev = EEPROM.read(0);     
void setup() {
  Serial.begin(115200);
  EEPROM.begin(512); 
  
}
void loop() {
  
  
  
  
  while(EEPROM.read(0) != 1000)
  {
    prev+=1;
    EEPROM.write(0, prev);
    EEPROM.commit();
    delay(996);
    Serial.println(EEPROM.read(0));
  }
  if(prev==1000)
  {
    Serial.println("TIME UP");
    delay(5000);
    EEPROM.write(0, 0);
    
  }
  

}
