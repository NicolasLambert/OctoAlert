/*
 * IntroAnimation.cpp
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#include "IntroAnimation.h"

IntroAnimation::IntroAnimation() :
	m_redMask(0),
	m_blueMask(0),
	m_yellowMask(0),
	m_greenMask(0),
	m_red(COLOR_RED),
	m_blue(COLOR_BLUE),
	m_yellow(COLOR_YELLOW),
	m_green(COLOR_GREEN),
	m_waitingCountBigRing(0),
	m_waitingCountLittleRing(0) {}

void IntroAnimation::activate() {
	m_redMask = (LED_MASK_TOP_RIGHT_QUARTER & ~LED_MASK_CENTER);
	m_blueMask = (LED_MASK_BOTTOM_RIGHT_QUARTER & ~LED_MASK_CENTER);
	m_yellowMask = (LED_MASK_BOTTOM_LEFT_QUARTER & ~LED_MASK_CENTER);
	m_greenMask = (LED_MASK_TOP_LEFT_QUARTER & ~LED_MASK_CENTER);
	OutputManager::getInstance()->m_octoAlertLeds->off(LED_MASK_CENTER);
	m_waitingCountLittleRing = WAITING_TICKS_LITTLE_RING;
	m_waitingCountBigRing = WAITING_TICKS_BIG_RING;
}

void IntroAnimation::update() {
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_redMask, m_red, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_blueMask, m_blue, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_yellowMask, m_yellow, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_greenMask, m_green, false);
	rotateAll(m_waitingCountLittleRing, WAITING_TICKS_LITTLE_RING, LED_MASK_LITTLE_RING);
	rotateAll(m_waitingCountBigRing, WAITING_TICKS_BIG_RING, LED_MASK_BIG_RING);
}

void IntroAnimation::rotateAll(uint8_t &waitingCounter, uint8_t waitingTicks, uint64_t rotationLocationMask) {
	waitingCounter--;
	if (!waitingCounter) {
		waitingCounter = waitingTicks;
		rotateOne(m_redMask, rotationLocationMask);
		rotateOne(m_blueMask, rotationLocationMask);
		rotateOne(m_yellowMask, rotationLocationMask);
		rotateOne(m_greenMask, rotationLocationMask);
	}
}

void IntroAnimation::rotateOne(uint64_t &colorMaskToRotate, uint64_t rotationLocationMask) {
	// Get the lowest set bit
	int rotationStartIndex = __builtin_ctzll(rotationLocationMask);
	uint64_t ring = colorMaskToRotate;
	// Remove useless bits
	ring &= rotationLocationMask;
	// Shift if necessary for rotation
	ring >>= rotationStartIndex;
	// Rotate by 1
	ring = ((ring >> 1) | (ring << (__builtin_popcountll(rotationLocationMask) - 1)));
	// Shift to restore maskIndex
	ring <<= rotationStartIndex;
	// Clean any polluted bit
	ring &= rotationLocationMask;
	// Override rotated bits
	colorMaskToRotate = ((colorMaskToRotate & ~rotationLocationMask) | ring);
}
