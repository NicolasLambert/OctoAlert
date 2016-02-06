/*
 * MusicPlayer.cpp
 *
 *  Created on: 14 juil. 2014
 *      Author: nicolaslambert
 */

#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() :
				m_musicPlayer(new Adafruit_VS1053_FilePlayer(SHIELD_CS, SHIELD_DCS, DREQ, CARDCS)),
				m_lastGPIORead(0UL),
				m_lastGPIOValues(0) {
	if (!m_musicPlayer->begin()) { // initialise the music player
		while (1);
	}
	Serial.println("VS1053 found");

	if (!SD.begin(CARDCS)) { // initialise the SD card
		while (1);
	}
	Serial.println("SD card OK");

	if (!m_musicPlayer->useInterrupt(VS1053_FILEPLAYER_PIN_INT)) {
		while (1);
	}

	m_musicPlayer->setVolume(20, 20);
}

bool MusicPlayer::isPlaying() {
	return m_musicPlayer->playingMusic;
}

void MusicPlayer::playFile(char * path) {
	if (path) {
		m_musicPlayer->startPlayingFile(path);
	}
}

void MusicPlayer::stopPlaying() {
	if (m_musicPlayer->playingMusic) {
		m_musicPlayer->stopPlaying();
		// It seems that the VS1053 need a little delay between stop a play.
		// Without this delay, the VS1053 crash very often and/or we got a big delay between play call and real playing
		delay(50);
	}
}
