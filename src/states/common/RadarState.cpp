/*
 * RadarState.cpp
 *
 *  Created on: 7 févr. 2016
 *      Author: nicolas
 */

#include "RadarState.h"

RadarState::RadarState(uint64_t mask, uint8_t waitingTicks, uint16_t rotationCount) :
	m_ledMask(new RotaryMask(mask, waitingTicks, rotationCount)),
	m_colorOff(COLOR_OFF) {}

void RadarState::activate() {
	m_ledMask->reset();
}

void RadarState::update() {
	setColors();
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_ledMask->getValue(), m_colorOff, false);
	m_ledMask->rotate();
}

bool RadarState::isFinished() {
	return m_ledMask->isFinished();
}
