/*
 * SoundState.h
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#ifndef SOUNDSTATE_H_
#define SOUNDSTATE_H_

#include <SD.h>

#include "../common/AbstractState.h"

// MP3 base file name (has to be suffixed by a digit 1-9)
// 7 char maximum !!
#define SOUND_ALERT         "Alert"
#define SOUND_CAPTAIN       "Captain"
#define SOUND_TWEAK         "Tweak"
#define SOUND_KWASII        "Kwazii"
#define SOUND_PESO          "Peso"
#define SOUND_CNTDOWN       "CntDown"
#define SOUND_SIMON_INTRO   "SimInt"
#define SOUND_SIMON_PLAY    "SimPlay"
#define SOUND_SIMON_FAIL    "SimFail"
#define SOUND_SIMON_WINSEQ  "SimWinS"
#define SOUND_SIMON_WINGAME "SimWinG"

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
