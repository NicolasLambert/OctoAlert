/*
 * SimonWinGameState.h
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_SIMONWINGAMESTATE_H_
#define SRC_STATES_SIMON_SIMONWINGAMESTATE_H_

#include "../../io/output/OutputManager.h"
#include "../common/SoundState.h"

class SimonWinGameState: public SoundState {
public:
	SimonWinGameState();
	void activate();
	void update();
};

#endif /* SRC_STATES_SIMON_SIMONWINGAMESTATE_H_ */
