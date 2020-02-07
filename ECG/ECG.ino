#include <ESP8266WiFi.h>

#include <FirebaseArduino.h>


#define FIREBASE_HOST "https://heart-sensor-dd22c.firebaseio.com/"  
#define FIREBASE_AUTH "OPOWcKbzyxTWU4qqXbrvQZSkSeqGyOSgKjfh7xtU"  
#define WIFI_SSID "Anirudh Ramdas"  
#define WIFI_PASSWORD "masteranirudh"  
  
void setup()
{
  pinMode(D7,INPUT);
  pinMode(D8,INPUT);
  pinMode(A0,INPUT);
  Serial.begin(112500);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
  Serial.print("connecting");  
  while (WiFi.status() != WL_CONNECTED) {  
    Serial.print(".");  
    delay(500);  
  }  
  Serial.println();  
  Serial.print("connected: ");  
  Serial.println(WiFi.localIP());  
    
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  


}

void loop() {

  int data = analogRead(A0);
  Serial.println(data);
  delay(50);

   Firebase.setFloat("data", data);  
  // handle error  
  if (Firebase.failed()) {  
      Serial.print("setting /number failed:");  
      Serial.println(Firebase.error());    
      return;  
  }
  
}
