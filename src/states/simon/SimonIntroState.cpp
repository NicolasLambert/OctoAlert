/*
 * SimonIntroState.cpp
 *
 *  Created on: 1 févr. 2016
 *      Author: nicolas
 */

#include "SimonIntroState.h"

SimonIntroState::SimonIntroState() :
	RadarState(LED_MASK_ALL & ~LED_MASK_TOP_RIGHT_QUARTER, 2, 0),
	m_soundState(new SoundState(SOUND_SIMON_INTRO)),
	m_red(COLOR_RED),
	m_blue(COLOR_BLUE),
	m_yellow(COLOR_YELLOW),
	m_green(COLOR_GREEN),
	m_white(COLOR_WHITE) {}

void SimonIntroState::activate() {
	RadarState::activate();
	m_soundState->activate();
}

void SimonIntroState::update() {
	RadarState::update();
	m_soundState->update();
}

bool SimonIntroState::isFinished() {
	return m_soundState->isFinished();
}

void SimonIntroState::setColors() {
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_TOP_RIGHT_QUARTER, m_red, true);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_BOTTOM_RIGHT_QUARTER, m_blue, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_BOTTOM_LEFT_QUARTER, m_yellow, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_TOP_LEFT_QUARTER, m_green, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_CENTER, m_white, false);
}
