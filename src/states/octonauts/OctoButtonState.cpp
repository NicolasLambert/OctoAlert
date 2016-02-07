/*
 * OctoButtonState.cpp
 *
 *  Created on: 7 févr. 2016
 *      Author: nicolas
 */

#include "../octonauts/OctoButtonState.h"

OctoButtonState::OctoButtonState(uint32_t color, char const * const mp3Path) :
	SoundState(mp3Path),
	m_explodeState(new ExplodeState(color)) {}

void OctoButtonState::activate() {
	SoundState::activate();
	m_explodeState->activate();
}

void OctoButtonState::update() {
	SoundState::update();
	m_explodeState->update();
}
