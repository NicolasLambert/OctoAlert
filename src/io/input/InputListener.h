/*
 * InputListener.h
 *
 *  Created on: 10 janv. 2016
 *      Author: nicolas
 */

#ifndef INPUTLISTENER_H_
#define INPUTLISTENER_H_

#include <stdint.h>

class InputListener {
public:
	InputListener();
	virtual ~InputListener();
	virtual void onNewInputState(uint8_t mask, bool newState) = 0;
};

#endif /* INPUTLISTENER_H_ */
