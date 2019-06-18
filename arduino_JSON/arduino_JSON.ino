#include <Arduino_JSON.h>

void setup() {
  const size_t capacity = JSON_OBJECT_SIZE(2) + 20;
  DynamicJsonBuffer jsonBuffer(capacity);

  const char* json = "{\"x\":12,\"y\":10}";

  
}

void loop() {
  const char* json = "{\"x\":12,\"y\":10}";
  JsonObject& root = jsonBuffer.parseObject(json);

  int x = root["x"]; // x-coordinate
  int y = root["y"]; // y-coordinate
}
