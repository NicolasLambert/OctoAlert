/*
 * FailAnimation.cpp
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#include "FailAnimation.h"

void FailAnimation::activate() {
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_ALL, 255, 0, 0);
}

void FailAnimation::update() {
	// TODO Auto-generated constructor stub

}
