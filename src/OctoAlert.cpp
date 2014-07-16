#include "OctoAlert.h"

void setup() {
	// Init serial logging
	Serial.begin(9600);
	Serial.println("Start OctoAlert Device");

	// Init shield and neopixels
	IOManager::getInstance();
}

void loop() {
	// Update state manager
	OctoStateManager::getInstance()->update(millis());
}
