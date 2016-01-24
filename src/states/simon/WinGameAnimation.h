/*
 * WinGameAnimation.h
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_WINGAMEANIMATION_H_
#define SRC_STATES_SIMON_WINGAMEANIMATION_H_

#include "../../io/output/OctoAlertLedAnimation.h"
#include "../../io/output/OutputManager.h"

class WinGameAnimation: public OctoAlertLedAnimation {
public:
	void activate();
	void update();
};

#endif /* SRC_STATES_SIMON_WINGAMEANIMATION_H_ */
