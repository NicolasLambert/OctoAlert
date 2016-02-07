/*
 * SimonFailState.h
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_SIMONFAILSTATE_H_
#define SRC_STATES_SIMON_SIMONFAILSTATE_H_

#include "../../io/output/Color.h"
#include "../common/SoundState.h"
#include "../common/SmoothBlinkState.h"

class SimonFailState: public SoundState {
public:
	SimonFailState();
	void activate();
	void update();
private:
	SmoothBlinkState * m_smoothBlinkState;
};

#endif /* SRC_STATES_SIMON_SIMONFAILSTATE_H_ */
