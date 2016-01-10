/*
 * DigitalInput.cpp
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#include "DigitalInput.h"

DigitalInput::DigitalInput(int const pin, bool const reversed) :
		DigitalIO(pin, reversed) {
	pinMode(pin, INPUT_PULLUP);
}

bool const DigitalInput::getState() {
	return (m_reversed xor digitalRead(m_pin));
}
