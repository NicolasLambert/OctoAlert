/*
 * StandByState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "StandByState.h"

StandByState::StandByState() : AbstractState(), m_blue(Adafruit_NeoPixel::Color(0, 40, 33)) {}

void StandByState::activate() {
	OutputManager::getInstance()->m_octoAlertLeds->colorAll(m_blue);
	OutputManager::getInstance()->m_red1Led->off();
	OutputManager::getInstance()->m_red2Led->off();
	OutputManager::getInstance()->m_red3Led->off();
	OutputManager::getInstance()->m_orangeLed->off();
	OutputManager::getInstance()->m_greenLed->off();
	OutputManager::getInstance()->m_startLed->on();
}

bool StandByState::isFinished() {
	return false;
}
