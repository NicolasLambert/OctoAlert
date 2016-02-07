/*
 * SimonPlayState.cpp
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#include "SimonPlayState.h"

SimonPlayState::SimonPlayState(uint32_t color, int64_t ledMask, uint8_t soundIndex) :
	SoundState(SOUND_SIMON_PLAY),
	m_explodeState(new ExplodeState(color, ledMask & ~LED_MASK_CENTER, 1)),
	m_soundIndex(soundIndex) {}

void SimonPlayState::activate() {
	m_lastIndex = m_soundIndex;
	SoundState::activate();
	m_explodeState->activate();
}

void SimonPlayState::update() {
	SoundState::update();
	m_explodeState->update();
}

bool SimonPlayState::isFinished() {
	return SoundState::isFinished() && m_explodeState->isFinished();
}
