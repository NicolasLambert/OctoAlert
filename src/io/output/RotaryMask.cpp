/*
 * RotaryMask.cpp
 *
 *  Created on: 8 févr. 2016
 *      Author: nicolas
 */

#include "RotaryMask.h"

RotaryMask::RotaryMask(uint64_t mask, uint8_t waitingTicks, uint16_t rotationCount) :
	m_startingMask(mask),
	m_maxRotationCount(rotationCount),
	m_baseWaitingTicks(waitingTicks) {
	reset();
}

uint64_t RotaryMask::getValue() {
	return m_currentMask;
}

void RotaryMask::rotate() {
	// Because we have 24 leds on the big ring and 16 on the little (24/16 = 3/2)
	rotateRing(m_waitingCountBigRing, m_baseWaitingTicks*2, LED_MASK_BIG_RING);
	rotateRing(m_waitingCountLittleRing, m_baseWaitingTicks*3, LED_MASK_LITTLE_RING);
}

void RotaryMask::rotateRing(uint8_t &waitingCounter, uint8_t waitingTicks, uint64_t rotationLocationMask) {
	waitingCounter--;
	if (!waitingCounter && (!m_maxRotationCount || m_currentRotationCount)) {
		waitingCounter = waitingTicks;
		rotateMask(m_currentMask, rotationLocationMask);
		if (m_maxRotationCount && m_currentRotationCount && m_currentMask==m_startingMask) {
			m_currentRotationCount--;
		}
	}
}

bool RotaryMask::isFinished() {
	return (m_maxRotationCount && !m_currentRotationCount);
}

void RotaryMask::rotateMask(uint64_t &colorMaskToRotate, uint64_t rotationLocationMask) {
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

void RotaryMask::reset() {
	m_currentRotationCount = m_maxRotationCount;
	m_currentMask = m_startingMask;
	m_waitingCountBigRing = m_baseWaitingTicks * 2;
	m_waitingCountLittleRing = m_baseWaitingTicks * 3;
}
