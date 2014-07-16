/*
 * StandByState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "StandByState.h"

StandByState::StandByState() :
		AbstractState() {
}

void StandByState::activate() {
	IOManager::getInstance()->m_musicPlayer->stopPlaying();
	OctoAlertLeds* const octoAlertLeds = IOManager::getInstance()->m_octoAlertLeds;
	octoAlertLeds->colorAll(Adafruit_NeoPixel::Color(0, 40, 33)); // Blue
	IOManager::getInstance()->m_red1Led->off();
	IOManager::getInstance()->m_red2Led->off();
	IOManager::getInstance()->m_red3Led->off();
	IOManager::getInstance()->m_orangeLed->off();
	IOManager::getInstance()->m_greenLed->off();
	IOManager::getInstance()->m_startLed->on();
}
