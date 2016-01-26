/*
 * DigitalOutput.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef DIGITALOUTPUT_H_
#define DIGITALOUTPUT_H_

#include "../DigitalIO.h"
#include "../../Updatable.h"
#include <Arduino.h>

class DigitalOutput: public DigitalIO, public Updatable {
public:
	DigitalOutput(uint8_t const pin, bool const reversed);
	void setState(bool const newState);
	bool const getState();
	virtual void on();
	virtual void off();
	void toggle();
private:
	int8_t m_lastState;
};

#endif /* DIGITALOUTPUT_H_ */
