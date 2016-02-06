/*
 * SimonWinGameState.cpp
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#include "SimonWinGameState.h"

SimonWinGameState::SimonWinGameState() : SoundState(SOUND_SIMON_WINGAME) {}

void SimonWinGameState::activate() {
	SoundState::activate();
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_ALL, 0, 255, 0);
}

void SimonWinGameState::update() {
	SoundState::update();
}
