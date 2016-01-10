/*
 * OctoStateManager.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "OctoStateManager.h"

OctoStateManager::OctoStateManager() :

		// States
		m_standByState(new StandByState()),
		m_octoAlertState(new OctoAlertState("Alert")),
		m_captainBarnaclesState(new SoundState("Captain")),
		m_tweakState(new SoundState("Tweak")),
		m_kwaziiState(new SoundState("Kwazii")),
		m_pesoState(new SoundState("Peso")),
		m_countDownState(new CountDownState("CntDown")),
		m_simonState(new SimonState("Simon")) {

	// Set listeners
	InputManager::getInstance()->setListener(this);

	// Initial state
	changeState(m_standByState);
}

void OctoStateManager::onNewInputState(uint8_t newState) {
	if (!m_currentState->shouldStayInThisState(newState)) {
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
		} else if (newState == (BTN_PESO | BTN_KWAZII)) {
			if (m_currentState == m_simonState) {
				changeState(m_standByState);
			} else {
				changeState(m_simonState);
			}
		}
	}
}

void OctoStateManager::update() {
	if (m_currentState->isFinished()) {
		changeState(m_standByState);
	}

	// Update count down procedure
	m_currentState->update();
}

void OctoStateManager::changeState(AbstractState* newState) {
	m_currentState = newState;
	if (m_standByState != newState) {
		// Stop music and restore stand by led states
		OutputManager::getInstance()->m_musicPlayer->stopPlaying();
		m_standByState->activate();
	}
	newState->activate();
}
