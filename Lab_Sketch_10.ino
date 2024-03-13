#include <Servo.h>
int servoPin = 9;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter angle ");
  while (Serial.available() == 0) {
    
  }
  int angle = Serial.parseInt();
  Serial.println(angle);
  int microseconds = map(angle, 0, 180, 600, 2400);
  servo.writeMicroseconds(microseconds);
}
