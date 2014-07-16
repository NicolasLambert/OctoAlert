/*
 * DigitalOutput.cpp
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(int const pin, bool const reversed) :
		DigitalIO(pin, reversed), m_lastState(-1) {
	pinMode(m_pin, OUTPUT);
	off();
}

void DigitalOutput::setState(const bool newState) {
	if (((int) newState) != m_lastState) {
		digitalWrite(m_pin, (newState xor m_reversed) ? HIGH : LOW);
		m_lastState = newState;
	}
}

const bool DigitalOutput::getState() {
	return m_lastState;
}

void DigitalOutput::on() {
	setState(true);
}

void DigitalOutput::off() {
	setState(false);
}

void DigitalOutput::toggle() {
	setState(!m_lastState);
}

void DigitalOutput::update(unsigned long currentTime) {
	// Do nothings, some output like Leds will override if necessary
}
