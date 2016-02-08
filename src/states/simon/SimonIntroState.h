/*
 * SimonIntroState.h
 *
 *  Created on: 1 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_SIMONINTROSTATE_H_
#define SRC_STATES_SIMON_SIMONINTROSTATE_H_

#include "../../io/output/OutputManager.h"
#include "../common/SoundState.h"
#include "../common/RadarState.h"
#include "../../io/output/Color.h"

class SimonIntroState: public RadarState {
public:
	SimonIntroState();
	void activate();
	void update();
	bool isFinished();
protected:
	void setColors();
private:
	SoundState * m_soundState;
	const uint32_t m_red;
	const uint32_t m_blue;
	const uint32_t m_yellow;
	const uint32_t m_green;
	const uint32_t m_white;
};

#endif /* SRC_STATES_SIMON_SIMONINTROSTATE_H_ */
