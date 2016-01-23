/*
 * OctoAlertState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "OctoAlertState.h"

OctoAlertState::OctoAlertState(char const * const mp3Path) :
		SoundState(mp3Path), m_yellow(Adafruit_NeoPixel::Color(255, 144, 0)) {
}

void OctoAlertState::activate() {
	SoundState::activate();
	OutputManager::getInstance()->m_octoAlertLeds->smoothBlink(m_yellow, ALL_QUARTER, 0, 50);
}
