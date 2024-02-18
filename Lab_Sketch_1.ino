boolean isRunning = true; // to be used to break from the loop
void setup() {
  // initialize baud rate to 9600
  Serial.begin(9600);
}

void loop() {
  // use if-else statement to break from the loop
  if (isRunning) {
    Serial.println("Hello, world"); // break the loop
  }
  isRunning = false;
}
