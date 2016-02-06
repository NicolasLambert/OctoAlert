/*
 * SimonState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef SRC_STATES_SIMON_SIMONSTATE_H_
#define SRC_STATES_SIMON_SIMONSTATE_H_

#include "../../io/input/InputManager.h"
#include "SimonIntroState.h"
#include "SimonWinSequenceState.h"
#include "SimonFailState.h"
#include "SimonWinGameState.h"
#include "SimonPlayState.h"
#include "SimonTestState.h"
#include "Color.h"
#include "../common/AbstractStateManager.h"

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

class SimonState: public AbstractStateManager {
public:
	SimonState();
	void activate();
	bool isFinished();
	bool handleButtonPressed(uint8_t newButtonsStates);
private:
	void generateMusicScore();
	bool isTestState(AbstractState * state);
	bool isPlayState(AbstractState * state);
	SimonPlayState * getNextPlayState();
	SimonTestState * getNextTestState();
	AbstractState * getNextState(AbstractState * currentState);
	uint8_t m_musicScore[STEP_TO_WIN_COUNT];
	int8_t m_lastScoreStep;
	int8_t m_lastSuccessfullScoreStep;
	SimonIntroState * m_introState;
	SimonWinSequenceState * m_winSequenceState;
	SimonFailState * m_failState;
	SimonWinGameState * m_winGameState;
	SimonPlayState * m_playStates[4];
	SimonTestState * m_testStates[4];
};

#endif /* SRC_STATES_SIMON_SIMONSTATE_H_ */
