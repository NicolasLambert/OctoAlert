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

class OctoStateManager: public AbstractManager<OctoStateManager> {
public:
	// Listener methods
	OctoStateManager();
	static void octoAlertPressed(bool const oldState, bool const newState);
	static void captainBarnaclesPressed(bool const oldState, bool const newState);
	static void tweakPressed(bool const oldState, bool const newState);
	static void kwaziiPressed(bool const oldState, bool const newState);
	static void pesoPressed(bool const oldState, bool const newState);
	static void countDownPressed(bool const oldState, bool const newState);
	void update(unsigned long currentTime);

private:
	// States members
	StandByState * m_standByState;
	OctoAlertState * m_octoAlertState;
	SoundState * m_captainBarnaclesState;
	SoundState * m_tweakState;
	SoundState * m_kwaziiState;
	SoundState * m_pesoState;
	CountDownState * m_countDownState;

	AbstractState * m_currentState;
	void changeState(AbstractState * newState);
};

#endif /* OCTOSTATEMANAGER_H_ */
