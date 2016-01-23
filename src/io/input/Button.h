/*
 * Button.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "DigitalInput.h"

class Button: public DigitalInput {
public:
	Button(uint8_t const pin);
};

#endif /* BUTTON_H_ */
