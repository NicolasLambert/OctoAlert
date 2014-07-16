/*
 * CountDownState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "CountDownState.h"

CountDownState::CountDownState(char const * const mp3Path) :
		SoundState(mp3Path), m_lastStepTime(0UL), m_lastStep(0) {

}

void CountDownState::activate() {
	SoundState::activate();
	m_lastStep = 1;
	m_lastStepTime = 0UL;
	IOManager::getInstance()->m_startLed->off();
}

void CountDownState::update(unsigned long currentTime) {
	if (m_lastStep > 0 && m_lastStepTime + cntDwnDelay[m_lastStep - 1] < currentTime) {
		m_lastStepTime = currentTime;
		switch (m_lastStep) {
		case 1:
			// just wait for the intro music
			break;
		case 2:
			// First beep
			IOManager::getInstance()->m_red1Led->on();
			break;
		case 3:
			// Second beep
			IOManager::getInstance()->m_red2Led->on();
			break;
		case 4:
			// Third beep
			IOManager::getInstance()->m_red3Led->on();
			break;
		case 5:
			// Fourth beep
			IOManager::getInstance()->m_orangeLed->on();
			break;
		case 6:
			// Fifth beep
			IOManager::getInstance()->m_greenLed->on();
			/* no break */
		default:
			m_lastStep = 0;
			return;
		}
		m_lastStep++;
	}

}
