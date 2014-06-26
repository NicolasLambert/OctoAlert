// Do not remove the include below
#include "OctoAlert.h"

Adafruit_VS1053_FilePlayer musicPlayer =
  // create breakout-example object!
  //Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);
  // create shield-example object!
  Adafruit_VS1053_FilePlayer(SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(40, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.


void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Simple Test");

/*  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("VS1053 found"));

  SD.begin(CARDCS);    // initialise the SD card
*/
  // Set volume for left, right channels. lower numbers == louder volume!
//  musicPlayer.setVolume(20,20);
//  musicPlayer.setVolume(0,0);

  // Timer interrupts are not suggested, better to use DREQ interrupt!
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int

  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
//  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int

  // Play one file, don't return until complete
 // Serial.println(F("Playing HTH.mp3"));
//  musicPlayer.playFullFile("HTH.mp3");
  // Play another file in the background, REQUIRES interrupts!
//  Serial.println(F("Playing track 002"));
//  musicPlayer.startPlayingFile("track002.mp3");

  strip.begin();
  strip.setBrightness(70);
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  // File is playing in the background
/*  if (musicPlayer.stopped()) {
    Serial.println("Done playing music");
    while (1);
  }
  if (Serial.available()) {
    char c = Serial.read();

    // if we get an 's' on the serial console, stop!
    if (c == 's') {
      musicPlayer.stopPlaying();
    }

    // if we get an 'p' on the serial console, pause/unpause!
    if (c == 'p') {
      if (! musicPlayer.paused()) {
        Serial.println("Paused");
        musicPlayer.pausePlaying(true);
      } else {
        Serial.println("Resumed");
        musicPlayer.pausePlaying(false);
      }
    }
  }

  delay(100);
*/

  // Some example procedures showing how to display to the pixels:
	  colorWipe(strip.Color(44, 74, 234)); // Blue
	  delay(3000);
	  colorWipe(strip.Color(233, 110, 29)); // Orange
	  blink();
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
  }
  strip.show();
}


// Fill the dots one after the other with a color
void blink() {
	unsigned int min = 20;
	unsigned int max = 70;
	for (int j = 0; j<5; j++) {
		  for(uint16_t i=max; i>min; i--) {
		      strip.setBrightness(i);
		      strip.show();
		      delay(10);
		  }
	  for(uint16_t i=min; i<max; i++) {
	      strip.setBrightness(i);
	      strip.show();
	      delay(10);
	  }
	}
}
