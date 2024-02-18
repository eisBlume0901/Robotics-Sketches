int pin = 2;

int waitingTime = 750;

int userInput;

 

void setup() {

  // put your setup code here, to run once:

  pinMode(pin, OUTPUT);

  Serial.begin(9600);

  Serial.println("How many times do you want to blink? ");

}

 

void loop() {

  // put your main code here, to run repeatedly:

  /*

   * If it is user input, put it inside serial.available

   */

  while (Serial.available() > 0) {

    userInput = Serial.parseInt();

 

    int count = userInput;

 

    while (count > 0) {

      Serial.println(count);

      blinkLED(pin);

      count--;

    }

  }

}

 

void blinkLED(int pinNum) {

  digitalWrite(pinNum,HIGH);

  delay(waitingTime);

  digitalWrite(pinNum,LOW);

  delay(waitingTime);

}