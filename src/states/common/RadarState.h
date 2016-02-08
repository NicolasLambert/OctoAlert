/*
 * RadarState.h
 *
 *  Created on: 7 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_COMMON_RADARSTATE_H_
#define SRC_STATES_COMMON_RADARSTATE_H_

#define WAITING_TICKS 5

#include "AbstractState.h"
#include "../../io/output/OutputManager.h"
#include "../../io/output/LedMapping.h"
#include "../../io/output/RotaryMask.h"
#include "../../io/output/Color.h"

class RadarState: public AbstractState {
public:
	RadarState(uint64_t mask, uint8_t waitingTicks = WAITING_TICKS, uint16_t rotationCount = 0);
	void activate();
	void update();
	bool isFinished();
protected:
	virtual void setColors() = 0;
private:
	RotaryMask * m_ledMask;
	uint32_t m_colorOff;
};

#endif /* SRC_STATES_COMMON_RADARSTATE_H_ */
