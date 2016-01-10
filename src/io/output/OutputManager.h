/*
 * OutputManager.h
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#ifndef OUTPUTMANAGER_H_
#define OUTPUTMANAGER_H_

#include "../../AbstractManager.h"
#include "Led.h"
#include "OctoAlertLeds.h"
#include "MusicPlayer.h"

class OutputManager: public AbstractManager<OutputManager> {
public:
	OutputManager();
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
};

#endif /* OUTPUTMANAGER_H_ */
