
boolean isRunning = true;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (isRunning) {
    Serial.println("Mary Kate F. Anecito");
  }
  isRunning = false;
  Serial.println("The more you know, the more you know you don't know");
  delay(2000);
}
