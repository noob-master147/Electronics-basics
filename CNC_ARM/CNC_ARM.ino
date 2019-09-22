#include <Servo.h>

Servo claw;  // create servo object to control a servo
Servo servo0;
Servo servo1;
Servo servo2;

int potpin0 = A0;
int potpin1 = A1; 
int potpin2 = A2; 
int val0, val1, val2;    

void setup() {
  Serial.begin(9600);
  servo0.attach(5);
  servo1.attach(6);
  servo2.attach(7);
  claw.attach(11);  
       
}

void loop() {
  int i;
  val0 = analogRead(potpin0);            
  val1 = analogRead(potpin1);
  val2 = analogRead(potpin2);

  
  val0 = map(val0, 0, 1023, 30, 150);
  val1 = map(val1, 0, 1023, 30, 150);
  val2 = map(val2, 0, 1023, 30, 150);  
     
  claw.write(val0);
  //servo0.write(val0);                 
  //servo1.write(val1);                 
  //servo2.write(val2); 
              
  delay(15);   
  Serial.println(val0);
  Serial.println(val1);
  Serial.println(val2);

  for(i = 30;i<150; i++)
  {
    servo2.write(120-i);
    servo1.write(i);
    servo0.write(i);
    delay(15);
  }

    for(;i>30; i--)
  {
    servo2.write(120-i);
    servo1.write(i);
    servo0.write(i);
    delay(15);
  }
    
  
}
