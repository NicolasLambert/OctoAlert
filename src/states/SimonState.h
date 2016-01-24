/*
 * SimonState.h
 *
 *  Created on: 15 juil. 2014
 *      Author: nicolaslambert
 */

#ifndef SIMONSTATE_H_
#define SIMONSTATE_H_

#include "SoundState.h"
#include "../io/input/InputManager.h"
#include "../../Libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

// Durations
#define STEP_INTERVAL 1000
#define STEP_TO_WIN_COUNT 5

// Simon states
#define STATE_INTRO 0
#define STATE_PLAY 1
#define STATE_TEST 2
#define STATE_WIN_SEQ 3
#define STATE_FAIL 4
#define STATE_WIN_GAME 5
#define STATE_END 6

// SOUND Ids
#define SOUND_ID_WIN_SEQ 5
#define SOUND_ID_FAIL 6
#define SOUND_ID_WIN_GAME 7

//typedef void(*LightActivator)(OctoAlertLeds*);

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
	void playResult(bool isWin);
	void playWinGame();
//	void play(uint8_t soundId, LightActivator lightActivator);
	const uint32_t m_colors[4];
	const uint8_t m_buttonByQuarter[4];
	uint8_t m_musicScore[STEP_TO_WIN_COUNT];
	int8_t m_nextScoreStep;
	int8_t m_lastSuccessfullScoreStep;
	unsigned long m_lastScoreStepTime;
	uint8_t m_currentState;
};

#endif /* SIMONSTATE_H_ */
