int userInput;
int pins[] = {3, 6, 9, 11, 13};
int pin_Size = sizeof(pins) / sizeof(pins[0]);
int waitingTime = 200;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < pin_Size; i++) {
    pinMode(pins[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Choose what LED pattern you want: ");
  Serial.println("Please enter an integer only");
  Serial.println("[1] Boogie Woogie");
  Serial.println("[2] Cha-cha");
  Serial.println("[3] Kate's Pattern");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    userInput = Serial.parseInt();
    String displayMessage = "Now playing ";
    switch (userInput) {
      case 1:
        displayMessage += "boogie woogie";
        Serial.println(displayMessage);
        playBoogieWoogie();
        break;
      case 2:
        displayMessage += "cha cha";
        Serial.println(displayMessage);
        playChaCha();
        break;
      default:
        displayMessage += "kate's pattern";
        Serial.println(displayMessage);
        playKatesPattern();
        break;
    }
    
  }

}

void blinkLED(int led0, int led1, int led2, int led3, int led4){
  digitalWrite(pins[0], led0);
  digitalWrite(pins[1], led1);
  digitalWrite(pins[2], led2);
  digitalWrite(pins[3], led3);
  digitalWrite(pins[4], led4);
}

void turnOffAll() {
    delay(waitingTime);
    blinkLED(0, 0, 0, 0, 0);
    delay(waitingTime);
}


void playBoogieWoogie() {
  for (int i = 0; i < 5; i++) {
    for (int i = 0; i < 4; i++) {
      blinkLED(1, 0, 0, 0, 0);
      turnOffAll();
    
      blinkLED(0, 0, 1, 0, 0);
      turnOffAll();
      
      blinkLED(0, 0, 0, 0, 1);
      turnOffAll();
    }
  
    for (int i = 0; i < 2; i++) {
      blinkLED(0, 1, 0, 1, 0);
      turnOffAll();
    }
  }
}

void playChaCha() {
    for (int i = 0; i < 5; i++) {
      for (int i = 0; i < 2; i++) {
      blinkLED(1, 0, 0, 0, 0);
      turnOffAll();
      
      blinkLED(0, 0, 0, 0, 1);
      turnOffAll();
  
      blinkLED(0, 0, 0, 1, 0);
      turnOffAll();
  
      blinkLED(0, 0, 1, 0, 0);
      turnOffAll();

      blinkLED(0, 1, 0, 0, 0);
      turnOffAll();
        
      blinkLED(0, 1, 0, 0, 0);
      turnOffAll();
    }
  
      for (int i = 0; i < 2; i++) {
        blinkLED(1, 1, 1, 1, 1);
        turnOffAll();
      }
    }
}

void playKatesPattern() {
  for (int i = 0; i < 3; i++) {
    for (int i = 0; i < 3; i++) {
      blinkLED(0, 1, 0, 1, 0);
      turnOffAll();
    }

    for (int i = 0; i < 2; i++) {
      blinkLED(1, 0, 1, 0, 1);
      turnOffAll();
    }

    blinkLED(1, 1, 1, 1, 1);
    turnOffAll();
    
    blinkLED(1, 0, 0, 0, 1);
    turnOffAll();

    blinkLED(0, 1, 0, 1, 0);
    turnOffAll();

    blinkLED(0, 0, 1, 0, 0);
    turnOffAll();
  }
}