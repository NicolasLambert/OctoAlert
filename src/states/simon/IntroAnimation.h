/*
 * IntroAnimation.h
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_INTROANIMATION_H_
#define SRC_STATES_SIMON_INTROANIMATION_H_

#include "../../io/output/OctoAlertLedAnimation.h"
#include "../../io/output/OutputManager.h"
#include "Color.h"

#define WAITING_TICKS_BIG_RING 13
// Because we have 24 leds on the big ring and 16 on the little (24/16 = 3/2)
#define WAITING_TICKS_LITTLE_RING WAITING_TICKS_BIG_RING*3/2

class IntroAnimation: public OctoAlertLedAnimation {
public:
	IntroAnimation();
	void activate();
	void update();
private:
	void rotateAll(uint8_t &waitingCounter, uint8_t waitingTicks, uint64_t rotationLocationMask);
	void rotateOne(uint64_t &colorMaskToRotate, uint64_t rotationLocationMask);
	uint64_t m_redMask;
	uint64_t m_blueMask;
	uint64_t m_yellowMask;
	uint64_t m_greenMask;
	uint8_t m_waitingCountBigRing;
	uint8_t m_waitingCountLittleRing;
	const uint32_t m_red;
	const uint32_t m_blue;
	const uint32_t m_yellow;
	const uint32_t m_green;
};

#endif /* SRC_STATES_SIMON_INTROANIMATION_H_ */
