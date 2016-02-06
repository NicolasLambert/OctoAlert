/*
 * SimonWinSequenceState.h
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_SIMONWINSEQUENCESTATE_H_
#define SRC_STATES_SIMON_SIMONWINSEQUENCESTATE_H_

#include "../../io/output/OutputManager.h"
#include "../common/SoundState.h"

class SimonWinSequenceState: public SoundState {
public:
	SimonWinSequenceState();
	void activate();
	void update();
};

#endif /* SRC_STATES_SIMON_SIMONWINSEQUENCESTATE_H_ */
