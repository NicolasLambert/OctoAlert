/*
 * RadarState.h
 *
 *  Created on: 7 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_COMMON_RADARSTATE_H_
#define SRC_STATES_COMMON_RADARSTATE_H_

#define WAITING_TICKS 10

#include "AbstractState.h"
#include "../../io/output/OutputManager.h"
#include "../../io/output/LedMapping.h"

class RadarState: public AbstractState {
public:
	RadarState(
			uint32_t color,
			uint64_t ledMask = LED_MASK_ALL,
			uint16_t blinkStateChangeCount = 0);
	void activate();
	void update();
	bool isFinished();
private:
	const uint64_t m_startLedMask;
	uint64_t m_ledMask;
	const uint32_t m_color;
	const uint16_t m_maxRotationCount;
	uint8_t m_waitingCounts;
	uint16_t m_currentRotationCount;
};

#endif /* SRC_STATES_COMMON_RADARSTATE_H_ */
