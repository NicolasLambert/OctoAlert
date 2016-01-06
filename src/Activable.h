/*
 * Activable.h
 *
 *  Created on: 6 janv. 2016
 *      Author: nicolas
 */

#ifndef SRC_ACTIVABLE_H_
#define SRC_ACTIVABLE_H_

#include "Updatable.h"

class Activable : public Updatable {
public:
	virtual void activate() = 0;
};

#endif /* SRC_ACTIVABLE_H_ */
