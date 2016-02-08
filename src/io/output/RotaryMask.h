/*
 * RotaryMask.h
 *
 *  Created on: 8 févr. 2016
 *      Author: nicolas
 */

#ifndef SRC_IO_OUTPUT_ROTARYMASK_H_
#define SRC_IO_OUTPUT_ROTARYMASK_H_

#include "LedMapping.h"

class RotaryMask {
public:
	RotaryMask(uint64_t mask, uint8_t waitingTicks, uint16_t rotationCount = 0);
	uint64_t getValue();
	void rotate();
	void reset();
	bool isFinished();
private:
	void rotateRing(uint8_t &waitingCounter, uint8_t waitingTicks, uint64_t rotationLocationMask);
	void rotateMask(uint64_t &colorMaskToRotate, uint64_t rotationLocationMask);
	uint64_t m_currentMask;
	uint64_t m_startingMask;
	uint8_t m_baseWaitingTicks;
	uint8_t m_waitingCountBigRing;
	uint8_t m_waitingCountLittleRing;
	const uint16_t m_maxRotationCount;
	uint16_t m_currentRotationCount;
};

#endif /* SRC_IO_OUTPUT_ROTARYMASK_H_ */
