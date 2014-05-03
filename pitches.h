//Arduino Pitch Values
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
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
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//MIDI Note Values
#define NOTE_B0_MIDI  11
#define NOTE_C1_MIDI  12
#define NOTE_CS1_MIDI 13
#define NOTE_D1_MIDI  14
#define NOTE_DS1_MIDI 15
#define NOTE_E1_MIDI  16
#define NOTE_F1_MIDI  17
#define NOTE_FS1_MIDI 18
#define NOTE_G1_MIDI  19
#define NOTE_GS1_MIDI 20
#define NOTE_A1_MIDI  21
#define NOTE_AS1_MIDI 22
#define NOTE_B1_MIDI  23
#define NOTE_C2_MIDI  24
#define NOTE_CS2_MIDI 25
#define NOTE_D2_MIDI  26
#define NOTE_DS2_MIDI 27
#define NOTE_E2_MIDI  28
#define NOTE_F2_MIDI  29
#define NOTE_FS2_MIDI 30
#define NOTE_G2_MIDI  31
#define NOTE_GS2_MIDI 32
#define NOTE_A2_MIDI  33
#define NOTE_AS2_MIDI 34
#define NOTE_B2_MIDI  35
#define NOTE_C3_MIDI  36
#define NOTE_CS3_MIDI 37
#define NOTE_D3_MIDI  38
#define NOTE_DS3_MIDI 39
#define NOTE_E3_MIDI  40
#define NOTE_F3_MIDI  41
#define NOTE_FS3_MIDI 42
#define NOTE_G3_MIDI  43
#define NOTE_GS3_MIDI 44
#define NOTE_A3_MIDI  45
#define NOTE_AS3_MIDI 46
#define NOTE_B3_MIDI  47
#define NOTE_C4_MIDI  48
#define NOTE_CS4_MIDI 49
#define NOTE_D4_MIDI  50
#define NOTE_DS4_MIDI 51
#define NOTE_E4_MIDI  52
#define NOTE_F4_MIDI  53
#define NOTE_FS4_MIDI 54
#define NOTE_G4_MIDI  55
#define NOTE_GS4_MIDI 56
#define NOTE_A4_MIDI  57
#define NOTE_AS4_MIDI 58
#define NOTE_B4_MIDI  59
#define NOTE_C5_MIDI  60
#define NOTE_CS5_MIDI 61
#define NOTE_D5_MIDI  62
#define NOTE_DS5_MIDI 63
#define NOTE_E5_MIDI  64
#define NOTE_F5_MIDI  65
#define NOTE_FS5_MIDI 66
#define NOTE_G5_MIDI  67
#define NOTE_GS5_MIDI 68
#define NOTE_A5_MIDI  69
#define NOTE_AS5_MIDI 70
#define NOTE_B5_MIDI  71
#define NOTE_C6_MIDI  72
#define NOTE_CS6_MIDI 73
#define NOTE_D6_MIDI  74
#define NOTE_DS6_MIDI 75
#define NOTE_E6_MIDI  76
#define NOTE_F6_MIDI  77
#define NOTE_FS6_MIDI 78
#define NOTE_G6_MIDI  79
#define NOTE_GS6_MIDI 80
#define NOTE_A6_MIDI  81
#define NOTE_AS6_MIDI 82
#define NOTE_B6_MIDI  83
#define NOTE_C7_MIDI  84
#define NOTE_CS7_MIDI 85
#define NOTE_D7_MIDI  86
#define NOTE_DS7_MIDI 87
#define NOTE_E7_MIDI  88
#define NOTE_F7_MIDI  89
#define NOTE_FS7_MIDI 90
#define NOTE_G7_MIDI  91
#define NOTE_GS7_MIDI 92
#define NOTE_A7_MIDI  93
#define NOTE_AS7_MIDI 94
#define NOTE_B7_MIDI  95
#define NOTE_C8_MIDI  96
#define NOTE_CS8_MIDI 97
#define NOTE_D8_MIDI  98
#define NOTE_DS8_MIDI 99

int bFlatBluesScale[6] = {
	58,
	61,
	63,
	64,
	65, 
	68
};

int pitchValues[100] = {
	31,
	33,
	35,
	37,
	39,
	41,
	44,
	46,
	49,
	52,
	55,
	58,
	62,
	65,
	69,
	73,
	78,
	82,
	87,
	93,
	98,
	104,
	110,
	117,
	123,
	131,
	139,
	147,
	156,
	165,
	175,
	185,
	196,
	208,
	220,
	233,
	247,
	262,
	277,
	294,
	311,
	330,
	349,
	370,
	392,
	415,
	440,
	466,
	494,
	523,
	554,
	587,
	622,
	659,
	698,
	740,
	784,
	831,
	880,
	932,
	988,
	1047,
	1109,
	1175,
	1245,
	1319,
	1397,
	1480,
	1568,
	1661,
	1760,
	1865,
	1976,
	2093,
	2217,
	2349,
	2489,
	2637,
	2794,
	2960,
	3136,
	3322,
	3520,
	3729,
	3951,
	4186,
	4435,
	4699,
	4978
};

inline int pitchToMidi(int pitch)
{
	int i = 0;
	while (pitchValues[i] != pitch)
	{
		i++;
	}
	return i+11;
};

inline int midiToPitch(int midiNote)
{
	return pitchValues[midiNote - 11];
};
