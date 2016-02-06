/*
 * SimonState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "SimonState.h"

SimonState::SimonState() :
		AbstractStateManager(),
		m_lastScoreStep(0),
		m_lastSuccessfullScoreStep(-1),
		m_introState(new SimonIntroState()),
		m_winSequenceState(new SimonWinSequenceState()),
		m_failState(new SimonFailState()),
		m_winGameState(new SimonWinGameState()),
		m_playStates({
			new SimonPlayState(COLOR_RED,    LED_MASK_TOP_RIGHT_QUARTER, 1),
			new SimonPlayState(COLOR_BLUE,   LED_MASK_BOTTOM_RIGHT_QUARTER, 2),
			new SimonPlayState(COLOR_YELLOW, LED_MASK_BOTTOM_LEFT_QUARTER, 3),
			new SimonPlayState(COLOR_GREEN,  LED_MASK_TOP_LEFT_QUARTER, 4)}),
		m_testStates({
			new SimonTestState(BTN_TWEAK, m_playStates[0]),
			new SimonTestState(BTN_PESO, m_playStates[1]),
			new SimonTestState(BTN_KWAZII, m_playStates[2]),
			new SimonTestState(BTN_CPTBARNAC, m_playStates[3])})
		{
	// Analog input pin 0 is unconnected, random analog
	// noise will cause the call to randomSeed() to generate
	// different seed numbers each time the sketch runs.
	// randomSeed() will then shuffle the random function.
	randomSeed(analogRead(0));
}

void SimonState::activate() {
	// Reset index
	m_lastScoreStep = -1;
	m_lastSuccessfullScoreStep = -1;

	generateMusicScore();

	// Go first state
	AbstractStateManager::activate();
}

void SimonState::generateMusicScore() {
	// Generate new music score
	for (uint8_t i = 0; i < STEP_TO_WIN_COUNT; i++) {
		m_musicScore[i] = random(4);
	}
}

bool SimonState::handleButtonPressed(uint8_t newButtonsStates) {
	bool isOnlyOneButtonPressed = (__builtin_popcount(newButtonsStates) == 1);
	bool isSimonGameButtonPressed = (newButtonsStates & (BTN_CPTBARNAC | BTN_TWEAK | BTN_KWAZII | BTN_PESO));
	if (isOnlyOneButtonPressed && isSimonGameButtonPressed) {
		bool shouldStayInCurrentState = AbstractStateManager::handleButtonPressed(newButtonsStates);
		// Make it possible to swueeze test sound/anim to increase game speed
		if (isTestState(m_currentState) && !shouldStayInCurrentState) {
			changeState(getNextState(m_currentState));
			m_currentState->handleButtonPressed(newButtonsStates);
		}
		return true;
	}
	return false;
}

bool SimonState::isFinished() {
	return m_currentState == m_winGameState && m_winGameState->isFinished();
}

AbstractState * SimonState::getNextState(AbstractState * currentState) {
	// No state
	if (currentState == nullptr) {
		return m_introState;
	}

	// Intro state
	if (currentState == m_introState) {
		return getNextPlayState();
	}

	// Play state
	if (isPlayState(currentState)) {
		if (m_lastScoreStep == m_lastSuccessfullScoreStep + 1) {
			// Reset score index
			m_lastScoreStep = -1;
			return getNextTestState();
		} else {
			return getNextPlayState();
		}
	}

	// Test state
	if (isTestState(currentState)) {
		SimonTestState* sts = (SimonTestState*)currentState;
		if (sts->isCorrect()) {
			if (m_lastScoreStep == m_lastSuccessfullScoreStep + 1) {
				if (m_lastSuccessfullScoreStep + 2 == STEP_TO_WIN_COUNT) {
					return m_winGameState;
				} else {
					return m_winSequenceState;
				}
			} else {
				return getNextTestState();
			}
		} else {
			return m_failState;
		}
	}

	// Fail state
	if (currentState == m_failState) {
		// Reset score index
		m_lastScoreStep = -1;
		// Reset user score
		m_lastSuccessfullScoreStep = -1;
		return getNextPlayState();
	}

	// Win sequence state
	if (currentState == m_winSequenceState) {
		// The user just reproduce the shown sequence, let's write that
		m_lastSuccessfullScoreStep++;
		// Reset score index
		m_lastScoreStep = -1;
		return getNextPlayState();
	}

	// Should be Win game state
	// Should not be called in this state, just return itself to be sure
	return m_winGameState;
}

bool SimonState::isTestState(AbstractState * state) {
	for (int i=0; i<4;i++) {
		if (m_testStates[i]==state) {
			return true;
		}
	}
    return false;
}

bool SimonState::isPlayState(AbstractState * state) {
	for (int i=0; i<4;i++) {
		if (m_playStates[i]==state) {
			return true;
		}
	}
    return false;
}

SimonPlayState * SimonState::getNextPlayState() {
	// Play next note
	m_lastScoreStep++;
	return m_playStates[m_musicScore[m_lastScoreStep]];;
}

SimonTestState * SimonState::getNextTestState() {
	// Go next test
	m_lastScoreStep++;
	SimonTestState * nextState = m_testStates[m_musicScore[m_lastScoreStep]];
	nextState->m_canBeSqueezed = (m_lastScoreStep < m_lastSuccessfullScoreStep + 1);
	return nextState;
}

