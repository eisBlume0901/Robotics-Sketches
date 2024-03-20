#include <Servo.h>
Servo servo;
int servoPin = 9;

int buzzPin = 10;
#define NOTE_C4  262
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_C5  523

int buttonPin = 8; // digital pin
int buttonState;

int ledPin1 = 2; // digital pin
int ledPin2 = 4; // digital pin
int ledPin3 = 7; // digital pin

void setup() {
  // put your setup code here, to run once:


  servo.attach(servoPin);
  servo.write(0);

  pinMode(buzzPin, OUTPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int buttonStatus = digitalRead(buttonPin);

  if (buttonStatus == 0) {
    Serial.begin(9600);
    askUserColor();
    playSong();
    moveServo();
  }
  else {}
}

void askUserColor() {

    Serial.println("Choose what color you want the LED to blink");
    Serial.println("1. Red");
    Serial.println("2. Yellow");
    Serial.println("3. Green");
    
    while (Serial.available() == 0) {}
  
    int color = Serial.parseInt();

    if (color == 1) { blinkLED(ledPin1); Serial.end(); }
    if (color == 2) { blinkLED(ledPin2); Serial.end(); }
    if (color == 3) { blinkLED(ledPin3); Serial.end(); }
    
}

void blinkLED(int ledPin) {
  int blinkInterval = 450;
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(blinkInterval);
    digitalWrite(ledPin, LOW);
    delay(blinkInterval);
  }
}
void playSong() {
  int duration = 2500;
  int  melody[] = {
     NOTE_C4, 
     NOTE_F4, NOTE_F4, NOTE_F4, NOTE_A4,
     NOTE_C5, NOTE_C5, NOTE_A4, NOTE_F4
  };

  int denomination[] = {
    8,
    4, 8, 4, 8,
    8, 8, 8, 4
  };

  int melodySize = sizeof(melody) / sizeof(melody[0]);
  for (int i = 0; i < 3; i++) {
    for (int i = 0; i < melodySize; i++) {
      int noteDuration = duration / denomination[i];
      tone(buzzPin, melody[i], noteDuration);
      delay(noteDuration);
      noTone(buzzPin);
    }
  }
}

void moveServo() {
  int servoInterval = 500;

  for (int i = 0; i < 2; i++) {
    servo.write(0);
    delay(servoInterval);
    servo.write(45);
    delay(servoInterval);
    servo.write(90);
    delay(servoInterval);
    servo.write(135);
    delay(servoInterval);
    servo.write(180);
    delay(servoInterval);
  }
}
