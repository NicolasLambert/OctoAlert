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
#include "output/Led.h"
#include "output/OctoAlertLeds.h"
#include "output/MusicPlayer.h"

class IOManager: public AbstractManager<IOManager> {
public:
	IOManager();
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

	//----------------------------------------------------------------------------------------------------
	// Inputs
	Button * const m_octoAlertButton;
	Button * const m_countDownButton;
	Button * const m_captainBarnaclesButton;
	Button * const m_tweakButton;
	Button * const m_kwaziiButton;
	Button * const m_pesoButton;
};

#endif /* IOMANAGER_H_ */
