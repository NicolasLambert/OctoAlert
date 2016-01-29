/*
 * CountDownState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef COUNTDOWNSTATE_H_
#define COUNTDOWNSTATE_H_

#include "SoundState.h"

static uint16_t const cntDwnDelay[6] = { 0, 1700, 850, 850, 850, 850 };

class CountDownState: public SoundState {
public:
	CountDownState(char const * const mp3Path);
	void activate();
	void update();
private:
	unsigned long m_lastStepTime;
	uint8_t m_lastStep;
};

#endif /* COUNTDOWNSTATE_H_ */
