/*
 * DigitalOutput.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef DIGITALOUTPUT_H_
#define DIGITALOUTPUT_H_

#include "../DigitalIO.h"

class DigitalOutput: public DigitalIO {
public:
	DigitalOutput(int const pin, bool const reversed);
	void setState(bool const newState);
	virtual bool const getState();
	virtual void on();
	virtual void off();
	void toggle();
	virtual void update(unsigned long currentTime);
private:
	int m_lastState;
};

#endif /* DIGITALOUTPUT_H_ */
