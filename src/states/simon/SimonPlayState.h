/*
 * SimonPlayState.h
 *
 *  Created on: 5 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_SIMONPLAYSTATE_H_
#define SRC_STATES_SIMON_SIMONPLAYSTATE_H_

#define QUARTER_TOP_RIGHT    0
#define QUARTER_BOTTOM_RIGHT 1
#define QUARTER_BOTTOM_LEFT  2
#define QUARTER_TOP_LEFT     3

#include "../common/SmoothBlinkState.h"
#include "../common/SoundState.h"

class SimonPlayState: public SoundState {
public:
	SimonPlayState(uint32_t color, int64_t ledMask, uint8_t soundIndex);
	void activate();
	void update();
	bool isFinished();
private:
	SmoothBlinkState * m_blink_center;
	SmoothBlinkState * m_blink_littleRing;
	SmoothBlinkState * m_blink_bigRing;
	uint16_t m_littleRingDelay;
	uint16_t m_bigRingDelay;
	unsigned long m_activationTime;
	uint8_t m_soundIndex;
};

#endif /* SRC_STATES_SIMON_SIMONPLAYSTATE_H_ */
