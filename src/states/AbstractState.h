/*
 * AbstractState.h
 *
 *  Created on: 16 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef ABSTRACTSTATE_H_
#define ABSTRACTSTATE_H_

#include "../Activable.h"

class AbstractState : public Activable {
public:
	AbstractState();
	void update(unsigned long currentTime);
	virtual AbstractState * getNextState() = 0;
};

#endif /* ABSTRACTSTATE_H_ */
