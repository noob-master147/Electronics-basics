#include <Servo.h>
#include <Wire.h>
#include "SPI.h"
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP280.h"

Adafruit_BMP280 bmp;
Servo servo;
int altimeter;
int initAlti ;
int N = 10;

void setup()
{
    servo.attach(7);
    bmp.begin();
    Serial.begin(9600);
    servo.write(180);
    initAlti = bmp.readAltitude(1039.00);
}

void loop()
{
    altimeter = bmp.readAltitude(1039.00);
    Serial.print("Pressure: ");
    Serial.print(pressure);
    delay(200);
    if(altimeter - initAlti > 60)
    {
        servo.write(0);
    }
}


