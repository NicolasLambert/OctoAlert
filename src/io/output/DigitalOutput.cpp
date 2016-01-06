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

bool const DigitalOutput::getState() {
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
