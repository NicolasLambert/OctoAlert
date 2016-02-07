/*
 * OctoButtonState.h
 *
 *  Created on: 7 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_OCTONAUTS_OCTOBUTTONSTATE_H_
#define SRC_STATES_OCTONAUTS_OCTOBUTTONSTATE_H_

#include "../common/ExplodeState.h"
#include "../common/SoundState.h"

class OctoButtonState: public SoundState {
public:
	OctoButtonState(uint32_t color, char const * const mp3Path);
	void activate();
	void update();
private:
	ExplodeState * m_explodeState;
};

#endif /* SRC_STATES_OCTONAUTS_OCTOBUTTONSTATE_H_ */
