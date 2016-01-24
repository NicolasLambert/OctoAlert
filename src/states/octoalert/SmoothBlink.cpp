/*
 * SmoothBlink.cpp
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#include "SmoothBlink.h"

SmoothBlink::SmoothBlink(uint32_t color, int8_t ledMask, uint16_t blinkStateChangeCount, uint8_t minBright, uint8_t maxBright)
	: OctoAlertLedAnimation(),
	m_smoothBlinkWay(0),
	m_maxCountDown(blinkStateChangeCount==0?-1:blinkStateChangeCount),
	m_currentCountDown(m_maxCountDown),
	m_currentBrightness(0),
	m_ledMask(ledMask),
	m_minBright(minBright),
	m_maxBright(maxBright)
{
	uint8_t r = (uint8_t) (color >> 16);
	uint8_t g = (uint8_t) (color >> 8);
	uint8_t b = (uint8_t) color;
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
}

void SmoothBlink::activate() {
	m_currentCountDown = m_maxCountDown;
	m_smoothBlinkWay = 1;
	m_currentBrightness = m_minBright;
}

void SmoothBlink::update() {
	if (m_smoothBlinkWay != 0) {
		uint8_t r = m_currentBrightness * m_rFactor / 100;
		uint8_t g = m_currentBrightness * m_gFactor / 100;
		uint8_t b = m_currentBrightness * m_bFactor / 100;
		OutputManager::getInstance()->m_octoAlertLeds->setColor(m_ledMask, r, g, b);
		OutputManager::getInstance()->m_octoAlertLeds->showNewColors();
		m_currentBrightness += m_smoothBlinkWay;
		if (m_currentBrightness <= m_minBright || m_currentBrightness >= m_maxBright) {
			m_smoothBlinkWay *= -1;
			if (m_currentCountDown>0) {
				m_currentCountDown--;
			}
			if (m_currentCountDown==0) {
				// The blinker counter is empty, stop blinking
				m_smoothBlinkWay = 0;
			}
		}
	}
}
