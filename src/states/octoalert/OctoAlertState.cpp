/*
 * OctoAlertState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "OctoAlertState.h"

OctoAlertState::OctoAlertState() :
	m_sound(new SoundState(SOUND_ALERT)),
	m_blink(new SmoothBlinkState(Adafruit_NeoPixel::Color(255, 144, 0), LED_MASK_ALL, INFINITE_BLINK, -1.25, 50)) {
}

void OctoAlertState::activate() {
	m_sound->activate();
	m_blink->activate();
}

void OctoAlertState::update() {
	m_sound->update();
	m_blink->update();
}

bool OctoAlertState::isFinished() {
	return m_sound->isFinished();
}

bool OctoAlertState::handleButtonPressed(uint8_t newButtonsStates) {
	return false;
}
