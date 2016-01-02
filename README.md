OctoAlert
=========

An OctoAlert device inspired by the TV show "The Octonauts"

You can found more informations here : http://bidouillesfactory.fr/tag/octoalert/

# Project IDE
I use Eclipse CDT with the plug-in "Arduino C++ IDE"
-> See https://marketplace.eclipse.org/content/arduino-c-ide

# Project structure

* **.project** the eclipse project description
* **.cproject** the eclipse C project description
* **.settings/** some eclipse variables
* **sd-card/** The content of the micro-SD card inserted into the mp3 shield
  * It contains some mp3 files but I cannot share that here because theses sounds are under some copyright protections.
  * So you have to create your own mp3 files.
  * Files names are :
    * Alert1.mp3
    * Captain1.mp3
    * CntDown1.mp3
    * Kwazii1.mp3
    * Peso1.mp3
    * Tweak1.mp3
  * You can put files with 1-9 as the last char and the application will play them sequentially for each button push.
* **libraries/** a copy of the Arduino library that I use for my project
  * **Adafruit_NeoPixel/** The official Neopixel lib from Adafruit : https://github.com/adafruit/Adafruit_NeoPixel
  * **Adafruit_VS1053/** The official mp3 shield lib from Adafruit : https://github.com/adafruit/Adafruit_VS1053_Library/
* **src/** My sources files
