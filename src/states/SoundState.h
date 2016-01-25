/*
 * SoundState.h
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#ifndef SOUNDSTATE_H_
#define SOUNDSTATE_H_

#include <SD.h>
#include "../io/output/OutputManager.h"
#include "AbstractState.h"

class SoundState: public AbstractState {
public:
	SoundState(char const * const mp3Path);
	void activate();
	bool isFinished();
protected:
	uint8_t m_lastIndex;
private:
	uint8_t m_trackNumberPosition;
	int8_t m_maxIndex;
	char m_fileName[13];
};

#endif /* SOUNDSTATE_H_ */
