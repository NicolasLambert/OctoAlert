/*
 * OctoAlertState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "OctoAlertState.h"

OctoAlertState::OctoAlertState(char const * const mp3Path) :
		SoundState(mp3Path) {
}

void OctoAlertState::activate() {
	SoundState::activate();
	IOManager::getInstance()->m_octoAlertLeds->smoothBlink(255, 144, 0);
}
