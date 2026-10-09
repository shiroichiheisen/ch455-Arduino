 # ch455 Arduino Library

This is a comprehensive Arduino library for interfacing with the CH455 7-segment LED display driver IC. It provides an easy-to-use interface for controlling the displays and reading key presses.
 ## Features

    Simple interface to set up and control CH455 based displays.
    Support for changing LED brightness.
    Capabilities to read key presses from a keypad connected to CH455.
    Functions to operate in either 7-segment or 8-segment mode.
    Power management through sleep mode functionality.

 ## Getting Started
 ### Installation

    Download or clone this repository to your local machine.
    Unzip and rename the folder to CH455 (if necessary).
    Move the CH455 folder into your Arduino libraries directory.
    Restart your Arduino IDE.

 ### Initialization
You need to include the ch455.h and create a CH455-object.
Since the I2C-bus is used, you also have to start the Wire-interface.
The display will be initialized by the first configure call.
```C++
#include <ch455.h>

ch455 display(Wire);

void setup() {
  Wire.begin(Scl,Sda);
 
  display.configure(uint8_t brightness,bool enabled, bool sleep, bool sevenSegment);
}
```

Brightness ranges from 1 (minimum) to 8 (maximum), with a default of 8 if unspecified.
 ### Displaying Numbers

Send digits to the display, optionally with decimal points:
 ```cpp 

void loop() {
display.digit(uint8_t digit, uint8_t number, bool dot); // With decimal point
// or
display.digit(uint8_t digit, uint8_t number); // Without decimal point
}
 ``` 
 ### Configuration

Adjust the display configuration at any time:
 ```cpp 

display.configure(uint8_t brightness, bool enabled, bool sleep, bool sevenSegment);
 ``` 
 ### Full Display Control

Control all digits and their respective decimal points:
 ```cpp 

display.showWithDots(uint8_t digit0, bool dot0, uint8_t digit1, bool dot1, uint8_t digit2, bool dot2, uint8_t digit3, bool dot3);
display.dotPosition(bool dot0, bool dot1, bool dot2, bool dot3);
display.show(uint8_t digit0, uint8_t digit1, uint8_t digit2, uint8_t digit3);
 ``` 
 ### Custom Characters

Create and display custom characters on the LED segments:
 ```cpp 

display.customDigit(uint8_t digit, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool dot);
display.customDigit(uint8_t digit, uint8_t digitData);
 ``` 
 ### Keypad Interaction

Read key presses when using CH455 with a keypad:
 ```cpp 

uint8_t keyboardData = display.readKeyboard();
 ``` 

Note: The library is designed to handle numeric displays and does not support alphabetic characters or other symbols.
 ## Contribute

Your contributions are welcome. Please feel free to submit pull requests or open issues to enhance the functionality of this library.

Enjoy building your projects with the CH455 Arduino Library!
