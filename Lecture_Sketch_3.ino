int buttonPin = 2;
int ledPin1 = 4;
int ledPin2 = 7;
int firstInterval = 500; // 1000 milliseconds = 1 second
int secondInterval = 100;
int buttonState = 1;
int buttonValue;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {

  buttonValue = digitalRead(buttonPin);
  Serial.println(buttonValue);

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  delay(firstInterval);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  delay(firstInterval);

  while (buttonValue == 0) {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      delay(secondInterval);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      delay(secondInterval);
      buttonValue = digitalRead(buttonPin);
    }
 
}
