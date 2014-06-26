// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _OctoAlert_H_
#define _OctoAlert_H_
#include "Arduino.h"
//add your includes for the project OctoAlert here
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>
#include <Adafruit_NeoPixel.h>


// define the pins used
//#define CLK 13       // SPI Clock, shared with SD card
//#define MISO 12      // Input data, from VS1053/SD card
//#define MOSI 11      // Output data, to VS1053/SD card
// Connect CLK, MISO and MOSI to hardware SPI pins.
// See http://arduino.cc/en/Reference/SPI "Connections"

// These are the pins used for the breakout example
#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
// These are the pins used for the music maker shield
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

#define PIN 10

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project OctoAlert here

void colorWipe(uint32_t c);
void blink();


//Do not add code below this line
#endif /* _OctoAlert_H_ */
