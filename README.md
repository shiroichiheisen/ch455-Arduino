# ch455 Arduino

Library for using the ch455 ic with arduino;

## ☕ Using this library

To use this library, you need to download, install the library, and include the following file in your project:

```
#include <ch455.h>
```

To use on your code you need to declare the ch455 object and begin with the sda pin, scl pin and led brightness:

```	
ch455 display;

setup{
display.begin(uint8_t sda, uint8_t scl, uint8_t brightness); //if you want to change sda and scl pins
display.begin(uint8_t brightness); //for attiny devices or if you dont want to change sda and scl pins
}

//max brightness is 8, min brightness is 1
//If the brightness is not set, the default brightness is 8
```

You also can enable the ch455, make the mcu enter in sleep mode and change the 8 segment mode to 7 segment mode with the following functions:

```
display.begin(uint8_t sda, uint8_t scl, uint8_t brightness, bool enabled, bool sleep, bool sevenSegment);
display.begin(uint8_t brightness, bool enabled, bool sleep, bool sevenSegment); 
```


Now to send numbers to the display you can use the following functions:

```	
display.digit(uint8_t digit, uint8_t number, bool dot);

//digit is the digit on the display
//number is the number to show on display
//dot is if you want to show a dot or not with the number
//if you dont use the dot on display, just dont send it:

display.digit(uint8_t digit, uint8_t number);
```

To configure the CH455 just use the following function:

```	
display.configure(uint8_t brightness, bool enabled, bool sleep, bool sevenSegment);
//max brightness is 8, min brightness is 1
```

To send to all numbers of the display you can use the following function:

```	
display.showWithDots(uint8_t digit0, bool dot0, uint8_t digit1, bool dot1, uint8_t digit2, bool dot2, uint8_t digit3, bool dot3);
```

If you want so set the dot of all numbers use the following function:

```	
display.dotPosition(bool dot0, bool dot1, bool dot2, bool dot3);
```

Now with the dot position set you can call the show function without need to set the dot of each number:

```	
display.show(uint8_t digit0, uint8_t digit1, uint8_t digit2, uint8_t digit3);
```

If you want to send a custom number to the display you can use the following function:

```
display.custom(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool dot);
```

Now we have the readKey function, this function read the key pressed on the keypad:

```
display.readKeyboard();
//Use the enum to get the key pressed Ex: if the key on the DIG0 and Seg 5 is pressed, the function will return the enum ch455::DIG0_SEG5
```


If you use less than 4 digits on your ch455 display, you dont need to set the digit or dot of each digit, only the first digit and dot (depending on the function) is obligatory

This library only show numbers, dont show letters, dont show symbols, dont show anything else.