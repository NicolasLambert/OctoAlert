/*
 * StandByState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef STANDBYSTATE_H_
#define STANDBYSTATE_H_

#include "common/AbstractState.h"

class StandByState: public AbstractState {
public:
	StandByState();
	void activate();
	bool isFinished();
private:
	const uint32_t m_blue;
};

#endif /* STANDBYSTATE_H_ */
