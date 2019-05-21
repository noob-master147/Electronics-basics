#include<Servo.h>

Servo s1;
Servo s2;
Servo s3;

void setup() {
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  s1.attach(8);
  s1.write(90);
  s2.attach(9);
  s2.write(90);
  s3.attach(10);
  s3.write(90);
  
  delay(2000);
  s1.write(180);
  delay(2000);
  s2.write(180);
  delay(2000);
  s3.write(180);
  delay(2000);

  Serial.begin(9600);

}

void loop() {
  int a = analogRead(A5);
  int b = analogRead(A4);
  a = map(a,0,1023,90,180);
  b = map(b,0,1023,90,180);
  int c = ((a + b) % 180) + 90;
  for(int i=90; i<180; i++)
  {
    s1.write(i);
    s2.write(i);
    s3.write(i);
    delay(5);
    
  }

  for(int i=180; i>90; i--)
  {
    s1.write(i);
    s2.write(i);
    s3.write(i);
    delay(5);
    
  }
}
