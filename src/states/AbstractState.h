/*
 * AbstractState.h
 *
 *  Created on: 16 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef ABSTRACTSTATE_H_
#define ABSTRACTSTATE_H_

#include "../Activable.h"
#include <stdint.h>

class AbstractState : public Activable {
public:
	AbstractState();
	void update();
	virtual bool isFinished() = 0;
	virtual bool shouldStayInThisState(uint8_t newButtonsStates);
};

#endif /* ABSTRACTSTATE_H_ */
