
/* 
 *  MidiLoopSwitch.ino
 *  Simple midi controllable looper/switcher
 *  Copyright (C) 2018 Pekka Huuskonen
 *  
 *  This sketch is for simple midi controllable looper/switcher for four relays.
 *  Listens midi channel 1
 *  
 *  TODO:
 *  - possibility to let the user program midi channel and switching
 *  
 *  Current version uses following arduino libraries:
 *  MIDI (https://github.com/FortySevenEffects/arduino_midi_library)
 */

 #include <MIDI.h>

// define relay pins
#define RELAY_1 2
#define RELAY_2 3
#define RELAY_3 4
#define RELAY_4 5

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  // midi begin
  MIDI.begin(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY_1, HIGH);
  delay(500);
  digitalWrite(RELAY_2, HIGH);
  delay(500);
  digitalWrite(RELAY_3, HIGH);
  delay(500);
  digitalWrite(RELAY_4, HIGH);
  delay(500);
  digitalWrite(RELAY_1, LOW);
  delay(500);
  digitalWrite(RELAY_2, LOW);
  delay(500);
  digitalWrite(RELAY_3, LOW);
  delay(500);
  digitalWrite(RELAY_4, LOW);
  delay(500);
}
