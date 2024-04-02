int triggerPin = 2;
int echoPin = A0;
int triggerPulse = 10;
int pulseDelay = 50;

int greenLEDPin = 4;
int redLEDPin = 7;
int buzzPin = 8;
int buzzDelay = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // // put your main code here, to run repeatedly:

  sendUltrasonicWaves();
  digitalWrite(triggerPin, LOW);
  int pingTravelTime = pulseIn(echoPin, HIGH);
  float distance = ( pingTravelTime / 58 );
  Serial.println(distance);
  delay(pulseDelay);
  feedback(0, 1, 0);

  while (distance < 10.) { 

    sendUltrasonicWaves();
    digitalWrite(triggerPin, LOW);
    pingTravelTime = pulseIn(echoPin, HIGH);
    distance = ( pingTravelTime / 58 );
    delay(pulseDelay);
    feedback(1, 0, 1);

  }
}

void sendUltrasonicWaves() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(triggerPulse);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(triggerPulse);
}

void feedback(int greenLEDState, int redLEDState, int buzzState) {
  digitalWrite(buzzPin, buzzState);
  delayMicroseconds(500);
  
  digitalWrite(greenLEDPin, greenLEDState);
  
  digitalWrite(redLEDPin, redLEDState);
  
}
