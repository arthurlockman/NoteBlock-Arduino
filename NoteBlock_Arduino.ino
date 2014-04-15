#include "Tone.h"

#include "Arduino.h"
#include "Pitches.h"
#include "utils.h"
#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);

Tone speaker1;
Tone speaker2;

#define SP_1  4
#define SP_2  5
#define ACC_X 0
#define ACC_Y 1
#define ACC_Z 2
#define MIC   3

int m_lastX = 0;
int m_lastY = 0;
int m_lastZ = 0;
int m_lastMic = 0;

void setup() 
{
  xbee.begin(9600);
  Serial.begin(115200);
  
 speaker1.begin(SP_1);
 speaker2.begin(SP_2);
}

void loop() 
{
	// readAccelerometers();
	readMic();
	// processData(m_lastX, m_lastY, m_lastZ, m_lastMic);
  // playChord(midiToPitch(50), midiToPitch(54), 1000);
  Serial.println(m_lastMic);
  delay(10);
}

void readAccelerometers()
{
	m_lastX = analogRead(ACC_X);
	m_lastY = analogRead(ACC_Y);
	m_lastZ = analogRead(ACC_Z);
}

void readMic()
{
	m_lastMic = analogRead(MIC);
}

void processData(int x, int y, int z, int mic)
{
	//Process accelerometer data and turn into notes.
  int note = map((x + y + z), 0, 3069, 11, 99);
  if (note > 49 || note < 47)
  {
    playChord(midiToPitch(note), midiToPitch(note + 4), 100);
    // sendNote(note, note + 4);
  }
}

void playChord(int tone1, int tone2, int duration)
{
 speaker1.play(tone1, duration);
  speaker2.play(tone2, duration);
}

void playNote(int channel, int tone, int duration)
{
  switch (channel)
  {
    case 1:
      speaker1.play(tone, duration);
      break;
    case 2:
      speaker2.play(tone, duration);
      break;
  }
}

void sendNote(int note1, int note2)
{
	xbee.print(note1);
  xbee.print(",");
  xbee.println(note2);
  Serial.print(note1);
  Serial.print(",");
  Serial.println(note2);
}

