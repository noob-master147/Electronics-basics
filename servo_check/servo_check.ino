#include<Servo.h>
#include<Filter.h>

Servo s1;
Servo s2;
Servo s3;

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  s1.attach(8);
  s1.write(90);
  s2.attach(9);
  s2.write(90);
  s3.attach(10);
  s3.write(90);
  delay(5000);

}

void loop() {
  int i=0;

  s1.write(30);
  s2.write(30);
  s3.write(30);
  delay(2000);
  
  s1.write(30);
  s2.write(30);
  s3.write(150);
  delay(2000);
  
  s1.write(30);
  s2.write(150);
  s3.write(150);  
  delay(2000);

  s1.write(150);
  s2.write(150);
  s3.write(150);
  delay(2000);
  
  

  for(i=150;i>30;i-=2)
  {
    s1.write(i);
    s2.write(i);
    s3.write(i);
    delay(5); 
  }
  delay(200);

  for(i=30;i<150;i+=2)
  {
    s1.write(i);
    s2.write(i);
    s3.write(i);
    delay(5);
  }
  delay(200);

}
