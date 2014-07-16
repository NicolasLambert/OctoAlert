/*
 * Button.cpp
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#include "Button.h"

Button::Button(int const pin, unsigned int debounceDelay) :
		DigitalInput(pin, true, debounceDelay) {
}
