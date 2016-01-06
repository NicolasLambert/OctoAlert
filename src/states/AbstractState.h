/*
 * AbstractState.h
 *
 *  Created on: 16 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef ABSTRACTSTATE_H_
#define ABSTRACTSTATE_H_

class AbstractState {
public:
	AbstractState();
	virtual ~AbstractState();
	virtual void activate() = 0;
};

#endif /* ABSTRACTSTATE_H_ */
