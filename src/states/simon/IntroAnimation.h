/*
 * IntroAnimation.h
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_INTROANIMATION_H_
#define SRC_STATES_SIMON_INTROANIMATION_H_

#include "../../io/output/OctoAlertLedAnimation.h"
#include "../../io/output/OutputManager.h"

class IntroAnimation: public OctoAlertLedAnimation {
public:
	void activate();
	void update();
};

#endif /* SRC_STATES_SIMON_INTROANIMATION_H_ */
