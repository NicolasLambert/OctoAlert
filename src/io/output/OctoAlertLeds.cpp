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
				m_currentBrightness(0),
				m_rFactor(100),
				m_gFactor(100),
				m_bFactor(100),
				off(Adafruit_NeoPixel::Color(0, 0, 0)) {
	m_strip->begin();
	m_strip->setBrightness(70);
	m_strip->show(); // Initialize all pixels to 'off'
}

void OctoAlertLeds::colorAll(uint32_t color) {
	m_smoothBlinkWay = 0;
	internalColorAll(color);
}

void OctoAlertLeds::offAll() {
	colorAll(off);
}

void OctoAlertLeds::colorQuarter(int quarterId, uint32_t color) {
	m_smoothBlinkWay = 0;
	for (uint16_t i = 0; i < m_strip->numPixels(); i++) {
		if (isInQuarter(quarterId, i)) {
			m_strip->setPixelColor(i, color);
		} else {
			m_strip->setPixelColor(i, off);
		}
	}
	m_strip->show();
}

bool OctoAlertLeds::isInQuarter(int quarterId, int ledId) {
	switch (quarterId) {
	case TOP_RIGHT_QUARTER:
		return (ledId>=15 && ledId<=20) || (ledId>=26 && ledId<= 29);
	case BOTTOM_RIGHT_QUARTER:
		return (ledId>=0 && ledId<=2) || (ledId>=21 && ledId<=25) || (ledId>=38 && ledId<= 39);
	case BOTTOM_LEFT_QUARTER:
		return (ledId>=3 && ledId<=8) || (ledId>=34 && ledId<= 37);
	case TOP_LEFT_QUARTER:
		return (ledId>=9 && ledId<=14) || (ledId>=30 && ledId<= 33);
	}
	return false;
}

void OctoAlertLeds::smoothBlink(uint32_t color) {
	uint8_t r = (uint8_t) (color >> 16);
	uint8_t g = (uint8_t) (color >> 8);
	uint8_t b = (uint8_t) color;
	smoothBlink(r, g, b);
}

void OctoAlertLeds::smoothBlink(int r, int g, int b) {
	int maxSmooth = max(max(r, g), b);
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
	m_smoothBlinkWay = -1;
	m_currentBrightness = MAX_BRIGHT_BLINK;
}

void OctoAlertLeds::update() {
	if (m_smoothBlinkWay != 0) {
		int r = m_currentBrightness * m_rFactor / 100;
		int g = m_currentBrightness * m_gFactor / 100;
		int b = m_currentBrightness * m_bFactor / 100;
		internalColorAll(r, g, b);
		m_currentBrightness += m_smoothBlinkWay;
		if (m_currentBrightness <= MIN_BRIGHT_BLINK || m_currentBrightness >= MAX_BRIGHT_BLINK) {
			m_smoothBlinkWay *= -1;
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
	int lastIndex = m_strip->numPixels() - 1;
	for (uint16_t i = 0; i < lastIndex; i++) {
		m_strip->setPixelColor(i, r, g, b);
	}
	// last Led (which is in the center) is in RGB mode instead of GRB
	m_strip->setPixelColor(lastIndex, g, r, b);
	m_strip->show();
}
