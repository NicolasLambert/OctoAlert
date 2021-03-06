/*
 * AbstractStateManager.cpp
 *
 *  Created on: 1 févr. 2016
 *      Author: nicolas
 */

#include "AbstractStateManager.h"

AbstractStateManager::AbstractStateManager() : m_currentState(nullptr) {}

void AbstractStateManager::activate() {
	m_currentState = nullptr;
}

void AbstractStateManager::update() {
	if (m_currentState==nullptr || m_currentState->isFinished()) {
		changeState(getNextState(m_currentState));
	}
	m_currentState->update();
}

void AbstractStateManager::changeState(AbstractState* newState) {
	m_currentState = newState;
	newState->activate();
}

bool AbstractStateManager::handleButtonPressed(uint8_t newButtonsStates) {
	if (m_currentState) {
		return m_currentState->handleButtonPressed(newButtonsStates);
	}
	return false;
}
