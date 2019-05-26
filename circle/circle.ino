#include<Servo.h>

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

  s1.write(30);

}


void onetwo()
{
  for(int i=0;i<=120;i+=2)
  {
    s1.write(30+i);
    s2.write(150-i);
    delay(5); 
  }
  
}

void twothree()
{
  for(int i=0;i<=120;i+=2)
  {
    s2.write(30+i);
    s3.write(150-i);
    delay(5); 
  }
  

}

void threeone()
{
  for(int i=0;i<=120;i+=2)
  {
    s3.write(30+i);
    s1.write(150-i);
    delay(5); 
  }
  

}



void loop() {

  onetwo();
  twothree();
  threeone();
    

  
}













 
