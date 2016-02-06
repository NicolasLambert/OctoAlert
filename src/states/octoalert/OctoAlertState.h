/*
 * OctoAlertState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef SRC_STATES_OCTOALERT_OCTOALERTSTATE_H_
#define SRC_STATES_OCTOALERT_OCTOALERTSTATE_H_

#include "../common/SmoothBlinkState.h"
#include "../common/SoundState.h"

class OctoAlertState: public AbstractState {
public:
	OctoAlertState();
	void activate();
	void update();
	bool isFinished();
	// Return true to stay in the current state
	bool handleButtonPressed(uint8_t newButtonsStates);
private:
	SoundState * m_sound;
	SmoothBlinkState * m_blink;
};

#endif /* SRC_STATES_OCTOALERT_OCTOALERTSTATE_H_ */
