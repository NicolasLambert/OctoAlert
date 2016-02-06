/*
 * SimonFailState.cpp
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#include "SimonFailState.h"

SimonFailState::SimonFailState() : SoundState(SOUND_SIMON_FAIL) {}

void SimonFailState::activate() {
	SoundState::activate();
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_ALL, 255, 0, 0);
}

void SimonFailState::update() {
	SoundState::update();
}
