/*
 * SimonWinGameState.h
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_SIMONWINGAMESTATE_H_
#define SRC_STATES_SIMON_SIMONWINGAMESTATE_H_

#include "../common/SoundState.h"
#include "../../io/output/RotaryMask.h"
#include "../../io/output/Color.h"

#define WAITING_TICKS 13

class SimonWinGameState: public SoundState {
public:
	SimonWinGameState();
	void activate();
	void update();
private:
	void rotateAll(uint8_t &waitingCounter, uint8_t waitingTicks, uint64_t rotationLocationMask);
	RotaryMask * m_redMask;
	RotaryMask * m_blueMask;
	RotaryMask * m_yellowMask;
	RotaryMask * m_greenMask;
	const uint32_t m_red;
	const uint32_t m_blue;
	const uint32_t m_yellow;
	const uint32_t m_green;
};

#endif /* SRC_STATES_SIMON_SIMONWINGAMESTATE_H_ */
