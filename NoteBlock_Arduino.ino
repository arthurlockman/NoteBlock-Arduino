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

#define MODE_DEBUG 1
#define MODE_RUN 2

int m_lastX = 0;
int m_lastY = 0;
int m_lastZ = 0;
int m_lastMic = 0;
int m_lastSide = 1;

int m_mode = 1;
int m_sound = 1;

int MODE = MODE_RUN;

void setup() 
{
  xbee.begin(9600);
  Serial.begin(115200);
  
 speaker1.begin(SP_1);
 speaker2.begin(SP_2);
}

void loop() 
{
	readAccelerometers();
	readMic();
  detectSide();

  if (MODE == MODE_DEBUG)
  {
    logData();
    delay(1);
  }
  else if (MODE == MODE_RUN)
  {
  	processData(m_lastX, m_lastY, m_lastZ, m_lastMic);
            
    if (xbee.available() > 0) {
      int incomingByte = xbee.read();
      Serial.print("I received: ");
      Serial.println(incomingByte, DEC);

      if (incomingByte == 10 || incomingByte == 80)
      {
        //do nothing
      }
      else if (incomingByte == 83) //Toggle Sound
      {
        (m_sound == 1)? m_sound = 0 : m_sound = 1;
        Serial.println("Toggling sound...");
      }
      else if (incomingByte == 49) //Switch to mode 1
      {
        m_mode = 1;
        Serial.println("Switching to mode 1...");
      }
      else if (incomingByte == 50) //Switch to mdoe 2
      {
        m_mode = 2;
        Serial.println("Switching to mode 2...");
      }
      else if (incomingByte == 51) //Switch to mode 3
      {
        m_mode = 3;
        Serial.println("Switching to mode 3...");
      }
      else if (incomingByte == 68) //Switch to debug mode
      {
        MODE = MODE_DEBUG;
      }
      else if (incomingByte == 82) //Switch to run mode
      {
        MODE = MODE_RUN;
      }
    }
    if (m_mode == 2)
      delay(100+m_lastMic);
    else
      delay(100);
  }
}

void readAccelerometers()
{
	m_lastX = analogRead(ACC_X);
	m_lastY = analogRead(ACC_Y);
	m_lastZ = analogRead(ACC_Z);
}

void readMic()
{
	m_lastMic = map(analogRead(MIC), 200, 500, 0, 100);
  if(m_lastMic >= 100)
    m_lastMic = 100;
  else if (m_lastMic <= 0)
    m_lastMic = 0;
}

void processData(int x, int y, int z, int mic)
{
	//Process accelerometer data and turn into notes.
  
  int mod = map(m_lastMic, 0, 100, 1, 11);
  int note;
  switch (m_mode) {
      case 1:
        note = map((x + y + z), 0, 3069, 11, 99);
        playChord(midiToPitch(note), midiToPitch(note + 4), 100);
        sendNote(note, note + 4);
        break;
      case 2:
        note = map((x + y + z), 0, 3069, 11, 99);        
        playChord(midiToPitch(note), midiToPitch(note + mod), 100);
        sendNote(note, note + mod);
        break;
      case 3:
        note = bFlatBluesScale[m_lastSide-1];
        playChord(midiToPitch(note), midiToPitch(note + 10), 100);
        sendNote(note, note + 10);
        break;
      default:
        note = map((x + y + z), 0, 3069, 11, 99);
        if (note > 49 || note < 47)
        {
          playChord(midiToPitch(note), midiToPitch(note + mod), 100);
          sendNote(note, note + mod);
        }
        break;
  }
}

void playChord(int tone1, int tone2, int duration)
{
  if (m_sound == 1)
  {
    speaker1.play(tone1, duration);
    speaker2.play(tone2, duration);
  }
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

void logData()
{
  xbee.print(m_lastX);
  xbee.print(",");
  xbee.print(m_lastY);
  xbee.print(",");
  xbee.print(m_lastZ);
  xbee.print(",");
  xbee.print(m_lastMic);
  xbee.print(",");
  xbee.print(m_lastSide);
  xbee.print("\n");
}

int detectSide()
{
  if (WithinTolerance(m_lastX, 552, 20) && WithinTolerance(m_lastY, 580, 20) 
    && WithinTolerance(m_lastZ, 720, 20))
  {
    m_lastSide = 1;
  }
  else if (WithinTolerance(m_lastX, 540, 20) && WithinTolerance(m_lastY, 820, 20) 
    && WithinTolerance(m_lastZ, 470, 30))
  {
    m_lastSide = 2;
  }
  else if (WithinTolerance(m_lastX, 300, 20) && WithinTolerance(m_lastY, 570, 20) 
    && WithinTolerance(m_lastZ, 470, 30))
  {
    m_lastSide = 3;
  }
  else if (WithinTolerance(m_lastX, 550, 20) && WithinTolerance(m_lastY, 330, 20) 
    && WithinTolerance(m_lastZ, 470, 30))
  {
    m_lastSide = 4;
  }
  else if (WithinTolerance(m_lastX, 790, 20) && WithinTolerance(m_lastY, 580, 20) 
    && WithinTolerance(m_lastZ, 470, 30))
  {
    m_lastSide = 5;
  }
  else if (WithinTolerance(m_lastX, 530, 20) && WithinTolerance(m_lastY, 570, 20) 
    && WithinTolerance(m_lastZ, 220, 20))
  {
    m_lastSide = 6;
  }
  else
  {
    return m_lastSide;
  }
}
