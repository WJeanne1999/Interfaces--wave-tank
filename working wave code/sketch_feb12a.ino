/
#include <Servo.h> 
Servo servo; 

int pos = 0; 
int back = 0; 
int forward = 90; 

void setup() {
  Serial.begin(9600); 
  
  servo.attach(9);
  servo.write(back); 
}


void loop() {
 for (pos = back; pos <= forward; pos += 1) {
  servo.write(pos);
  delay(2); 
  Serial.print(pos);
 }
 
 for (pos = forward; pos >= back; pos -=1) {
  servo.write(pos);
  delay(2); 
  Serial.print(pos);
 }



}

