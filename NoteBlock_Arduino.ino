#include "Arduino.h"
#include "Pitches.h"
#include "utils.h"

#define ACC_X 0
#define ACC_Y 1
#define ACC_Z 2

float m_lastX = 0.0;
float m_lastY = 0.0;
float m_lastZ = 0.0;

static const int deadbandSize = 1;

void setup() 
{

}

void loop() 
{
	readAccelerometers();
	processData();
}

float readAccelerometers()
{
	m_lastX = Deadband(analogRead(ACC_X), deadbandSize, 0);
	m_lastY = Deadband(analogRead(ACC_Y), deadbandSize, 0);
	m_lastZ = Deadband(analogRead(ACC_Z), deadbandSize, 0);
}

void processData()
{
	//Process accelerometer data and turn into notes.
}

void playTone()
{

}

void sendNote()
{

}

