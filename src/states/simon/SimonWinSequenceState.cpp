/*
 * SimonWinSequenceState.cpp
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#include "SimonWinSequenceState.h"

SimonWinSequenceState::SimonWinSequenceState() :
	SoundState(SOUND_SIMON_WINSEQ),
	m_smoothBlinkState(new SmoothBlinkState(COLOR_GREEN, LED_MASK_BIG_RING, 2, 3)) {}

void SimonWinSequenceState::activate() {
	SoundState::activate();
	m_smoothBlinkState->activate();
}

void SimonWinSequenceState::update() {
	SoundState::update();
	m_smoothBlinkState->update();
}

