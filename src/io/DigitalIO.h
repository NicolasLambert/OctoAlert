/*
 * DigitalIO.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef DIGITALIO_H_
#define DIGITALIO_H_

#include "Arduino.h"
#include "../Updatable.h"

class DoorStateManager;

class DigitalIO : public Updatable {
public:
	DigitalIO(int const pin, bool const reversed = false);
	virtual bool const getState() = 0;
protected:
	int const m_pin;
	bool const m_reversed;
};

#endif /* DIGITALIO_H_ */
