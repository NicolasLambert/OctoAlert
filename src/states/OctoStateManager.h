/*
 * OctoStateManager.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef OCTOSTATEMANAGER_H_
#define OCTOSTATEMANAGER_H_

#include "StandByState.h"
#include "countdown/CountDownState.h"
#include "simon/SimonState.h"
#include "common/AbstractStateManager.h"
#include "octonauts/OctoAlertState.h"
#include "octonauts/OctoButtonState.h"

class OctoStateManager: public AbstractManager<OctoStateManager>, public AbstractStateManager, public InputManagerListener {
public:
	// Listener methods
	OctoStateManager();
	void onNewInputState(uint8_t newState);
	StandByState * m_standByState;
	void update();
	bool isFinished();
	// Return true to stay in the current state
	bool handleButtonPressed(uint8_t newButtonsStates);

private:
	// States members
	OctoAlertState * m_octoAlertState;
	OctoButtonState * m_captainBarnaclesState;
	OctoButtonState * m_tweakState;
	OctoButtonState * m_kwaziiState;
	OctoButtonState * m_pesoState;
	CountDownState * m_countDownState;
	SimonState * m_simonState;
	AbstractState * getNextState(AbstractState * currentState);
};

#endif /* OCTOSTATEMANAGER_H_ */
