/*
 * AbstractStateManager.h
 *
 *  Created on: 1 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_ABSTRACTSTATEMANAGER_H_
#define SRC_STATES_ABSTRACTSTATEMANAGER_H_

#include "AbstractState.h"

class AbstractStateManager : public AbstractState {
public:
	AbstractStateManager();
	void activate();
	void update();
	// Return true to stay in the current state
	bool handleButtonPressed(uint8_t newButtonsStates);
protected:
	AbstractState * m_currentState;
	virtual void changeState(AbstractState * newState);
private:
	virtual AbstractState * getNextState(AbstractState * currentState) = 0;
};

#endif /* SRC_STATES_ABSTRACTSTATEMANAGER_H_ */
