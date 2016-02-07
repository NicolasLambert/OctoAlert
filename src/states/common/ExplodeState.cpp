/*
 * ExplodeState.cpp
 *
 *  Created on: 7 févr. 2016
 *      Author: nicolas
 */

#include "ExplodeState.h"

ExplodeState::ExplodeState(uint32_t color, int64_t ledMask) :
	m_blink_center(new SmoothBlinkState(color, ledMask & LED_MASK_CENTER, 2, 3)),
	m_blink_littleRing(new SmoothBlinkState(color, ledMask & LED_MASK_LITTLE_RING, 2, 3)),
	m_blink_bigRing(new SmoothBlinkState(color, ledMask & LED_MASK_BIG_RING, 2, 3)),
	m_littleRingDelay(0),
	m_bigRingDelay(0),
	m_activationTime(0) {}

void ExplodeState::activate() {
	OutputManager::getInstance()->m_octoAlertLeds->off(LED_MASK_ALL);
	m_littleRingDelay = 100;
	m_bigRingDelay = 200;
	m_blink_center->activate();
	m_activationTime = millis();
}

void ExplodeState::update() {
	m_blink_center->update();
	unsigned long currentTime = millis();
	if (m_littleRingDelay==0) {
		m_blink_littleRing->update();
	} else if (currentTime > (m_activationTime + m_littleRingDelay)) {
		m_littleRingDelay = 0;
		m_blink_littleRing->activate();
	}
	if (m_bigRingDelay==0) {
		m_blink_bigRing->update();
	} else if (currentTime > (m_activationTime + m_bigRingDelay)) {
		m_bigRingDelay = 0;
		m_blink_bigRing->activate();
	}
}

bool ExplodeState::isFinished() {
	return m_blink_center->isFinished() && m_blink_littleRing->isFinished() && m_blink_bigRing->isFinished();
}
