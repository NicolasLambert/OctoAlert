/*
 * DigitalInput.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef DIGITALINPUT_H_
#define DIGITALINPUT_H_

#include "../DigitalIO.h"
#include "InputListener.h"

#define DEFAULT_DEBOUNCE_DELAY 50

class DigitalInput: public DigitalIO {
public:
	DigitalInput(int const pin, bool const reversed, uint8_t mask, unsigned int debounceDelay);
	void setListener(InputListener * listener);
	bool const getState();
	void update(unsigned long currentTime);
private:
	unsigned long m_lastChangeTime;
	bool m_lastState;
	bool m_currentState;
	InputListener * m_listener;
	unsigned int m_debounceDelay;
	uint8_t m_mask;
};

#endif /* DIGITALINPUT_H_ */
