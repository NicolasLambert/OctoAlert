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
#include <stdint.h>

#define MIN_BRIGHT_BLINK 50
#define MAX_BRIGHT_BLINK 255
#define REFRESH_SMOOTH_BLINK_DELAY 200UL
#define TOP_RIGHT_QUARTER 0
#define BOTTOM_RIGHT_QUARTER 1
#define BOTTOM_LEFT_QUARTER 2
#define TOP_LEFT_QUARTER 3

class OctoAlertLeds {
public:
	OctoAlertLeds(uint16_t pin);
	void update();
	void colorAll(uint32_t color);
	void colorQuarter(int quarterId, uint32_t color);
	void smoothBlink(uint32_t color);
	void offAll();
private:
	void internalColorAll(uint32_t color);
	void internalColorAll(uint8_t r, uint8_t g, uint8_t b);
	void smoothBlink(int r, int g, int b);
	bool isInQuarter(int quarterId, int ledId);
	Adafruit_NeoPixel * const m_strip;
	int m_smoothBlinkWay;
	uint16_t m_currentBrightness;
	int m_rFactor;
	int m_gFactor;
	int m_bFactor;
	const uint32_t off;
};

#endif /* OCTOALERTLEDS_H_ */
