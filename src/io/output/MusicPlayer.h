/*
 * MusicPlayer.h
 *
 *  Created on: 14 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef MUSICPLAYER_H_
#define MUSICPLAYER_H_

#include <Adafruit_VS1053.h>

// These are the pins used for the music maker shield
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

class MusicPlayer {
public:
	MusicPlayer();
	void playFile(char * path);
	bool isPlaying();
	void stopPlaying();
private:
	Adafruit_VS1053_FilePlayer * const m_musicPlayer;
	unsigned long m_lastGPIORead;
	uint16_t m_lastGPIOValues;
};

#endif /* MUSICPLAYER_H_ */
