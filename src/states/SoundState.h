/*
 * SoundState.h
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#ifndef SOUNDSTATE_H_
#define SOUNDSTATE_H_

#include "../io/IOManager.h"
#include "AbstractState.h"

class SoundState: public AbstractState {
public:
	SoundState(char const * const mp3Path);
	virtual void activate();
private:
	unsigned int m_trackNumberPosition;
	unsigned int m_lastIndex;
	unsigned int m_maxIndex;
	char m_fileName[13];
};

#endif /* SOUNDSTATE_H_ */
