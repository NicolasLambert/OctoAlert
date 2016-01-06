/*
 * OctoStateManager.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "OctoStateManager.h"

//#define PRINT_DEBUG_MSGS

OctoStateManager::OctoStateManager() :

		// States
		m_standByState(new StandByState()),
		m_octoAlertState(new OctoAlertState("Alert")),
		m_captainBarnaclesState(new SoundState("Captain")),
		m_tweakState(new SoundState("Tweak")),
		m_kwaziiState(new SoundState("Kwazii")),
		m_pesoState(new SoundState("Peso")),
		m_countDownState(new CountDownState("CntDown")),
		m_simonState(new SimonState("Simon"))

{
	// Set listeners
	IOManager::getInstance()->m_octoAlertButton->setListener(&OctoStateManager::octoAlertPressed);
	IOManager::getInstance()->m_countDownButton->setListener(&OctoStateManager::countDownPressed);
	IOManager::getInstance()->m_captainBarnaclesButton->setListener(&OctoStateManager::captainBarnaclesPressed);
	IOManager::getInstance()->m_tweakButton->setListener(&OctoStateManager::tweakPressed);
	IOManager::getInstance()->m_kwaziiButton->setListener(&OctoStateManager::kwaziiPressed);
	IOManager::getInstance()->m_pesoButton->setListener(&OctoStateManager::pesoPressed);

	// Initial state
	changeState(m_standByState);
}

void OctoStateManager::octoAlertPressed(const bool oldState, const bool newState) {
	if (newState) {
		getInstance()->changeState(getInstance()->m_octoAlertState);
	}
}

void OctoStateManager::captainBarnaclesPressed(const bool oldState, const bool newState) {
	if (newState && getInstance()->m_currentState!=getInstance()->m_simonState) {
		getInstance()->changeState(getInstance()->m_captainBarnaclesState);
	}
}

void OctoStateManager::tweakPressed(const bool oldState, const bool newState) {
	if (newState && getInstance()->m_currentState!=getInstance()->m_simonState) {
		getInstance()->changeState(getInstance()->m_tweakState);
	}
}

void OctoStateManager::kwaziiPressed(const bool oldState, const bool newState) {
	if (newState && getInstance()->m_currentState!=getInstance()->m_simonState) {
		getInstance()->changeState(getInstance()->m_kwaziiState);
	}
}

void OctoStateManager::pesoPressed(const bool oldState, const bool newState) {
	if (newState && getInstance()->m_currentState!=getInstance()->m_simonState) {
		getInstance()->changeState(getInstance()->m_pesoState);
	}
}

void OctoStateManager::countDownPressed(const bool oldState, const bool newState) {
	if (newState) {
		getInstance()->changeState(getInstance()->m_countDownState);
	}
}

void OctoStateManager::update(unsigned long currentTime) {
	IOManager::getInstance()->update(currentTime);
	AbstractState* nextState = m_currentState->getNextState();
	if (nextState != m_currentState) {
		changeState(nextState);
		// We recompute millis instead of use the currentTime because the stop/play delay is too long
		currentTime = millis();
	}

	// Update count down procedure
	m_currentState->update(currentTime);
}

void OctoStateManager::changeState(AbstractState* newState) {
	if (IOManager::getInstance()->m_pesoButton->getState() && IOManager::getInstance()->m_kwaziiButton->getState()) {
		// If Kwasii and Peso button are pressed at the same time, go to simon mode !
		newState = m_simonState;
	}
	m_currentState = newState;
	if (m_standByState != newState) {
		// Stop music and restore stand by led states
		m_standByState->activate();
	}
	newState->activate();
}
