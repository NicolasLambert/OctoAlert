/*
 * AbstractStateManager.h
 *
 *  Created on: 1 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_ABSTRACTSTATEMANAGER_H_
#define SRC_STATES_ABSTRACTSTATEMANAGER_H_

#include "../Activable.h"
#include "AbstractState.h"

class AbstractStateManager : public Activable {
public:
	AbstractStateManager();
	void activate();
	void update();
protected:
	AbstractState * m_currentState;
	virtual void changeState(AbstractState * newState);
private:
	virtual AbstractState * getNextState(AbstractState * currentState) = 0;
};

#endif /* SRC_STATES_ABSTRACTSTATEMANAGER_H_ */
