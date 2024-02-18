int pins[] = {8, 12, 13};
int pins_Size = sizeof(pins) / sizeof(pins[0]);
int waitingTime = 750;
int userInput;

void setup() {
  for (int i = 0; i < pins_Size; i++)
  {
    pinMode(pins[i],OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Enter the number of times you want to blink the LED: ");
}

void loop()
{
    while (Serial.available() > 0)
    {
      userInput = Serial.parseInt();

      int count = userInput;

      while (count > 0)
      {
        blinkLED(1, 0, 0);
        blinkLED(0, 1, 0);
        blinkLED(0, 0, 1);
        blinkLED(0, 1, 0);
        Serial.println(count);
        count--;
      }
        blinkLED(0, 0, 0);

    }

}


void blinkLED(int pin_Status1, int pin_Status2, int pin_Status3) {
  digitalWrite(pins[0], pin_Status1);
  digitalWrite(pins[1], pin_Status2);
  digitalWrite(pins[2], pin_Status3);
  delay(waitingTime);
}