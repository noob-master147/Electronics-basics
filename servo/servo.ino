#include<Servo.h>

Servo servo;

int servo_pin = 4;

void setup() {
  pinMode(servo_pin,OUTPUT);
  servo.write(90);

}

void loop() {
  for(int i = 0;i<180; i+=5)
  {
    servo.write(i);
    delay(10);
  }

  for(int i = 180;i>0; i-=5)
  {
    servo.write(i);
    delay(10);
  }

}
