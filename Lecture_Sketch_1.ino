char code;
String message = "Your total fee is ";
String promptMsg = "Please enter code from A to D";

void setup() {
  Serial.begin(9600);
  Serial.println(promptMsg);
}  


void loop() {

  if (Serial.available()) {
    code = Serial.read();
    float total = calculateSchoolFees(code) - deductIfScholar(code);
    Serial.println(message + total);
    Serial.end();
  }

}

float calculateSchoolFees(char code) {
  float fee_per_unit = 1000.;
  float misc_fee = 3500.;
  float units;
  float discount;
  switch(code) {
    case 'A':
      units = 24.;
      discount = 0.05;
      break;
    case 'B':
      units = 26.;
      discount = 0.06;
      break;
    case 'C':
      units = 27.;
      discount = 0.07;
      break;
    default:
      units = 0.;
      discount = 0.;
      break;
  }

  return (units * fee_per_unit) + misc_fee - ( ((units * fee_per_unit) + misc_fee) * discount);
}

float deductIfScholar(char code) {
  switch (code) {
      case 'B':
        Serial.println("You are eligible for scholarship");
        return 5000.;
      case 'C':
        Serial.println("You are eligible for scholarship");
        return 3000.;
      default:
        return 0.;
  }
}