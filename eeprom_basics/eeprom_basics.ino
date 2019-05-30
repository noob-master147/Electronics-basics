#include<string>
#include<EEPROM.h>
  int a = 0;  
  int b = 0;
  int c = 0;
  int d = 0;
  int aa = 1;
  int ab = 2;
  int ac = 3;
  int ad = 4;


int num()
{
  int n =0;
  int p = EEPROM.read(ad);
  int q = EEPROM.read(ac);
  int r = EEPROM.read(ab);
  int s = EEPROM.read(aa);

  n=n*10 + s;
  n=n*10 + r;
  n=n*10 + q;
  n=n*10 + p;
  Serial.println(n);
  return n;

}

void setup() {
  
  Serial.begin(115200);
  EEPROM.begin(512);
  delay(2000);
  
  EEPROM.write(aa,a);
  EEPROM.write(ab,b);
  EEPROM.write(ac,c);
  EEPROM.write(ad,d);

}



void loop() {

  for(a=0;a<10;a++)
  {
    for(b=0;b<10;b++)
    {
      for(c=0;c<10;c++)
      {
        for(d=0;d<10;d++)
        {
            EEPROM.write(aa,a);
            EEPROM.write(ab,b);
            EEPROM.write(ac,c);
            EEPROM.write(ad,d);
            num();
            delay(200);
        }
      }
    }
  }

  
}
