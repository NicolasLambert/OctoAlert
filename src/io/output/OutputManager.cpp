/*
 * OutputManager.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#include "OutputManager.h"

OutputManager::OutputManager() :
		m_octoAlertLeds(new OctoAlertLeds(44)),
		m_musicPlayer(new MusicPlayer()),
		m_startLed(new Led(48)),
		m_red1Led(new Led(40)),
		m_red2Led(new Led(38)),
		m_red3Led(new Led(36)),
		m_orangeLed(new Led(34)),
		m_greenLed(new Led(24)) {}

void OutputManager::update(unsigned long currentTime) {
	m_octoAlertLeds->update(currentTime);
	m_startLed->update(currentTime);
	m_red1Led->update(currentTime);
	m_red2Led->update(currentTime);
	m_red3Led->update(currentTime);
	m_orangeLed->update(currentTime);
	m_greenLed->update(currentTime);
}
