/*
 * OctoAlertLeds.cpp
 *
 *  Created on: 14 juil. 2014
 *      Author: nicolaslambert
 */

#include "OctoAlertLeds.h"

OctoAlertLeds::OctoAlertLeds(uint16_t pin) :
				m_strip(new Adafruit_NeoPixel(41, pin, NEO_GRB + NEO_KHZ800)),
				m_off(Adafruit_NeoPixel::Color(0, 0, 0)) {
	m_strip->begin();
	m_strip->setBrightness(70);
	m_strip->show(); // Initialize all pixels to 'off'
}

void OctoAlertLeds::update() {
	m_strip->show();
}

void OctoAlertLeds::setColor(uint64_t ledMask, uint32_t color, bool switchOffOthers) {
	uint8_t r = (uint8_t) (color >> 16);
	uint8_t g = (uint8_t) (color >> 8);
	uint8_t b = (uint8_t) color;
	setColor(ledMask, r, g, b, switchOffOthers);
}

void OctoAlertLeds::setColor(uint64_t ledMask, uint8_t r, uint8_t g, uint8_t b, bool switchOffOthers) {
	for (uint8_t ledId = 0; ledId < LED_COUNT; ledId++) {
		uint16_t ledPin = idToPinLedMap[ledId];
		if (bitRead(ledMask, LED_COUNT - ledId - 1)) {
			if (ledId==0) {
				// First led (which is in the center) is in RGB mode instead of GRB
				m_strip->setPixelColor(ledPin, g, r, b);
			} else {
				m_strip->setPixelColor(ledPin, r, g, b);
			}
		} else if (switchOffOthers) {
			m_strip->setPixelColor(ledPin, m_off);
		}
	}
}

void OctoAlertLeds::off(uint64_t ledMask) {
	setColor(ledMask, m_off, false);
}
