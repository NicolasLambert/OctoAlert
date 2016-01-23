/*
 * Button.cpp
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#include "Button.h"

Button::Button(uint8_t const pin) : DigitalInput(pin, true) {}
