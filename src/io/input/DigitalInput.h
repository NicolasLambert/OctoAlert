/*
 * DigitalInput.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef DIGITALINPUT_H_
#define DIGITALINPUT_H_

#include "../DigitalIO.h"

class DigitalInput: public DigitalIO {
public:
	DigitalInput(uint8_t const pin, bool const reversed);
	bool const getState();
};

#endif /* DIGITALINPUT_H_ */
