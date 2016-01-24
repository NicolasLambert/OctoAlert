/*
 * OctoAlertLeds.h
 *
 *  Created on: 14 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef OCTOALERTLEDS_H_
#define OCTOALERTLEDS_H_

#include "../../../Libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include <stdint.h>
#include "../input/InputManager.h"
#include "OctoAlertLedAnimation.h"

class OctoAlertLeds {
public:
	OctoAlertLeds(uint16_t pin);
	void update();
	void animate(OctoAlertLedAnimation * animation);
	void setColor(uint64_t ledMask, uint32_t color, bool switchOffOthers = true);
	void setColor(uint64_t ledMask, uint8_t r, uint8_t g, uint8_t b, bool switchOffOthers = true);
	void showNewColors();
//	void introAnimation();
//	void winSeqAnimation();
//	void failAnimation();
//	void winGameAnimation();
private:
	Adafruit_NeoPixel * const m_strip;
	const uint32_t m_off;
	OctoAlertLedAnimation * m_animation;
//	const uint32_t m_introColor;
//	const uint32_t m_winColor;
//	const uint32_t m_failColor;
};

#endif /* OCTOALERTLEDS_H_ */
