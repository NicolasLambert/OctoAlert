/*
 * SimonState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef SRC_STATES_SIMON_SIMONSTATE_H_
#define SRC_STATES_SIMON_SIMONSTATE_H_

#include "../SoundState.h"
#include "../../io/input/InputManager.h"
#include "../../../Libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.h"
#include "IntroAnimation.h"
#include "WinSequenceAnimation.h"
#include "FailAnimation.h"
#include "WinGameAnimation.h"
#include "PlayNoteAnimation.h"

// Durations
#define STEP_INTERVAL 800
#define STEP_TO_WIN_COUNT 5

// Simon states
#define STATE_INTRO    0
#define STATE_PLAY     1
#define STATE_TEST     2
#define STATE_WIN_SEQ  3
#define STATE_FAIL     4
#define STATE_WIN_GAME 5
#define STATE_END      6
#define STATE_EXIT     7

// SOUND Ids
// MP3 Files are named from 1 to 9 max
#define SOUND_ID_TWEAK     1
#define SOUND_ID_PESO      2
#define SOUND_ID_KWAZII    3
#define SOUND_ID_CPTBARNAC 4
#define SOUND_ID_INTRO     5
#define SOUND_ID_WIN_SEQ   6
#define SOUND_ID_FAIL      7
#define SOUND_ID_WIN_GAME  8

class SimonState: public SoundState {
public:
	SimonState(char const * const mp3Path);
	void activate();
	void update();
	bool isFinished();
	bool handleButtonPressed(uint8_t newButtonsStates);
private:
	void playOneNote();
	void generateMusicScore();
	bool isDelayPassed(uint16_t delay);
	void switchState(uint8_t newState);
	void play(uint8_t soundId);
	const uint8_t m_buttonByQuarter[4];
	uint8_t m_musicScore[STEP_TO_WIN_COUNT];
	int8_t m_lastScoreStep;
	int8_t m_lastSuccessfullScoreStep;
	unsigned long m_lastScoreStepTime;
	uint8_t m_currentState;
	IntroAnimation * m_introAnimation;
	WinSequenceAnimation * m_winSequenceAnimation;
	FailAnimation * m_failAnimation;
	WinGameAnimation * m_winGameAnimation;
	PlayNoteAnimation * m_playNoteAnimation[4];
};

#endif /* SRC_STATES_SIMON_SIMONSTATE_H_ */
