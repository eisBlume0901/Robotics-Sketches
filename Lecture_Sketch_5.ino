int triggerPin = 2;
int echoPin = A0;
int triggerPulse = 10;
int triggerDelays = 50;

int ledPin = 4;
int blinkTime = 100;

int buzzPin = 7;
int buzzTime = 2500;

#include <Servo.h>
Servo servo;
int servoPin = 9;
int servoDelays = 1;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);

  servo.attach(servoPin);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sendUltrasonicWaves();
  digitalWrite(triggerPin, LOW); // Have to be declared here not inside a function
  
  float travelTime = pulseIn(echoPin, HIGH);
  float distance = travelTime / 58.;
  Serial.println(distance);
  delay(triggerDelays);

  if (distance < 10.) {
    playBuzzer();
    blinkLED();
  }
  else 
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzPin, LOW);
    moveServoArm(angle);
    angle+=10;
  }
  
}

void moveServoArm(int angle) {

  int modAngle = angle % 360;
  int desiredAngle = 0;
  if (modAngle > 180) {
    desiredAngle = 360 - modAngle;
  }
  else 
  {
    desiredAngle = modAngle;
  }
  servo.write(desiredAngle);
}
void sendUltrasonicWaves() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(triggerPulse);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(triggerPulse);

}
void blinkLED() {
  digitalWrite(ledPin, HIGH);
  delay(blinkTime);
  digitalWrite(ledPin, LOW);
  delay(blinkTime);
}

void playBuzzer()  {
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(buzzTime);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(buzzTime);
}


