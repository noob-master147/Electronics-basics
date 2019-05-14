float av1=A3;       //x-axis
float av2=A4;       //y-axis
float av3=A2;       //z-axis
int led1=2;//front led
int led2=3;//back led
int led3=4;//left led
int led4=5;//right led
float a,b,c,x,y,z;
void setup() {
 // put your setup code here, to run once:
 //Set the LED pins to output mode
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT);

 a=analogRead(av1)/10; // To store the INITIAL (REFERENCE) VALUES
 b=analogRead(av2/10);
 c=analogRead(av3)/10;

 Serial.begin(9600);
}
void loop() {
x=analogRead(av1)/10;
y=analogRead(av2)/10;
z=analogRead(av3)/10;
Serial.println("------");
Serial.print("X value: "); 
Serial.println(x-a);
Serial.print("Y value  ");
Serial.println(y-b);
Serial.print("Z value: "); 
Serial.println(z-c);

delay(300);

 //Initially set all the ledpins to LOW
 digitalWrite(led1,LOW);
 digitalWrite(led2,LOW);
 digitalWrite(led3,LOW);
 digitalWrite(led4,LOW);
 //for left led
 if(x-a>30)
 {
 digitalWrite(led3,HIGH);
 Serial.println("LEFT");
 }
//for right led
 if(a-x>30)
 {
 digitalWrite(led4,HIGH);
 Serial.println("RIGHT");
 }
 //for forward led
if(b-y>30)
 {
 digitalWrite(led1,HIGH);
 Serial.println("FORWARD");
 }
//for back led
 if(y-b>30)
 {
 digitalWrite(led2,HIGH);
 Serial.println("BACK");
 }
 delay(100);
}
