/*
 * SimonFailState.cpp
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#include "SimonFailState.h"

SimonFailState::SimonFailState() :
	SoundState(SOUND_SIMON_FAIL),
	m_smoothBlinkState(new SmoothBlinkState(COLOR_RED, LED_MASK_CROSS, 2, 3)) {}

void SimonFailState::activate() {
	SoundState::activate();
	m_smoothBlinkState->activate();
}

void SimonFailState::update() {
	SoundState::update();
	m_smoothBlinkState->update();
}
