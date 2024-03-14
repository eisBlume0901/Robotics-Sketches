// Music Sheet used: https://www.bethsnotesplus.com/2016/03/leron-leron-sinta.html
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

#include <Volume.h>
#define buzzPin 5
Volume vol;

float duration = 2500;
float dot = 0.75;
int potReader = A2;
int potValue;

int melody[] = {
  //1
  NOTE_A4, 
  //2
  NOTE_A4,
  NOTE_G4,
  NOTE_FS4,
  NOTE_G4,
  //3
  NOTE_A4,
  NOTE_A4,
  //4
  NOTE_B4,
  NOTE_A4,
  NOTE_FS4,
  NOTE_A4,
  //5
  NOTE_G4,
  NOTE_G4,
  //6
  NOTE_G4,
  NOTE_FS4,
  NOTE_E4,
  NOTE_FS4,
  //7 Another line
  NOTE_G4,
  NOTE_A4,
  //8
  NOTE_A4,
  NOTE_B4,
  NOTE_A4,
  NOTE_G4,
  //9
  NOTE_FS4,
  NOTE_A4,
  //10
  NOTE_A4,
  NOTE_G4,
  NOTE_FS4,
  NOTE_G4,
  //11
  NOTE_A4,
  NOTE_FS4,
  //12
  NOTE_FS4,
  NOTE_FS4,
  NOTE_G4,
  NOTE_A4,
  //13 Another line
  NOTE_B4,
  NOTE_B4,
  //14
  NOTE_B4,
  NOTE_B4,
  NOTE_G4,
  NOTE_B4,
  //15
  NOTE_A4,
  NOTE_A4,
  //16
  NOTE_G4,
  NOTE_B4,
  NOTE_A4,
  NOTE_G4,
  //17
  NOTE_FS4
};
float noteDenominations[] = {
  //1
  8, 
  //2
  8 * dot,
  16,
  8,
  8,
  //3
  4 * dot,
  8,
  //4
  8 * dot,
  16,
  8,
  8,
  //5
  4 * dot,
  8,
  //6
  8 * 0.66,
  16, 
  8,
  8,
  //7
  4 * dot,
  8,
  //8
  8 * dot,
  16,
  8,
  8,
  //9
  4 * dot,
  8,
  //10
  8,
  8,
  8,
  8,
  //11
  4 * dot,
  8,
  //12
  8,
  8,
  8,
  8,
  //13 Another line
  4 * dot,
  8,
  //14
  8 * dot,
  16,
  8,
  8,
  //15
  4 * dot,
  8,
  // 16
  8,
  8,
  8,
  8,
  //
  4 * dot
};

int melodySize = sizeof(melody) / sizeof(melody[0]);

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(potReader, INPUT);
  vol.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < melodySize; i++) {
    potValue = analogRead(potReader);

    vol.tone(melody[i], map(potValue, 0, 1023, 0, 255));
    vol.delay(duration / noteDenominations[i]);
    vol.noTone();
    
  }
}
