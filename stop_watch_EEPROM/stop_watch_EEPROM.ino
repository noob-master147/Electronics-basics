#include <EEPROM.h>
 
#define SAMPLE_TIME 1000  //The time between each EEPROM write function call in ms
 

int address = 0;      //EEPROM address counter
int prev = 0;
unsigned long timer;
 


void writeTemp();
 
void setup(){
  Serial.begin(9600);     //start the serial connection as always
  timer = millis()/1000;         //millis() returns the time since program start in ms
  pinMode(2,INPUT);
}
 
void loop(){
  if(millis()/1000-timer > SAMPLE_TIME)  //check if it's time to do a temp sensor sample
  {
    Serial.println("TIME UP!");
    
  }
 
}
 

 

 
void writeTemp()
{
  
   
  EEPROM.update(address, timer);         //write value to current address counter address
 
  Serial.print("Sensor value stored at address ");
  Serial.println(address);
   
  
}



/*  NOTES
 *  An EEPROM write takes 3.3 ms to complete.
 * The EEPROM memory has a specified life of 100,000 write/erase cycles, 
 * so you may need to be careful about how often you write to it.
 * so using update() function instead of write() 
 * can save cycles if the written data does not change often
 */
