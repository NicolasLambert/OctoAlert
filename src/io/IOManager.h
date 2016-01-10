/*
 * IOManager.h
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#ifndef IOMANAGER_H_
#define IOMANAGER_H_

#include <SPI.h>
#include <SD.h>
#include "../AbstractManager.h"
#include "input/Button.h"
#include "input/InputListener.h"
#include "output/Led.h"
#include "output/OctoAlertLeds.h"
#include "output/MusicPlayer.h"
#include "input/InputManagerListener.h"

#define BTN_OCTOALERT 1
#define BTN_COUNTDOWN 2
#define BTN_CPTBARNAC 4
#define BTN_TWEAK     8
#define BTN_KWAZII    16
#define BTN_PESO      32

class IOManager: public AbstractManager<IOManager>, public InputListener {
public:
	IOManager();
	void setListener(InputManagerListener * listener);
	void update(unsigned long currentTime);

	//----------------------------------------------------------------------------------------------------
	// Outputs
	OctoAlertLeds * const m_octoAlertLeds;
	MusicPlayer * const m_musicPlayer;
	Led * const m_startLed;
	Led * const m_red1Led;
	Led * const m_red2Led;
	Led * const m_red3Led;
	Led * const m_orangeLed;
	Led * const m_greenLed;

private:
	void onNewInputState(uint8_t mask, bool newState);
	uint8_t m_buttonStates;
	InputManagerListener * m_listener;
	// Inputs
	Button * const m_octoAlertButton;
	Button * const m_countDownButton;
	Button * const m_captainBarnaclesButton;
	Button * const m_tweakButton;
	Button * const m_kwaziiButton;
	Button * const m_pesoButton;
};

#endif /* IOMANAGER_H_ */
