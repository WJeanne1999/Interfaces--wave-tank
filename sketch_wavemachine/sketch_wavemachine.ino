#include <ArduinoJson.h>
#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(9); // Attach servo to pin 9
}

void loop() {
  if (Serial.available()) {
    String jsonStr = Serial.readStringUntil('\n'); 
    StaticJsonDocument<1024> doc; 
    DeserializationError error = deserializeJson(doc, jsonStr); 

    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
    }

    JsonArray waveData = doc["wave_data"].as<JsonArray>(); 

    for (JsonObject wave : waveData) {
      float waveHeight = wave["wave_height"]; 
      int servoPos = map(waveHeight, 1.7, 5.04, 0, 180); 

      
      if (servoPos >= 0 && servoPos <= 180) {
        myServo.write(servoPos); 
        Serial.println("Servo position set to: " + String(servoPos));
      } else {
        Serial.println("Invalid servo position!");
      }

      delay(3000); 
    }
  }
}

