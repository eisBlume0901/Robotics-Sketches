// initialize user input variable
int userInput;
// initialize message
String message1 = "Please input 1 to 10";
String message2 = "I received: ";
// use a boolean for breaking a loop
boolean isRunning = true;
void setup() {
  Serial.begin(9600); // initialize baud rate to 9600
}

void loop() {
  if (isRunning) // To output the message only once
  {
    Serial.println(message1);
  }
  isRunning = false;

  // Checks if the input is from the range 1 to 10
  if (Serial.available() > 0 && Serial.available() <= 10) {
    // read the incoming byte:
    userInput = Serial.read();

    // Display the output to the user
    Serial.print(message2);
    Serial.println( (char) userInput);
    Serial.end(); // to end reading
  }
}
