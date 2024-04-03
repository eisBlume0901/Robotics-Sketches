int triggerPin = 2;
int triggerPulse = 10;
int echoPin = A0;
int pulseDelay = 50;

int redLED = 4;
int greenLED = 7;
int yellowLED = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sendUltrasonicWaves();
  digitalWrite(triggerPin, LOW);
  int travelTime = pulseIn(echoPin, HIGH);
  float distance = travelTime / 58;
  Serial.println(distance);
  delay(pulseDelay);

  if (distance < 1.5) switchLEDs(1, 0, 0);
  if (distance > 1.5 && distance < 2.5) switchLEDs(0, 1, 0);
  if (distance > 2.5) switchLEDs(0, 0, 1);
}

void sendUltrasonicWaves() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(triggerPulse);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(triggerPulse);
}

void switchLEDs(int redLEDState, int greenLEDState, int yellowLEDState) {
  digitalWrite(redLED, redLEDState);
  delay(25);
  digitalWrite(greenLED, greenLEDState);
  delay(25);
  digitalWrite(yellowLED, yellowLEDState);
  delay(25);

}
