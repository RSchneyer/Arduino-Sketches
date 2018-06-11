#include <Servo.h>
Servo myServo;


void setup() {
  myServo.attach(11);
  Serial.begin(9600);
}

void loop() {
  myServo.write(0);
  Serial.println("0");
  delay(2000);
  myServo.write(45);
  Serial.println("45");
  delay(2000);
  myServo.write(90);
  Serial.println("90");
  delay(500);
  myServo.write(95);
  Serial.println("95");
  delay(2000);
  myServo.write(135);
  Serial.println("135");
  delay(2000);
  myServo.write(180);
  Serial.println("180");
  delay(2000);
}
