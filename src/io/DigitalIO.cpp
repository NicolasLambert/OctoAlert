/*
 * DigitalIO.cpp
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#include "DigitalIO.h"

DigitalIO::DigitalIO(uint8_t const pin, bool const reversed) :
		m_pin(pin), m_reversed(reversed) {}
DigitalIO::~DigitalIO() {}
