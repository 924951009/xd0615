/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8
 8欧姆扬声器在数字引脚8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
//音符时长：4=四分音符，8=八分音符，等等；
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // iterate over the notes of the melody:
  //重复旋律的音符
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.要计算音符持续时间，用1秒除以音符类型
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    //例如：四分音符=1000/4,八分音符=1000/8，等等。
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    //为了区分音符，设置它们之间的最短时间。
    // the note's duration + 30% seems to work well:
    //音符的持续时间+30%似乎是有效的。
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    //停止演奏
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
  //没有必要重复旋律。
}