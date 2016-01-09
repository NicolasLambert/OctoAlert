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
	IOManager::getInstance()->setListener(&OctoStateManager::buttonChanged);

	// Initial state
	changeState(m_standByState);
}

void OctoStateManager::buttonChanged(uint8_t buttonStates) {
	if (buttonStates == BTN_OCTOALERT) {
		getInstance()->changeState(getInstance()->m_octoAlertState);
	} else if (buttonStates == BTN_COUNTDOWN) {
		getInstance()->changeState(getInstance()->m_countDownState);
	} else if (buttonStates == BTN_CPTBARNAC) {
		getInstance()->changeState(getInstance()->m_captainBarnaclesState);
	} else if (buttonStates == BTN_TWEAK) {
		getInstance()->changeState(getInstance()->m_tweakState);
	} else if (buttonStates == BTN_KWAZII) {
		getInstance()->changeState(getInstance()->m_kwaziiState);
	} else if (buttonStates == BTN_PESO) {
		getInstance()->changeState(getInstance()->m_pesoState);
	} else if (buttonStates == (BTN_PESO & BTN_KWAZII)) {
		getInstance()->changeState(getInstance()->m_simonState);
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
