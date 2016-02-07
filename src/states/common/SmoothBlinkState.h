/*
 * SmoothBlink.h
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_OCTOALERT_SMOOTHBLINKSTATESTATE_H_
#define SRC_STATES_OCTOALERT_SMOOTHBLINKSTATESTATE_H_

#include "../../io/output/OutputManager.h"
#include "../../io/output/LedMapping.h"
#include "../common/AbstractState.h"

#define MIN_BRIGHT_BLINK 0
#define MAX_BRIGHT_BLINK 255
#define REFRESH_SMOOTH_BLINK_DELAY 200UL
// (1 is slow, 10 or more is quick)
#define DEFAULT_SMOOTH_SPEED 2
#define INFINITE_BLINK 0

class SmoothBlinkState: public AbstractState {
public:
	SmoothBlinkState(
			uint32_t color,
			uint64_t ledMask = LED_MASK_ALL,
			uint16_t blinkStateChangeCount = INFINITE_BLINK,
			float speed = DEFAULT_SMOOTH_SPEED,
			uint8_t minBright = MIN_BRIGHT_BLINK,
			uint8_t maxBright = MAX_BRIGHT_BLINK);
	void activate();
	void update();
	bool isFinished();
private:
	const uint64_t m_ledMask;
	float m_smoothBlinkWay; // Light increase or decrease or disable
	int8_t m_currentCountDown; // -1 means infinite blink, 2 for one blink
	const int8_t m_maxCountDown; // -1 means infinite blink, 2 for one blink
	float m_currentBrightness;
	uint8_t m_rFactor;
	uint8_t m_gFactor;
	uint8_t m_bFactor;
	const float m_speed;
	const uint8_t m_minBright;
	const uint8_t m_maxBright;
};

#endif /* SRC_STATES_OCTOALERT_SMOOTHBLINKSTATESTATE_H_ */
