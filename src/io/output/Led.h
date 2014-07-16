/*
 * Led.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef LED_H_
#define LED_H_

#include "DigitalOutput.h"

#define BLINK_INTERVAL 400UL    // interval at which to blink (milliseconds)

class Led: public DigitalOutput {
public:
	Led(int const pin);
	void blink();
	virtual void on();
	virtual void off();
	virtual void update(unsigned long currentTime);
private:
	unsigned long m_previousBlinkTime; // will store last time LED was updated
	bool m_isBlinking;
};

#endif /* LED_H_ */
