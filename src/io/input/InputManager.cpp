/*
 * InputManager.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#include "InputManager.h"

InputManager::InputManager() :
		InputListener(),

		m_octoAlertButton(new Button(42, BTN_OCTOALERT)),
		m_countDownButton(new Button(46, BTN_COUNTDOWN)),
		m_captainBarnaclesButton(new Button(28, BTN_CPTBARNAC)),
		m_tweakButton(new Button(22, BTN_TWEAK)),
		m_kwaziiButton(new Button(30, BTN_KWAZII)),
		m_pesoButton(new Button(26, BTN_PESO)),

		// All button states
		m_listener(0),
		m_buttonStates(0) {

	// Set listeners
	m_octoAlertButton->setListener(this);
	m_octoAlertButton->setListener(this);
	m_countDownButton->setListener(this);
	m_captainBarnaclesButton->setListener(this);
	m_tweakButton->setListener(this);
	m_kwaziiButton->setListener(this);
	m_pesoButton->setListener(this);
}

void InputManager::onNewInputState(uint8_t buttonMask, const bool newState) {
	// Update current values
	if (newState) {
		m_buttonStates |= buttonMask;
		// Ping listener only on button push
		if (m_listener) {
			m_listener->onNewInputState(m_buttonStates);
		}
	} else {
		m_buttonStates &= ~buttonMask;
	}
}

void InputManager::update(unsigned long currentTime) {
	m_octoAlertButton->update(currentTime);
	m_countDownButton->update(currentTime);
	m_captainBarnaclesButton->update(currentTime);
	m_tweakButton->update(currentTime);
	m_kwaziiButton->update(currentTime);
	m_pesoButton->update(currentTime);
}

void InputManager::setListener(InputManagerListener * listener) {
	m_listener = listener;
}
