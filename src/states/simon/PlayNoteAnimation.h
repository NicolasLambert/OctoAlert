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

#include "../octoalert/SmoothBlink.h"

class PlayNoteAnimation: public OctoAlertLedAnimation {
public:
	PlayNoteAnimation(uint32_t color, int64_t ledMask);
	void activate();
	void update();
private:
	SmoothBlink * m_blink_center;
	SmoothBlink * m_blink_littleRing;
	SmoothBlink * m_blink_bigRing;
	uint16_t m_littleRingDelay;
	uint16_t m_bigRingDelay;
	unsigned long m_activationTime;
};

#endif /* SRC_STATES_SIMON_PLAYNOTEANIMATION_H_ */
