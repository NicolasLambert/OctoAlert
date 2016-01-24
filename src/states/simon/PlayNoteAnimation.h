/*
 * PlayNoteAnimation.h
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#ifndef SRC_STATES_SIMON_PLAYNOTEANIMATION_H_
#define SRC_STATES_SIMON_PLAYNOTEANIMATION_H_

#define QUARTER_TOP_RIGHT    0
#define QUARTER_BOTTOM_RIGHT 1
#define QUARTER_BOTTOM_LEFT  2
#define QUARTER_TOP_LEFT     3

#include "../../io/output/LedMapping.h"
#include "../../io/output/OctoAlertLedAnimation.h"
#include "../../io/output/OutputManager.h"


class PlayNoteAnimation: public OctoAlertLedAnimation {
public:
	PlayNoteAnimation(uint32_t color, int64_t ledMask);
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

#endif /* SRC_STATES_SIMON_PLAYNOTEANIMATION_H_ */
