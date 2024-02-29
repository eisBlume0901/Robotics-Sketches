int ledPin = 2;
int buttonPin = 4;
int buttonReader;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}


void loop() {

  buttonReader = digitalRead(buttonPin);
  digitalWrite(ledPin, LOW);
  Serial.print("Button state ");
  Serial.println(buttonReader);

  while (buttonReader == 0) {
    digitalWrite(ledPin, HIGH);
    buttonReader = digitalRead(buttonPin);
  }
}
