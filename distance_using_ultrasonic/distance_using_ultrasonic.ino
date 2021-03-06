const int trigPin = 2;
const int echoPin = 3;

long duration;
int distance;


void setup() 
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}


void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= constrain(duration*0.034/2, 4, 30);
Serial.print("Distance: ");
Serial.println(distance);
}
