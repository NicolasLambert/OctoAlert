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
		m_lastStep(0),
		m_lastStepTime(0) {
	// Analog input pin 0 is unconnected, random analog
	// noise will cause the call to randomSeed() to generate
	// different seed numbers each time the sketch runs.
	// randomSeed() will then shuffle the random function.
	randomSeed(analogRead(0));
}

void SimonState::activate() {
	// TODO: play some animation to start the game
	generateMusicScore();
}

void SimonState::generateMusicScore() {
	// Reset index
	m_lastStep = 0;

	// Generate new music score
	for(int i=0;i<STEP_COUNT;i++) {
		m_musicScore[i] = random(4);
	}
}

void SimonState::colorQuarter(int quarterId) {
	// Select the right sound track
	SoundState::m_lastIndex = quarterId;
	// Play sound
	SoundState::activate();
	// Light quarter
	OutputManager::getInstance()->m_octoAlertLeds->colorQuarter(quarterId, m_colors[quarterId]);
}

void SimonState::update() {
	AbstractState::update();
	unsigned long currentTime = millis();
	if (currentTime - m_lastStepTime > SOUND_DURATION) {
		OutputManager::getInstance()->m_musicPlayer->stopPlaying();
		OutputManager::getInstance()->m_octoAlertLeds->offAll();
	}
	if (currentTime - m_lastStepTime > STEP_INTERVAL && m_lastStep<STEP_COUNT) {
		m_lastStepTime = currentTime;
		colorQuarter(m_musicScore[m_lastStep]);
		m_lastStep++;
	}
}

bool SimonState::shouldStayInThisState(uint8_t newButtonsStates) {
	return	(__builtin_popcount(newButtonsStates) == 1) &&// One button pressed only
			(newButtonsStates & (BTN_CPTBARNAC | BTN_TWEAK | BTN_KWAZII | BTN_PESO)); // Button from simon games
}

bool SimonState::isFinished() {
	return m_lastStep >= STEP_COUNT;
}
