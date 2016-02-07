/*
 * SimonIntroState.cpp
 *
 *  Created on: 1 févr. 2016
 *      Author: nicolas
 */

#include "SimonIntroState.h"

SimonIntroState::SimonIntroState() :
	SoundState(SOUND_SIMON_INTRO),
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

void SimonIntroState::activate() {
	SoundState::activate();
	m_redMask = (LED_MASK_TOP_RIGHT_QUARTER & ~LED_MASK_CENTER);
	m_blueMask = (LED_MASK_BOTTOM_RIGHT_QUARTER & ~LED_MASK_CENTER);
	m_yellowMask = (LED_MASK_BOTTOM_LEFT_QUARTER & ~LED_MASK_CENTER);
	m_greenMask = (LED_MASK_TOP_LEFT_QUARTER & ~LED_MASK_CENTER);
	OutputManager::getInstance()->m_octoAlertLeds->off(LED_MASK_CENTER);
	m_waitingCountLittleRing = WAITING_TICKS_LITTLE_RING;
	m_waitingCountBigRing = WAITING_TICKS_BIG_RING;
}

void SimonIntroState::update() {
	SoundState::update();
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_redMask, m_red, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_blueMask, m_blue, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_yellowMask, m_yellow, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_greenMask, m_green, false);
	rotateAll(m_waitingCountLittleRing, WAITING_TICKS_LITTLE_RING, LED_MASK_LITTLE_RING);
	rotateAll(m_waitingCountBigRing, WAITING_TICKS_BIG_RING, LED_MASK_BIG_RING);
}

void SimonIntroState::rotateAll(uint8_t &waitingCounter, uint8_t waitingTicks, uint64_t rotationLocationMask) {
	waitingCounter--;
	if (!waitingCounter) {
		waitingCounter = waitingTicks;
		rotate(m_redMask, rotationLocationMask);
		rotate(m_blueMask, rotationLocationMask);
		rotate(m_yellowMask, rotationLocationMask);
		rotate(m_greenMask, rotationLocationMask);
	}
}
