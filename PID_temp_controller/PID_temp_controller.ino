double sensed_output, setpoint, control_signal;
double kp=4, ki, kd;
int T =50;
unsigned long last_time;
double total_error, last_error;

int sensorPin =A1;
int sensorVoltage;
double temperature;
int OutputPin = 4;

void setup() {
  pinMode(OutputPin, OUTPUT);

}



void loop() {
  sensorVoltage = analogRead(sensorPin);
  temperature = (sensorVoltage*500)/1023;
  sensed_output =  temperature;
  setpoint = 440;
  Serial.println(temperature);
  PID_Control();

  analogWrite(OutputPin, control_signal);

}

void PID_Control()
{

  unsigned long current_time =millis();
  int delta_time = current_time - last_time;
  
  if(delta_time>T)
  {

    double error = setpoint - sensed_output;
    total_error +=error;
    if(total_error>=255) total_error = 255;
    else if(total_error<=0) total_error = 0;
    double delta_error = error -last_error;

    control_signal = kp*error +ki*T*total_error +(kd/T)*delta_error;
    if(total_error>=255) total_error = 255;
    else if(total_error<=0) total_error = 0;
    
    last_error = error;
    last_time = current_time;
  }
}
