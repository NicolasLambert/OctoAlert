/*
 * InputManager.h
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "../../AbstractManager.h"
#include "Button.h"
#include "InputListener.h"
#include "InputManagerListener.h"

#define BTN_OCTOALERT 1
#define BTN_COUNTDOWN 2
#define BTN_CPTBARNAC 4
#define BTN_TWEAK     8
#define BTN_KWAZII    16
#define BTN_PESO      32

class InputManager: public AbstractManager<InputManager>, public InputListener {
public:
	InputManager();
	void setListener(InputManagerListener * listener);
	void update(unsigned long currentTime);

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

#endif /* INPUTMANAGER_H_ */
