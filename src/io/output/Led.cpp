/*
 * Led.cpp
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#include "Led.h"

Led::Led(uint8_t const pin) :
		DigitalOutput(pin, false), m_previousBlinkTime(0UL), m_isBlinking(false) {
}

void Led::blink() {
	m_isBlinking = true;
}

void Led::on() {
	DigitalOutput::on();
	m_isBlinking = false;
}

void Led::off() {
	DigitalOutput::off();
	m_isBlinking = false;
}

void Led::update() {
	unsigned long currentTime = millis();
	if (m_isBlinking) {
		if ((currentTime - m_previousBlinkTime) > BLINK_INTERVAL) {
			// save the last time you blinked the LED
			m_previousBlinkTime = currentTime;

			// if the LED is off turn it on and vice-versa:
			toggle();
		}
	}
}
