/*
 * SimonWinGameState.cpp
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#include "SimonWinGameState.h"

SimonWinGameState::SimonWinGameState() :
	SoundState(SOUND_SIMON_WINGAME),
	m_redMask(new RotaryMask(LED_MASK_TOP_RIGHT_QUARTER & ~LED_MASK_CENTER, WAITING_TICKS)),
	m_blueMask(new RotaryMask(LED_MASK_BOTTOM_RIGHT_QUARTER & ~LED_MASK_CENTER, WAITING_TICKS)),
	m_yellowMask(new RotaryMask(LED_MASK_BOTTOM_LEFT_QUARTER & ~LED_MASK_CENTER, WAITING_TICKS)),
	m_greenMask(new RotaryMask(LED_MASK_TOP_LEFT_QUARTER & ~LED_MASK_CENTER, WAITING_TICKS)),
	m_red(COLOR_RED),
	m_blue(COLOR_BLUE),
	m_yellow(COLOR_YELLOW),
	m_green(COLOR_GREEN) {}

void SimonWinGameState::activate() {
	SoundState::activate();
	OutputManager::getInstance()->m_octoAlertLeds->off(LED_MASK_CENTER);
}

void SimonWinGameState::update() {
	SoundState::update();
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_redMask->getValue(), m_red, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_blueMask->getValue(), m_blue, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_yellowMask->getValue(), m_yellow, false);
	OutputManager::getInstance()->m_octoAlertLeds->setColor(m_greenMask->getValue(), m_green, false);
	m_redMask->rotate();
	m_blueMask->rotate();
	m_yellowMask->rotate();
	m_greenMask->rotate();
}
