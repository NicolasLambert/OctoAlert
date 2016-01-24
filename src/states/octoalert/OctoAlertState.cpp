/*
 * OctoAlertState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "OctoAlertState.h"

OctoAlertState::OctoAlertState(char const * const mp3Path) :
		SoundState(mp3Path), m_yellow(Adafruit_NeoPixel::Color(255, 144, 0)),
		m_smoothBlink(new SmoothBlink(Adafruit_NeoPixel::Color(255, 144, 0), LED_MASK_ALL, 0, 50)) {
}

void OctoAlertState::activate() {
	SoundState::activate();
	m_smoothBlink->activate();
}

void OctoAlertState::update() {
	SoundState::update();
	m_smoothBlink->update();
}
