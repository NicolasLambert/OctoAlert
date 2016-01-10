/*
 * InputManager.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#include "InputManager.h"

InputManager::InputManager() :
		m_octoAlertButton(new Button(42)),
		m_countDownButton(new Button(46)),
		m_captainBarnaclesButton(new Button(28)),
		m_tweakButton(new Button(22)),
		m_kwaziiButton(new Button(30)),
		m_pesoButton(new Button(26)),

		m_lastChangeTime(0),
		m_debounceDelay(DEFAULT_COMBINED_DEBOUNCE_DELAY),
		m_lastState(0),
		m_currentState(0),
		m_listener(0) {}

uint8_t InputManager::getState() {
	return
	m_octoAlertButton->getState() * BTN_OCTOALERT +
	m_countDownButton->getState() * BTN_COUNTDOWN +
	m_captainBarnaclesButton->getState() * BTN_CPTBARNAC +
	m_tweakButton->getState() * BTN_TWEAK +
	m_kwaziiButton->getState() * BTN_KWAZII +
	m_pesoButton->getState() * BTN_PESO;
}

void InputManager::update(unsigned long currentTime) {
	// Compute new manager state
	uint8_t newState = getState();

	// If the switch changed, due to noise or pressing:
	if (newState != m_lastState) {
		// reset the debouncing timer
		m_lastChangeTime = currentTime;
	}

	if ((newState != m_currentState) && ((currentTime - m_lastChangeTime) > m_debounceDelay)) {
		// whatever the reading is at, it's been there for longer
		// than the debounce delay, so take it as the actual current state:
		m_currentState = newState;
		// Ping listener only on button push
		if (m_listener) {
			m_listener->onNewInputState(m_currentState);
		}
	}

	// Save last state
	m_lastState = newState;
}

void InputManager::setListener(InputManagerListener * listener) {
	m_listener = listener;
}
