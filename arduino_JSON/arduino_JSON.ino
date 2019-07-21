#include <Arduino_JSON.h>

void setup() {
  const size_t capacity = JSON_OBJECT_SIZE(2) + 20;
  DynamicJsonBuffer jsonBuffer(capacity);
  Serial.begin(9600);
    
}

void loop() {
  while(Serial.available() == 0){}
  
  const char* json = Serial.read();
  JsonObject& root = jsonBuffer.parseObject(json);

  int x = root["x"]; // x-coordinate
  int y = root["y"]; // y-coordinate
  Serial.println(x);
  Serial.println(y);
}

//"{\"x\":12,\"y\":10}"
