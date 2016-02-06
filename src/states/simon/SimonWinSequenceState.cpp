/*
 * SimonWinSequenceState.cpp
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#include "SimonWinSequenceState.h"

SimonWinSequenceState::SimonWinSequenceState() : SoundState(SOUND_SIMON_WINSEQ) {}

void SimonWinSequenceState::activate() {
	SoundState::activate();
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_ALL, 0, 255, 0);
}

void SimonWinSequenceState::update() {
	SoundState::update();
}

