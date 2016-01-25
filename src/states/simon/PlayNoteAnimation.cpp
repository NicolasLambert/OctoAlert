/*
 * PlayNoteAnimation.cpp
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#include "PlayNoteAnimation.h"


PlayNoteAnimation::PlayNoteAnimation(uint32_t color, int64_t ledMask)
	: OctoAlertLedAnimation(),
	m_blink_center(new SmoothBlink(color, ledMask & LED_MASK_CENTER, 2, 3)),
	m_blink_littleRing(new SmoothBlink(color, ledMask & LED_MASK_LITTLE_RING, 2, 3)),
	m_blink_bigRing(new SmoothBlink(color, ledMask & LED_MASK_BIG_RING, 2, 3)),
	m_littleRingDelay(0),
	m_bigRingDelay(0),
	m_activationTime(0) {}

void PlayNoteAnimation::activate() {
	OutputManager::getInstance()->m_octoAlertLeds->off(LED_MASK_ALL);
	m_littleRingDelay = 100;
	m_bigRingDelay = 200;
	m_blink_center->activate();
	m_activationTime = millis();
}

void PlayNoteAnimation::update() {
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
