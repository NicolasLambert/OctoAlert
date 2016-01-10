/*
 * IOManager.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#include "IOManager.h"

IOManager::IOManager() :
		InputListener(),
		//----------------------------------------------------------------------------------------------------
		// Outputs
		m_octoAlertLeds(new OctoAlertLeds(44)),
		m_musicPlayer(new MusicPlayer()),
		m_startLed(new Led(48)),
		m_red1Led(new Led(40)),
		m_red2Led(new Led(38)),
		m_red3Led(new Led(36)),
		m_orangeLed(new Led(34)),
		m_greenLed(new Led(24)),

		//----------------------------------------------------------------------------------------------------
		// Inputs
		m_octoAlertButton(new Button(42, BTN_OCTOALERT)),
		m_countDownButton(new Button(46, BTN_COUNTDOWN)),
		m_captainBarnaclesButton(new Button(28, BTN_CPTBARNAC)),
		m_tweakButton(new Button(22, BTN_TWEAK)),
		m_kwaziiButton(new Button(30, BTN_KWAZII)),
		m_pesoButton(new Button(26, BTN_PESO)),

		// All button states
		m_listener(0),
		m_buttonStates(0) {

	// Set listeners
	m_octoAlertButton->setListener(this);
	m_octoAlertButton->setListener(this);
	m_countDownButton->setListener(this);
	m_captainBarnaclesButton->setListener(this);
	m_tweakButton->setListener(this);
	m_kwaziiButton->setListener(this);
	m_pesoButton->setListener(this);
}

void IOManager::onNewInputState(uint8_t buttonMask, const bool newState) {
	// Update current values
	if (newState) {
		m_buttonStates |= buttonMask;
		// Ping listener only on button push
		if (m_listener) {
			m_listener->onNewInputState(m_buttonStates);
		}
	} else {
		m_buttonStates &= ~buttonMask;
	}
}

void IOManager::update(unsigned long currentTime) {
	// Outputs
	m_octoAlertLeds->update(currentTime);
	m_startLed->update(currentTime);

	// Inputs
	m_octoAlertButton->update(currentTime);
	m_countDownButton->update(currentTime);
	m_captainBarnaclesButton->update(currentTime);
	m_tweakButton->update(currentTime);
	m_kwaziiButton->update(currentTime);
	m_pesoButton->update(currentTime);
}

void IOManager::setListener(InputManagerListener * listener) {
	m_listener = listener;
}
