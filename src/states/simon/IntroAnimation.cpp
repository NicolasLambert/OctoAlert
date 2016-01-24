/*
 * IntroAnimation.cpp
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#include "IntroAnimation.h"

void IntroAnimation::activate() {
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_ALL, 0, 0, 255);
	OutputManager::getInstance()->m_octoAlertLeds->showNewColors();
}

void IntroAnimation::update() {
	// TODO Auto-generated constructor stub

}

