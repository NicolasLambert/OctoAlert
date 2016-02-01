/*
 * StandByState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "StandByState.h"

StandByState::StandByState() : AbstractState(), m_blue(Adafruit_NeoPixel::Color(0, 40, 33)) {}

void StandByState::activate() {
	AbstractState::activate();
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_ALL, m_blue);
}

bool StandByState::isFinished() {
	return false;
}
