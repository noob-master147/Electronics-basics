#include<Servo.h>

Servo s1;
Servo s2;

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  s1.attach(8);
  s1.write(90);
  s2.attach(9);
  s2.write(90);

}

void loop() {
  int i=0;
  for(i=0;i<180;i++)
  {
    s1.write(i);
    s2.write(i);
    delay(3);
  }
  delay(2);

  for(i=180;i>0;i--)
  {
    s1.write(i);
    s2.write(i);
    delay(3); 
  }
  delay(2);

}
