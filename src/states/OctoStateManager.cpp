/*
 * OctoStateManager.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "OctoStateManager.h"

OctoStateManager::OctoStateManager() :
		AbstractStateManager(),
		// States
		m_standByState(new StandByState()),
		m_octoAlertState(new OctoAlertState()),
		m_captainBarnaclesState(new OctoButtonState(Adafruit_NeoPixel::Color(255, 144, 0), SOUND_CAPTAIN)),
		m_tweakState(new OctoButtonState(Adafruit_NeoPixel::Color(255, 144, 0), SOUND_TWEAK)),
		m_kwaziiState(new OctoButtonState(Adafruit_NeoPixel::Color(255, 144, 0), SOUND_KWASII)),
		m_pesoState(new OctoButtonState(Adafruit_NeoPixel::Color(255, 144, 0), SOUND_PESO)),
		m_countDownState(new CountDownState()),
		m_simonState(new SimonState()) {

	// Set listeners
	InputManager::getInstance()->setListener(this);

	// Initial state
	changeState(m_standByState);
}

void OctoStateManager::onNewInputState(uint8_t newState) {
	handleButtonPressed(newState);
}

bool OctoStateManager::handleButtonPressed(uint8_t newButtonsStates) {
	if (!AbstractStateManager::handleButtonPressed(newButtonsStates)) {
		if (newButtonsStates == BTN_OCTOALERT) {
			changeState(m_octoAlertState);
		} else if (newButtonsStates == BTN_COUNTDOWN) {
			changeState(m_countDownState);
		} else if (newButtonsStates == BTN_CPTBARNAC) {
			changeState(m_captainBarnaclesState);
		} else if (newButtonsStates == BTN_TWEAK) {
			changeState(m_tweakState);
		} else if (newButtonsStates == BTN_KWAZII) {
			changeState(m_kwaziiState);
		} else if (newButtonsStates == BTN_PESO) {
			changeState(m_pesoState);
		} else if (newButtonsStates == (BTN_PESO | BTN_KWAZII)) {
			if (m_currentState == m_simonState) {
				changeState(m_standByState);
			} else {
				changeState(m_simonState);
			}
		}
	}
	// Does'nt matter what we return
	return false;
}

AbstractState * OctoStateManager::getNextState(AbstractState * currentState) {
	return m_standByState;
}

void OctoStateManager::update() {
	// Just implement this::update to avoid ambiguous calls
	AbstractStateManager::update();
}

bool OctoStateManager::isFinished() {
	// Never ended (not called anyway)
	return false;
}

