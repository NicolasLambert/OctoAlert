/*
 * StandByState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef STANDBYSTATE_H_
#define STANDBYSTATE_H_

#include "AbstractState.h"
#include "../io/IOManager.h"

class StandByState: public AbstractState {
public:
	StandByState();
	virtual void activate();
};

#endif /* STANDBYSTATE_H_ */
