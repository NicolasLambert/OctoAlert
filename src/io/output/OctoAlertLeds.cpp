/*
 * OctoAlertLeds.cpp
 *
 *  Created on: 14 juil. 2014
 *      Author: nicolaslambert
 */

#include "OctoAlertLeds.h"

OctoAlertLeds::OctoAlertLeds(uint16_t pin) :
				m_strip(new Adafruit_NeoPixel(41, pin, NEO_GRB + NEO_KHZ800)),
				m_smoothBlinkWay(0),
				m_blinkStateChangeCountDown(-1),
				m_currentBrightness(0),
				m_quarterId(-1),
				m_rFactor(100),
				m_gFactor(100),
				m_bFactor(100),
				m_minBright(MIN_BRIGHT_BLINK),
				m_maxBright(MAX_BRIGHT_BLINK),
				off(Adafruit_NeoPixel::Color(0, 0, 0)),
				introColor(Adafruit_NeoPixel::Color(0, 0, 255)),
				winColor(Adafruit_NeoPixel::Color(0, 255, 0)),
				failColor(Adafruit_NeoPixel::Color(255, 0, 0)) {
	m_strip->begin();
	m_strip->setBrightness(70);
	m_strip->show(); // Initialize all pixels to 'off'
}

void OctoAlertLeds::colorAll(uint32_t color) {
	m_smoothBlinkWay = 0;
	m_quarterId = -1;
	internalColorAll(color);
}

void OctoAlertLeds::offAll() {
	colorAll(off);
}

bool OctoAlertLeds::isInQuarter(uint8_t ledId) {
	switch (m_quarterId) {
	case TOP_RIGHT_QUARTER:
		return (ledId>=15 && ledId<=20) || (ledId>=26 && ledId<= 29);
	case BOTTOM_RIGHT_QUARTER:
		return (ledId>=0 && ledId<=2) || (ledId>=21 && ledId<=25) || (ledId>=38 && ledId<= 39);
	case BOTTOM_LEFT_QUARTER:
		return (ledId>=3 && ledId<=8) || (ledId>=34 && ledId<= 37);
	case TOP_LEFT_QUARTER:
		return (ledId>=9 && ledId<=14) || (ledId>=30 && ledId<= 33);
	case ALL_QUARTER:
		return true;
	}
	return false;
}

void OctoAlertLeds::smoothBlink(uint32_t color, int8_t quarterId, uint16_t blinkStateChangeCount, uint8_t minBright, uint8_t maxBright) {
	m_blinkStateChangeCountDown = (blinkStateChangeCount==0?-1:blinkStateChangeCount);
	m_quarterId = quarterId;
	m_minBright = minBright;
	m_maxBright = maxBright;
	uint8_t r = (uint8_t) (color >> 16);
	uint8_t g = (uint8_t) (color >> 8);
	uint8_t b = (uint8_t) color;
	internalSmoothBlink(r, g, b);
}

void OctoAlertLeds::internalSmoothBlink(uint8_t r, uint8_t g, uint8_t b) {
	uint8_t maxSmooth = max(max(r, g), b);
	if (maxSmooth == 0) {
		m_rFactor = 100;
		m_gFactor = 100;
		m_bFactor = 100;
	} else if (r == maxSmooth) {
		m_rFactor = 100;
		m_gFactor = g * 100 / r;
		m_bFactor = b * 100 / r;
	} else if (g == maxSmooth) {
		m_rFactor = r * 100 / g;
		m_gFactor = 100;
		m_bFactor = b * 100 / g;
	} else {
		m_rFactor = r * 100 / b;
		m_gFactor = g * 100 / b;
		m_bFactor = 100;
	}
	m_smoothBlinkWay = 1;
	m_currentBrightness = m_minBright;
}

void OctoAlertLeds::update() {
	if (m_smoothBlinkWay != 0) {
		uint8_t r = m_currentBrightness * m_rFactor / 100;
		uint8_t g = m_currentBrightness * m_gFactor / 100;
		uint8_t b = m_currentBrightness * m_bFactor / 100;
		internalColorAll(r, g, b);
		m_currentBrightness += m_smoothBlinkWay;
		if (m_currentBrightness <= m_minBright || m_currentBrightness >= m_maxBright) {
			m_smoothBlinkWay *= -1;
			m_blinkStateChangeCountDown--;
			if (m_blinkStateChangeCountDown==0) {
				// The blinker counter is empty, stop blinking
				m_smoothBlinkWay = 0;
			}
		}
	}
}

void OctoAlertLeds::internalColorAll(uint32_t color) {
	uint8_t r = (uint8_t) (color >> 16);
	uint8_t g = (uint8_t) (color >> 8);
	uint8_t b = (uint8_t) color;
	internalColorAll(r, g, b);
}

void OctoAlertLeds::internalColorAll(uint8_t r, uint8_t g, uint8_t b ) {
	uint8_t lastIndex = m_strip->numPixels() - 1;
	for (uint16_t i = 0; i < lastIndex; i++) {
		if (isInQuarter(i)) {
			m_strip->setPixelColor(i, r, g, b);
		} else {
			m_strip->setPixelColor(i, off);
		}
	}
	// last Led (which is in the center) is in RGB mode instead of GRB
	if (isInQuarter(lastIndex)) {
		m_strip->setPixelColor(lastIndex, g, r, b);
	} else {
		m_strip->setPixelColor(lastIndex, off);
	}
	m_strip->show();
}

void OctoAlertLeds::introAnimation() {
	smoothBlink(introColor, ALL_QUARTER, 2);
}

void OctoAlertLeds::winSeqAnimation() {
	smoothBlink(winColor, ALL_QUARTER, 2);
}

void OctoAlertLeds::failAnimation() {
	smoothBlink(failColor, ALL_QUARTER, 2);
}

void OctoAlertLeds::winGameAnimation() {
	smoothBlink(winColor, ALL_QUARTER, 2);
}

