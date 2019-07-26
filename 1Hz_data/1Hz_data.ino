const int trigPin = 2;
const int echoPin = 3;
int Analog_in = A0;

int period = 50;
int distance = 0;
int time;
void setup() {
  Serial.begin(9600);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Analog_in,INPUT);
  time = millis();
}


void loop() {
  if (millis() > time+period)
  {
    time = millis();
    distance = get_dist();
    Serial.println(distance);
       
  }
}


int get_dist()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  int distance = constrain(duration*0.034/2, 2, 30);
  
  delay(1);        
  return(distance);
}
