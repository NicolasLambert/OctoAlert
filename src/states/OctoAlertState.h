/*
 * OctoAlertState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef OCTOALERTSTATE_H_
#define OCTOALERTSTATE_H_

#include "SoundState.h"

class OctoAlertState: public SoundState {
public:
	OctoAlertState(char const * const mp3Path);
	void activate();
private:
	const uint32_t m_yellow;
};

#endif /* OCTOALERTSTATE_H_ */
