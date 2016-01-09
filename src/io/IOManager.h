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

#define BTN_OCTOALERT 1
#define BTN_COUNTDOWN 2
#define BTN_CPTBARNAC 4
#define BTN_TWEAK     8
#define BTN_KWAZII    16
#define BTN_PESO      32

class IOManager: public AbstractManager<IOManager> {
public:
	typedef void (*ButtonChangeListener)(uint8_t m_buttonStates);
	IOManager();
	void setListener(ButtonChangeListener listener);
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
	static void octoAlertPressed(bool const oldState, bool const newState);
	static void captainBarnaclesPressed(bool const oldState, bool const newState);
	static void tweakPressed(bool const oldState, bool const newState);
	static void kwaziiPressed(bool const oldState, bool const newState);
	static void pesoPressed(bool const oldState, bool const newState);
	static void countDownPressed(bool const oldState, bool const newState);
	void pingListeners(uint8_t buttonId, bool newState);
	uint8_t m_buttonStates;
	ButtonChangeListener m_listener;
	// Inputs
	Button * const m_octoAlertButton;
	Button * const m_countDownButton;
	Button * const m_captainBarnaclesButton;
	Button * const m_tweakButton;
	Button * const m_kwaziiButton;
	Button * const m_pesoButton;
};

#endif /* IOMANAGER_H_ */
