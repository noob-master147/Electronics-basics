#include<Servo.h>

Servo servo;

int servo_pin = 3;

void setup() {
  pinMode(servo_pin,OUTPUT);

}


void loop() {
  
  
  for(int i = 0; i<180; i+=2)
  {
    int pulse_high = map(i,0,180,1000,2000);
    write_angle(pulse_high);
    delay(5);
  }

  for(int i = 180; i>0; i-=2)
  {
    int pulse_high = map(i,0,180,1000,2000);
    write_angle(pulse_high);
    delay(5);
  }
  
}


void write_angle(int pulse){
  digitalWrite(3,HIGH);
  delayMicroseconds(pulse);
  digitalWrite(3,LOW);
  delayMicroseconds(2000 - pulse);
}
