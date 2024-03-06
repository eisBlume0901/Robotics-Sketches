#include "Volume.h" 
Volume vol;

#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_G5 784


int potReader = A1;
int potValue;
int buzzPin = 5; // Initialize passiveBuzzer pin
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
  vol.begin();
  pinMode(buzzPin, OUTPUT);
  pinMode(potReader, A1);
}

void loop() {

  // potValue = analogRead(potReader);
  // int volume = map(potValue, 0, 1023, 0, 255);
  playPart1();
  vol.noTone();

  playPart2();
  vol.noTone();

  playPart1();
  vol.noTone();

  playPart2();
  vol.noTone();
}

void playPart1() {
    for (int thisNote = 0; thisNote < 9; thisNote++) {
    potValue = analogRead(potReader);
    Serial.print(potValue);

    int noteDuration = duration / noteDurations1[thisNote];
    vol.tone(melody1[thisNote], map(potValue, 0, 1023, 50, 255));
    vol.delay(noteDurations1[thisNote]);
    int pauseBetweenNotes = noteDuration;
    vol.delay(pauseBetweenNotes);
    vol.noTone();
  }
}

void playPart2() {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    potValue = analogRead(potReader);

    int noteDuration = duration / noteDurations2[thisNote];
    vol.tone(melody2[thisNote], map(potValue, 0, 1023, 50, 255));
    vol.delay(noteDurations1[thisNote]);

    int pauseBetweenNotes = noteDuration;
    vol.delay(pauseBetweenNotes);
    vol.noTone();
  }
}
