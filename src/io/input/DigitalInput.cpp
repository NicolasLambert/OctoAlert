/*
 * DigitalInput.cpp
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#include "DigitalInput.h"

DigitalInput::DigitalInput(int const pin, bool const reversed, unsigned int debounceDelay) :
		DigitalIO(pin, reversed), m_listener(0), m_debounceDelay(debounceDelay) {
	pinMode(pin, INPUT_PULLUP);
	m_lastChangeTime = millis();
	m_currentState = m_lastState = getState();
}

bool const DigitalInput::getState() {
	return (m_reversed xor digitalRead(m_pin));
}

void DigitalInput::setListener(InputChangeListener listener) {
	m_listener = listener;
}

void DigitalInput::update(unsigned long currentTime) {
	// Get current state
	bool newState = getState();

	// If the switch changed, due to noise or pressing:
	if (newState != m_lastState) {
		// reset the debouncing timer
		m_lastChangeTime = currentTime;
	}

	if ((newState != m_currentState) && ((currentTime - m_lastChangeTime) > m_debounceDelay)) {
		// whatever the reading is at, it's been there for longer
		// than the debounce delay, so take it as the actual current state:
		bool oldState = m_currentState;
		m_currentState = newState;
		// Ping listener
		if (m_listener) {
			(*m_listener)(oldState, newState);
		}
	}

	// Save last state
	m_lastState = newState;
}
