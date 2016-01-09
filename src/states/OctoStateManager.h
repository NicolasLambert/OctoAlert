/*
 * OctoStateManager.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef OCTOSTATEMANAGER_H_
#define OCTOSTATEMANAGER_H_

#include "../io/IOManager.h"
#include "OctoAlertState.h"
#include "StandByState.h"
#include "CountDownState.h"
#include "SimonState.h"

class OctoStateManager: public AbstractManager<OctoStateManager> {
public:
	// Listener methods
	OctoStateManager();
	static void buttonChanged(uint8_t buttonStates);
	void update(unsigned long currentTime);
	StandByState * m_standByState;

private:
	// States members
	OctoAlertState * m_octoAlertState;
	SoundState * m_captainBarnaclesState;
	SoundState * m_tweakState;
	SoundState * m_kwaziiState;
	SoundState * m_pesoState;
	CountDownState * m_countDownState;
	SimonState * m_simonState;

	AbstractState * m_currentState;
	void changeState(AbstractState * newState);
};

#endif /* OCTOSTATEMANAGER_H_ */
