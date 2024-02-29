#define G3 196
#define GS3 208
#define A3 220
#define AS3 233
#define B3 247
#define C4 262
#define CS4 277
#define D4 294
#define DS4 311
#define E4 330
#define F4 349
#define FS4 370
#define G4 392
#define GS4 415
#define A4 440
#define AS4 466
#define B4 494
#define C5 523
#define CS5 554
#define D5 587
#define DS5 622
#define E5 659
#define F5 698
#define FS5 740
#define G5 784
#define GS5 831
#define A5 880
#define AS5 932
#define B5 988

int buzzPin = 8;

int ledPin1 = 2;
int ledPin2 = 4;
int ledPin3 = 6;

int blinkingTime = 250;

String userInput;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Please enter the word bahay to play the song Bahay Kubo");
  while (Serial.available() == 0) {
  }
  userInput = Serial.readString();
  userInput.trim();
  
  if (userInput == "bahay") {
    blinkLED();
    bahayKubo();
    blinkLED();
  }
}

void blinkLED() {
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  delay(blinkingTime);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  delay(blinkingTime);

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  delay(blinkingTime);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  delay(blinkingTime);

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  delay(blinkingTime);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  delay(blinkingTime);
}

// Code by <a href=https://github.com/Myrandde">Myrandde</a>
void bahayKubo() {
  int tempo = 2000;
  play(G4, tempo / 4);
 
  play(C5, tempo / 2);
  play(D5, tempo / 4);
 
  play(B4, tempo / 2);
  play(G4, tempo / 4);
 
  play(A4, tempo / 2);
  play(C5, tempo / 4);
 
  play(G4, tempo / 2);
  play(E4, tempo / 8);
  play(F4, tempo / 8);
 
  play(G4, tempo / 4);
  play(A4, tempo / 4);
  play(G4, tempo / 4);

  play(F4, tempo / 2);
  play(B4, tempo / 8);
  play(C5, tempo / 8);

  play(D5, tempo / 4);
  play(E5, tempo / 4);
  play(D5, tempo / 4);

  play(C5, tempo / 2);
  play(G4, tempo / 8);
  play(G4, tempo / 8);
 
  play(C5, tempo / 2);
  play(D5, tempo / 8);
  play(C5, tempo / 8);
 
  play(B4, tempo / 2);
  play(G4, tempo / 8);
  play(G4, tempo / 8);
 
  play(A4, tempo / 4);
  play(A4, tempo / 4);
  play(B4, tempo / 8);
  play(A4, tempo / 8);
 
  play(G4, tempo / 2);
  play(G4, tempo / 4);
 
  play(A4, tempo / 2);
  play(A4, tempo / 4);
 
  play(B4, tempo / 4 * 1.5);
  play(A4, tempo / 8);
  play(G4, tempo / 4);

  play(C5, tempo / 2);
  play(0, tempo);
}

void play(int note, int time)
{
  if (note == 0) {
    delay(time);
    noTone(buzzPin);
  } else {
    tone(buzzPin,note);
    delay(time);
    noTone(buzzPin);
  }
}
