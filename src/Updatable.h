/*
 * Updatable.h
 *
 *  Created on: 7 janv. 2016
 *      Author: nicolas
 */

#ifndef SRC_UPDATABLE_H_
#define SRC_UPDATABLE_H_

class Updatable {
public:
	virtual ~Updatable();
	virtual void update() = 0;
};

#endif /* SRC_UPDATABLE_H_ */
