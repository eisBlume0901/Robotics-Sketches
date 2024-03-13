#include <Servo.h>

# define servoPin 9
Servo servo; 
# define ledPin 11
# define potentiometerReader A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(potentiometerReader);
  int angle = map(reading, 0, 1023, 0, 180);
  servo.write(angle);
  
  int brightness = map(servo.read(), 0, 180, 255, 0);
  analogWrite(ledPin, brightness);

}

 
