/*
 * InputManagerListener.h
 *
 *  Created on: 10 janv. 2016
 *      Author: nicolas
 */

#ifndef INPUTMANAGERLISTENER_H_
#define INPUTMANAGERLISTENER_H_

#include <stdint.h>

class InputManagerListener {
public:
	virtual ~InputManagerListener();
	virtual void onNewInputState(uint8_t newState) = 0;
};

#endif /* INPUTMANAGERLISTENER_H_ */
