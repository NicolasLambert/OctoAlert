/*
 * OctoAlertState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef SRC_STATES_OCTOALERT_OCTOALERTSTATE_H_
#define SRC_STATES_OCTOALERT_OCTOALERTSTATE_H_

#include "../SoundState.h"
#include "SmoothBlink.h"

class OctoAlertState: public SoundState {
public:
	OctoAlertState(char const * const mp3Path);
	void activate();
	void update();
private:
	const uint32_t m_yellow;
	SmoothBlink * m_smoothBlink;
};

#endif /* SRC_STATES_OCTOALERT_OCTOALERTSTATE_H_ */
