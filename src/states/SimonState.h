/*
 * SimonState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef SIMONSTATE_H_
#define SIMONSTATE_H_

#include "SoundState.h"
#include "../../Libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

#define STEP_INTERVAL 1000
#define SOUND_DURATION 800
#define STEP_COUNT 20

class SimonState: public SoundState {
public:
	SimonState(char const * const mp3Path);
	void activate();
	void update();
	bool isFinished();
private:
	void colorQuarter(int quarterId);
	void generateMusicScore();
	const uint32_t m_colors[4];
	int m_musicScore[STEP_COUNT];
	unsigned long m_lastStepTime;
	int m_lastStep;
};

#endif /* SIMONSTATE_H_ */
