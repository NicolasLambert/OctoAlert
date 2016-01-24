/*
 * WinGameAnimation.cpp
 *
 *  Created on: 24 janv. 2016
 *      Author: nicolas
 */

#include "WinGameAnimation.h"

void WinGameAnimation::activate() {
	OutputManager::getInstance()->m_octoAlertLeds->setColor(LED_MASK_ALL, 0, 255, 0);
	OutputManager::getInstance()->m_octoAlertLeds->showNewColors();
}

void WinGameAnimation::update() {
	// TODO Auto-generated constructor stub

}

