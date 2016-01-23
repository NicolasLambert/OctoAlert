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

#define MIN_BRIGHT_BLINK 0
#define MAX_BRIGHT_BLINK 255
#define REFRESH_SMOOTH_BLINK_DELAY 200UL
#define ALL_QUARTER -1
#define TOP_RIGHT_QUARTER 0
#define BOTTOM_RIGHT_QUARTER 1
#define BOTTOM_LEFT_QUARTER 2
#define TOP_LEFT_QUARTER 3

class OctoAlertLeds {
public:
	OctoAlertLeds(uint16_t pin);
	void update();
	void colorAll(uint32_t color);
	void smoothBlink(uint32_t color, int8_t quarterId = ALL_QUARTER, uint16_t blinkStateChangeCount = 0, uint8_t minBright = MIN_BRIGHT_BLINK, uint8_t maxBright = MAX_BRIGHT_BLINK);
	void offAll();
private:
	void internalColorAll(uint32_t color);
	void internalColorAll(uint8_t r, uint8_t g, uint8_t b);
	void internalSmoothBlink(int r, int g, int b);
	bool isInQuarter(uint8_t ledId);
	Adafruit_NeoPixel * const m_strip;
	int8_t m_quarterId;
	int8_t m_smoothBlinkWay; // Light increase or decrease or disable
	int8_t m_blinkStateChangeCountDown; // -1 means infinite blink, 2 for one blink
	uint16_t m_currentBrightness;
	int m_rFactor;
	int m_gFactor;
	int m_bFactor;
	const uint32_t off;
	uint8_t m_minBright;
	uint8_t m_maxBright;
};

#endif /* OCTOALERTLEDS_H_ */
