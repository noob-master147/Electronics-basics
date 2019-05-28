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

//  s1.write(60);
//  s2.write(90);
//  s3.write(120);
}



void loop() {

  cycle2();
  cycle3();
  cycle4();
  cycle1();
  
}

void cycle1()
{
  for(int i=0; i<30; i++)
  {
    s1.write(90-i);
    s2.write(60+i);
    s3.write(90+i);
    delay(5);
  }
}

void cycle2()
{
  for(int i=0; i<30; i++)
  {
    s1.write(60+i);
    s2.write(90+i);
    s3.write(120-i);
    delay(5);
  }
}

void cycle3()
{
  for(int i=0; i<30; i++)
  {
    s1.write(90+i);
    s2.write(120-i);
    s3.write(90-i);
    delay(5);
  }
}

void cycle4()
{
  for(int i=0; i<30; i++)
  {
    s1.write(120-i);
    s2.write(90-i);
    s3.write(60+1);
    delay(5);
  }
}












 
