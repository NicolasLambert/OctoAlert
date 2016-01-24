/*
 * SmoothBlink.h
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_OCTOALERT_SMOOTHBLINK_H_
#define SRC_STATES_OCTOALERT_SMOOTHBLINK_H_

#include "../../io/output/OutputManager.h"

#define MIN_BRIGHT_BLINK 0
#define MAX_BRIGHT_BLINK 255
#define REFRESH_SMOOTH_BLINK_DELAY 200UL
#define ALL_QUARTER -1
#define TOP_RIGHT_QUARTER 0
#define BOTTOM_RIGHT_QUARTER 1
#define BOTTOM_LEFT_QUARTER 2
#define TOP_LEFT_QUARTER 3

class SmoothBlink: public OctoAlertLedAnimation {
public:
	SmoothBlink(uint32_t color, int8_t ledMask = LED_MASK_ALL, uint16_t blinkStateChangeCount = 0, uint8_t minBright = MIN_BRIGHT_BLINK, uint8_t maxBright = MAX_BRIGHT_BLINK);
	void activate();
	void update();
private:
	const int64_t m_ledMask;
	int8_t m_smoothBlinkWay; // Light increase or decrease or disable
	int8_t m_currentCountDown; // -1 means infinite blink, 2 for one blink
	const int8_t m_maxCountDown; // -1 means infinite blink, 2 for one blink
	uint16_t m_currentBrightness;
	uint8_t m_rFactor;
	uint8_t m_gFactor;
	uint8_t m_bFactor;
	const uint8_t m_minBright;
	const uint8_t m_maxBright;
};

#endif /* SRC_STATES_OCTOALERT_SMOOTHBLINK_H_ */
