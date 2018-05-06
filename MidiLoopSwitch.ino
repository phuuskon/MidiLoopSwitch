
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

#define MIDI_CHANNEL 1

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  //Serial.begin(9600);

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  // midi begin
  MIDI.begin(MIDI_CHANNEL);
  MIDI.setHandleProgramChange(handleProgramChange);
}

void loop() {
  MIDI.read();
}

void handleProgramChange(byte channel, byte number)
{
  switch(number)
  {
    case 1:
      digitalWrite(RELAY_1, LOW);
      digitalWrite(RELAY_2, LOW);
      digitalWrite(RELAY_3, LOW);
      digitalWrite(RELAY_4, LOW);
      break;
    case 2:
      digitalWrite(RELAY_1, HIGH);
      digitalWrite(RELAY_2, LOW);
      digitalWrite(RELAY_3, LOW);
      digitalWrite(RELAY_4, LOW);
      break;
    case 3:
      digitalWrite(RELAY_1, LOW);
      digitalWrite(RELAY_2, HIGH);
      digitalWrite(RELAY_3, LOW);
      digitalWrite(RELAY_4, LOW);
      break;
    case 4:
      digitalWrite(RELAY_1, LOW);
      digitalWrite(RELAY_2, LOW);
      digitalWrite(RELAY_3, HIGH);
      digitalWrite(RELAY_4, LOW);
      break;
    case 5:
      digitalWrite(RELAY_1, LOW);
      digitalWrite(RELAY_2, LOW);
      digitalWrite(RELAY_3, LOW);
      digitalWrite(RELAY_4, HIGH);
      break;
    case 6:
      digitalWrite(RELAY_1, HIGH);
      digitalWrite(RELAY_2, HIGH);
      digitalWrite(RELAY_3, LOW);
      digitalWrite(RELAY_4, LOW);
      break;
    case 7:
      digitalWrite(RELAY_1, HIGH);
      digitalWrite(RELAY_2, LOW);
      digitalWrite(RELAY_3, HIGH);
      digitalWrite(RELAY_4, LOW);
      break;
    case 8:
      digitalWrite(RELAY_1, HIGH);
      digitalWrite(RELAY_2, LOW);
      digitalWrite(RELAY_3, LOW);
      digitalWrite(RELAY_4, HIGH);
      break;
    case 9:
      digitalWrite(RELAY_1, LOW);
      digitalWrite(RELAY_2, HIGH);
      digitalWrite(RELAY_3, HIGH);
      digitalWrite(RELAY_4, LOW);
      break;
    case 10:
      digitalWrite(RELAY_1, LOW);
      digitalWrite(RELAY_2, HIGH);
      digitalWrite(RELAY_3, LOW);
      digitalWrite(RELAY_4, HIGH);
      break;
    case 11:
      digitalWrite(RELAY_1, LOW);
      digitalWrite(RELAY_2, LOW);
      digitalWrite(RELAY_3, HIGH);
      digitalWrite(RELAY_4, HIGH);
      break;
    case 12:
      digitalWrite(RELAY_1, HIGH);
      digitalWrite(RELAY_2, HIGH);
      digitalWrite(RELAY_3, HIGH);
      digitalWrite(RELAY_4, LOW);
      break;
    case 13:
      digitalWrite(RELAY_1, HIGH);
      digitalWrite(RELAY_2, HIGH);
      digitalWrite(RELAY_3, LOW);
      digitalWrite(RELAY_4, HIGH);
      break;
    case 14:
      digitalWrite(RELAY_1, HIGH);
      digitalWrite(RELAY_2, LOW);
      digitalWrite(RELAY_3, HIGH);
      digitalWrite(RELAY_4, HIGH);
      break;
    case 15:
      digitalWrite(RELAY_1, LOW);
      digitalWrite(RELAY_2, HIGH);
      digitalWrite(RELAY_3, HIGH);
      digitalWrite(RELAY_4, HIGH);
      break;
    case 16:
      digitalWrite(RELAY_1, HIGH);
      digitalWrite(RELAY_2, HIGH);
      digitalWrite(RELAY_3, HIGH);
      digitalWrite(RELAY_4, HIGH);
      break;
    default:
      break;
  }
}

