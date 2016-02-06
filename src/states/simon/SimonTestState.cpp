/*
 * SimonTestState.cpp
 *
 *  Created on: 1 févr. 2016
 *      Author: nicolas
 */

#include "SimonTestState.h"

SimonTestState::SimonTestState(uint8_t correctButtonsStates, SimonPlayState * playState)
	: AbstractState(),
	  m_isWaiting(false),
	  m_isCorrect(false),
	  m_correctButtonsStates(correctButtonsStates),
	  m_playState(playState),
	  m_canBeSqueezed(true)
{}

void SimonTestState::activate() {
	m_isWaiting = true;
}

void SimonTestState::update() {
	if (!m_isWaiting && m_isCorrect) {
		m_playState->update();
	}
}

bool SimonTestState::handleButtonPressed(uint8_t newButtonsStates) {
	if (m_isWaiting) {
		m_isCorrect = (newButtonsStates == m_correctButtonsStates);
		m_isWaiting = false;
		if (m_isCorrect) {
			m_playState->activate();
		}
		return true;
	}
	// Should stay in this state ?
	return m_isWaiting || !m_canBeSqueezed;
}

bool SimonTestState::isCorrect() {
	return m_isCorrect;
}

bool SimonTestState::isFinished() {
	return !m_isWaiting && m_playState->isFinished();
}
