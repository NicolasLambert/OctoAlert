/*
 * SoundState.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#include "SoundState.h"
#include "OctoStateManager.h"

/**
 * Sound files must be named from "something1.mp3" to a maximum of "something9.mp2"
 */
SoundState::SoundState(char const * const mp3CoreName) :
		AbstractState(), m_trackNumberPosition(strlen(mp3CoreName)), m_lastIndex(1), m_maxIndex(-1) {
	if (mp3CoreName != 0) {
		strcpy(m_fileName, mp3CoreName);
		strcat(m_fileName, "X.mp3");
		do {
			// Ok, this file exist so let update the file number
			// Starting with -1 -> 0 for the first loop
			m_maxIndex++;
			// Try next file (starting with (0 + 1) for the first loop
			m_fileName[m_trackNumberPosition] = (char) (((int) '0') + (m_maxIndex + 1));
		} while (SD.exists(m_fileName));
	} else {
		m_maxIndex = 0;
	}
}

void SoundState::activate() {
	if (m_maxIndex > 0) {
		m_fileName[m_trackNumberPosition] = (char) (((int) '0') + m_lastIndex);
		m_lastIndex++;
		if (m_lastIndex > m_maxIndex) {
			m_lastIndex = 1;
		}
		OutputManager::getInstance()->m_musicPlayer->playFile(m_fileName);
	}
}

bool SoundState::isFinished() {
	return !OutputManager::getInstance()->m_musicPlayer->isPlaying();
}
