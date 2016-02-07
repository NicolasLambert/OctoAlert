/*
 * RadarState.cpp
 *
 *  Created on: 7 févr. 2016
 *      Author: nicolas
 */

#include "RadarState.h"

RadarState::RadarState(uint32_t color, uint64_t ledMask, uint16_t rotationCount) :
	m_color(color),
	m_ledMask(ledMask),
	m_startLedMask(ledMask),
	m_maxRotationCount(rotationCount),
	m_currentRotationCount(rotationCount),
	m_waitingCounts(0) {}

void RadarState::activate() {
	m_ledMask = m_startLedMask & (LED_MASK_LED_17 | LED_MASK_LED_29);
	m_waitingCounts = WAITING_TICKS;
}

void RadarState::update() {
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_ledMask, m_color, true);
	m_waitingCounts--;
	if (!m_waitingCounts) {
		m_waitingCounts = WAITING_TICKS;
		rotate(m_ledMask, LED_MASK_BIG_RING);
	}
}

bool RadarState::isFinished() {
	return false;
}
