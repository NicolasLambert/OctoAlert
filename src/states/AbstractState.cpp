/*
 * AbstractState.cpp
 *
 *  Created on: 16 juil. 2014
 *      Author: nicolaslambert
 */

#include "AbstractState.h"

AbstractState::AbstractState() {}

void AbstractState::update() {
	// Do nothing, update is not always necessary in states
}

bool AbstractState::handleButtonPressed(uint8_t newButtonsStates) {
	// Default implementation : a button pressed is a state changing
	return false;
}

