/*
 * OctoButtonState.cpp
 *
 *  Created on: 7 févr. 2016
 *      Author: nicolas
 */

#include "../octonauts/OctoButtonState.h"

OctoButtonState::OctoButtonState(uint32_t color, char const * const mp3Path) :
	RadarState(LED_MASK_RADAR),
	m_color(color),
	m_soundState(new SoundState(mp3Path)) {}

void OctoButtonState::activate() {
	RadarState::activate();
	m_soundState->activate();
}

void OctoButtonState::update() {
	RadarState::update();
	m_soundState->update();
}

bool OctoButtonState::isFinished() {
	return m_soundState->isFinished();
}

void OctoButtonState::setColors() {
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_ALL, m_color);
}
