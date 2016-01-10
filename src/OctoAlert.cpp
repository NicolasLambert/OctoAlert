#include "OctoAlert.h"

void setup() {
	// Init serial logging
	Serial.begin(9600);
	Serial.println("Start OctoAlert Device");

	// Init shield and neopixels
	InputManager::getInstance();
	OutputManager::getInstance();
}

void loop() {
	// Update state manager
	unsigned long currentTime = millis();
	InputManager::getInstance()->update(currentTime);
	OctoStateManager::getInstance()->update(currentTime);
	OutputManager::getInstance()->update(currentTime);
}
