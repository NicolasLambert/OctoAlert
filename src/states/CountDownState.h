/*
 * CountDownState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef COUNTDOWNSTATE_H_
#define COUNTDOWNSTATE_H_

#include "SoundState.h"

static unsigned int const cntDwnDelay[6] = { 0, 1950, 950, 950, 950, 950 };

class CountDownState: public SoundState {
public:
	CountDownState(char const * const mp3Path);
	void activate();
	void update(unsigned long currentTime);
private:
	unsigned long m_lastStepTime;
	int m_lastStep;
};

#endif /* COUNTDOWNSTATE_H_ */
