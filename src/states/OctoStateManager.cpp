/*
 * OctoStateManager.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "OctoStateManager.h"

//#define PRINT_DEBUG_MSGS

OctoStateManager::OctoStateManager() :

		// States
		m_standByState(new StandByState()),
		m_octoAlertState(new OctoAlertState("Alert")),
		m_captainBarnaclesState(new SoundState("Captain")),
		m_tweakState(new SoundState("Tweak")),
		m_kwaziiState(new SoundState("Kwazii")),
		m_pesoState(new SoundState("Peso")),
		m_countDownState(new CountDownState("CntDown")),
		m_simonState(new SimonState("Simon"))

{
	// Set listeners
	IOManager::getInstance()->setListener(this);

	// Initial state
	changeState(m_standByState);
}

void OctoStateManager::onNewInputState(uint8_t newState) {
	if (newState == BTN_OCTOALERT) {
		changeState(m_octoAlertState);
	} else if (newState == BTN_COUNTDOWN) {
		changeState(m_countDownState);
	} else if (newState == BTN_CPTBARNAC) {
		changeState(m_captainBarnaclesState);
	} else if (newState == BTN_TWEAK) {
		changeState(m_tweakState);
	} else if (newState == BTN_KWAZII) {
		changeState(m_kwaziiState);
	} else if (newState == BTN_PESO) {
		changeState(m_pesoState);
	} else if (newState == (BTN_PESO & BTN_KWAZII)) {
		changeState(m_simonState);
	}
}

void OctoStateManager::update(unsigned long currentTime) {
	IOManager::getInstance()->update(currentTime);
	AbstractState* nextState = m_currentState->getNextState();
	if (nextState != m_currentState) {
		changeState(nextState);
		// We recompute millis instead of use the currentTime because the stop/play delay is too long
		currentTime = millis();
	}

	// Update count down procedure
	m_currentState->update(currentTime);
}

void OctoStateManager::changeState(AbstractState* newState) {
	m_currentState = newState;
	if (m_standByState != newState) {
		// Stop music and restore stand by led states
		m_standByState->activate();
	}
	newState->activate();
}