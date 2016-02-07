/*
 * SimonWinSequenceState.h
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_SIMONWINSEQUENCESTATE_H_
#define SRC_STATES_SIMON_SIMONWINSEQUENCESTATE_H_

#include "../../io/output/Color.h"
#include "../common/SoundState.h"
#include "../common/SmoothBlinkState.h"

class SimonWinSequenceState: public SoundState {
public:
	SimonWinSequenceState();
	void activate();
	void update();
private:
	SmoothBlinkState * m_smoothBlinkState;
};

#endif /* SRC_STATES_SIMON_SIMONWINSEQUENCESTATE_H_ */
