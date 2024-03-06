int potentiometerReader = A5;
int potentiometerValue;
int waitingTime = 100;
int ledPin1 = 3;
int ledPin2 = 6;
int brightness1;
int brightness2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potentiometerReader, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potentiometerValue = analogRead(potentiometerReader);
  brightness1 = map(potentiometerValue, 0, 1023, 0, 255);
  Serial.print("Brightness 1: ");
  Serial.println(brightness1);
  analogWrite(ledPin1, brightness1);

  brightness2 = map(potentiometerValue, 0, 1023, 255, 0);
   Serial.print("Brightness 2: ");
  Serial.println(brightness2);
  analogWrite(ledPin2, brightness2);

  delay(waitingTime);
}
