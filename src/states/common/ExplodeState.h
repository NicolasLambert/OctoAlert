/*
 * ExplodeState.h
 *
 *  Created on: 7 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_COMMON_EXPLODESTATE_H_
#define SRC_STATES_COMMON_EXPLODESTATE_H_

#include "../../io/output/OutputManager.h"
#include "AbstractState.h"
#include "SmoothBlinkState.h"

class ExplodeState: public AbstractState {
public:
	ExplodeState(uint32_t color, uint64_t ledMask = LED_MASK_ALL, uint16_t animationCount = INFINITE_BLINK);
	void activate();
	void update();
	bool isFinished();
private:
	void startAnimation();
	SmoothBlinkState * m_blink_center;
	SmoothBlinkState * m_blink_littleRing;
	SmoothBlinkState * m_blink_bigRing;
	uint16_t m_littleRingDelay;
	uint16_t m_bigRingDelay;
	unsigned long m_activationTime;
	const uint16_t m_maxAnimationCount;
	uint16_t m_currentAnimationCount;
};

#endif /* SRC_STATES_COMMON_EXPLODESTATE_H_ */
