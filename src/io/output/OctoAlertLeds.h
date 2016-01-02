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

class OctoAlertLeds {
public:
	OctoAlertLeds(uint16_t pin);
	void update(unsigned long currentTime);
	void colorAll(uint8_t r, uint8_t g, uint8_t b);
	void smoothBlink(int r, int g, int b);
private:
	void internalColorAll(uint8_t r, uint8_t g, uint8_t b);
	Adafruit_NeoPixel * const m_strip;
	int m_smoothBlinkWay;
	uint16_t m_currentBrightness;
	int m_rFactor;
	int m_gFactor;
	int m_bFactor;
};

#endif /* OCTOALERTLEDS_H_ */
