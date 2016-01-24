/*
 * SimonState.cpp
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#include "SimonState.h"

SimonState::SimonState(char const * const mp3Path) :
		SoundState(mp3Path),
		m_colors({
			Adafruit_NeoPixel::Color(255, 0, 0),
			Adafruit_NeoPixel::Color(0, 0, 255),
			Adafruit_NeoPixel::Color(255, 255, 0),
			Adafruit_NeoPixel::Color(0, 255, 0)}),
		m_buttonByQuarter({BTN_TWEAK, BTN_PESO, BTN_KWAZII, BTN_CPTBARNAC}),
		m_nextScoreStep(0),
		m_lastSuccessfullScoreStep(0),
		m_lastScoreStepTime(0),
		m_currentState(STATE_INTRO) {
	// Analog input pin 0 is unconnected, random analog
	// noise will cause the call to randomSeed() to generate
	// different seed numbers each time the sketch runs.
	// randomSeed() will then shuffle the random function.
	randomSeed(analogRead(0));
}

void SimonState::activate() {
	m_lastScoreStepTime = 0;
	switchState(STATE_INTRO);
}

void SimonState::generateMusicScore() {
	// Reset index
	m_lastSuccessfullScoreStep = 0;
	m_lastScoreStepTime = 0;

	// Generate new music score
	for(uint8_t i=0;i<STEP_TO_WIN_COUNT;i++) {
		m_musicScore[i]  = random(4);
	}
}

void SimonState::update() {
	AbstractState::update();
	if (isDelayPassed(STEP_INTERVAL)) {
		switch (m_currentState) {
		case STATE_INTRO:
			generateMusicScore();
			play(SOUND_ID_INTRO);
			OutputManager::getInstance()->m_octoAlertLeds->introAnimation();
			switchState(STATE_PLAY);
			break;
		case STATE_PLAY:
			playOneNote();
			if (m_nextScoreStep > m_lastSuccessfullScoreStep) {
				switchState(STATE_TEST);
			}
			break;
		case STATE_TEST:
			// Do nothing, just wait for button press
			break;
		case STATE_WIN_SEQ:
			play(SOUND_ID_WIN_SEQ);
			OutputManager::getInstance()->m_octoAlertLeds->winSeqAnimation();
			switchState(STATE_PLAY);
			break;
		case STATE_FAIL:
			play(SOUND_ID_FAIL);
			OutputManager::getInstance()->m_octoAlertLeds->failAnimation();
			switchState(STATE_PLAY);
			break;
		case STATE_WIN_GAME:
			play(SOUND_ID_WIN_GAME);
			OutputManager::getInstance()->m_octoAlertLeds->winGameAnimation();
			switchState(STATE_END);
			break;
		case STATE_END:
			// Do nothing, the state will go back to stand by at the next update
			break;
		}
	}
}

void SimonState::playOneNote() {
	uint8_t quarterId = m_musicScore[m_nextScoreStep];
	OutputManager::getInstance()->m_octoAlertLeds->smoothBlink(m_colors[quarterId], quarterId, 2);
	play(quarterId);
	m_nextScoreStep++;
}

void SimonState::play(uint8_t soundId) {
	m_lastScoreStepTime = millis();
	// Select the right sound track
	SoundState::m_lastIndex = soundId;
	// Play sound
	OutputManager::getInstance()->m_musicPlayer->stopPlaying();
	SoundState::activate();
}


void SimonState::switchState(uint8_t newState) {
	m_currentState = newState;
	m_nextScoreStep = 0;
}

bool SimonState::isDelayPassed(uint16_t delay) {
	return (millis() > (delay + m_lastScoreStepTime));
}

bool SimonState::handleButtonPressed(uint8_t newButtonsStates) {
	bool isOnlyOneButtonPressed = (__builtin_popcount(newButtonsStates) == 1);
	bool isSimonGameButtonPressed = (newButtonsStates & (BTN_CPTBARNAC | BTN_TWEAK | BTN_KWAZII | BTN_PESO));
	if (isOnlyOneButtonPressed && isSimonGameButtonPressed) {
		// Are we listening to simon button press ?
		if (m_currentState==STATE_TEST) {
			uint8_t correctQuarter = m_musicScore[m_nextScoreStep];
			uint8_t correctButton = m_buttonByQuarter[correctQuarter];
			// It is the correct button ?
			if (correctButton==newButtonsStates) {
				// So lets start over the same music store with one more note
				bool isSequenceSuccessfull = m_nextScoreStep==m_lastSuccessfullScoreStep;
				playOneNote();
				if (m_lastSuccessfullScoreStep >= STEP_TO_WIN_COUNT) {
					switchState(STATE_WIN_GAME);
				} else if (isSequenceSuccessfull) {
					switchState(STATE_WIN_SEQ);
					m_lastSuccessfullScoreStep++;
				}
			} else {
				m_lastScoreStepTime = 0;
				switchState(STATE_FAIL);
			}
		}
		// Return true to stay in this state
		return true;
	}
	return false;
}

bool SimonState::isFinished() {
	return m_currentState == STATE_END;
}

