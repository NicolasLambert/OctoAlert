/*
 * SimonTestState.h
 *
 *  Created on: 1 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_SIMONTESTSTATE_H_
#define SRC_STATES_SIMON_SIMONTESTSTATE_H_

#include "SimonPlayState.h"

class SimonTestState: public AbstractState {
public:
	SimonTestState(uint8_t correctButtonsStates, SimonPlayState * playState);
	void activate();
	void update();
	// Return true to stay in the current state
	bool handleButtonPressed(uint8_t newButtonsStates);
	bool isCorrect();
	bool isFinished();
	bool m_canBeSqueezed;
private:
	bool m_isWaiting;
	bool m_isCorrect;
	const uint8_t m_correctButtonsStates;
	SimonPlayState * m_playState;
};

#endif /* SRC_STATES_SIMON_SIMONTESTSTATE_H_ */
