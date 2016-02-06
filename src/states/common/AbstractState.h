/*
 * AbstractState.h
 *
 *  Created on: 16 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef ABSTRACTSTATE_H_
#define ABSTRACTSTATE_H_

#include "../../Activable.h"
#include "../../io/output/OutputManager.h"
#include <stdint.h>

class AbstractState : public Activable {
public:
	void activate();
	void update();
	virtual bool isFinished() = 0;
	// Return true to stay in the current state
	virtual bool handleButtonPressed(uint8_t newButtonsStates);
};

#endif /* ABSTRACTSTATE_H_ */
