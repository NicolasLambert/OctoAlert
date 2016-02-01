/*
 * AbstractState.cpp
 *
 *  Created on: 16 juil. 2014
 *      Author: nicolaslambert
 */

#include "AbstractState.h"

AbstractState::AbstractState() {}

void AbstractState::activate() {
	// Stop music and restore stand by led states
	OutputManager::getInstance()->m_musicPlayer->stopPlaying();
	OutputManager::getInstance()->m_octoAlertLeds->off(LED_MASK_ALL);
	OutputManager::getInstance()->m_red1Led->off();
	OutputManager::getInstance()->m_red2Led->off();
	OutputManager::getInstance()->m_red3Led->off();
	OutputManager::getInstance()->m_orangeLed->off();
	OutputManager::getInstance()->m_greenLed->off();
	OutputManager::getInstance()->m_startLed->on();
}

void AbstractState::update() {
	// Do nothing, update is not always necessary in states
}

bool AbstractState::handleButtonPressed(uint8_t newButtonsStates) {
	// Default implementation : a button pressed is a state changing
	return false;
}

