int buttonPin = 2;
int ledPin = 4;
int buzzPin = 8;
int buttonValue;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  buttonValue = digitalRead(buttonPin);
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzPin, LOW);
  
  Serial.print("Button state ");
  Serial.println(buttonValue);

  while (buttonValue == 0) {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzPin, HIGH);
    buttonValue = digitalRead(buttonPin);
  }
  
}
