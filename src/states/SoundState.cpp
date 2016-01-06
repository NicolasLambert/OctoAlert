/*
 * SoundState.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#include "SoundState.h"
#include "OctoStateManager.h"

SoundState::SoundState(char const * const mp3CoreName) :
		AbstractState(), m_trackNumberPosition(strlen(mp3CoreName)), m_lastIndex(0), m_maxIndex(1) {
	if (mp3CoreName != 0) {
		strcpy(m_fileName, mp3CoreName);
		strcat(m_fileName, "1.mp3");
		Serial.print("Test1 ");
		Serial.println(m_fileName);
		while (SD.exists(m_fileName)) {
			m_maxIndex++;
			m_fileName[m_trackNumberPosition] = (char) (((int) '0') + m_maxIndex);
			Serial.print("TestN ");
			Serial.println(m_fileName);
		}
	} else {
		m_maxIndex = 0;
	}
}

void SoundState::activate() {
	if (m_maxIndex > 0) {
		m_lastIndex++;
		if (m_lastIndex >= m_maxIndex) {
			m_lastIndex = 1;
		}
		m_fileName[m_trackNumberPosition] = (char) (((int) '0') + m_lastIndex);
		Serial.print("Play--> ");
		Serial.println(m_fileName);
		IOManager::getInstance()->m_musicPlayer->playFile(m_fileName);
	}
}

AbstractState * SoundState::getNextState() {
	if (IOManager::getInstance()->m_musicPlayer->isPlaying()) {
		return this;
	}
	return OctoStateManager::getInstance()->m_standByState;
}
