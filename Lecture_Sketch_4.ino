#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_G5 784


int buzzPin = 8; // Initialize passiveBuzzer pin
int duration = 3000; // 3 seconds
int melody1[] =
{
  NOTE_B4, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_CS5, NOTE_G5, NOTE_G5
};

int noteDurations1[] =
{
  8, 8, 4, 4, 4, 4, 8, 8, 8
};

int melody2[] =
{
  NOTE_CS5, NOTE_CS5, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_E5, NOTE_B4, NOTE_D5
};

int noteDurations2[] =
{
  8, 8, 8, 8, 4, 4, 4, 4
};

void setup() {
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  playPart1();
  noTone(buzzPin);

  playPart2();
  noTone(buzzPin);

  playPart1();
  noTone(buzzPin);

  playPart2();
  noTone(buzzPin);
}

void playPart1() {
    for (int thisNote = 0; thisNote < 9; thisNote++) {

    int noteDuration = duration / noteDurations1[thisNote];
    tone(buzzPin, melody1[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration;
    delay(pauseBetweenNotes);
    noTone(buzzPin);
  }
}

void playPart2() {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = duration / noteDurations2[thisNote];
    tone(buzzPin, melody2[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration;
    delay(pauseBetweenNotes);
    noTone(buzzPin);
  }
}
