# ch455 Arduino

Library for using the ch455 ic with arduino;

## ☕ Using this library

To use this library, you need to download, install the library, and include the following file in your project:

```
#include <ch455.h>
```

To use on your code you need to declare the ch455 object with the sda pin, scl pin and led brightness:

```	
ch455 display(int sda, int scl, int brightness, int frequency);
//max brightness is 8, min brightness is 1
//If the brightness is not set, the default brightness is 8
//Frequency is the frequency of the i2c comunication in Hz, default is 100000Hz
```

Now to send numbers to the display you can use the following functions:

```	
display.d0(int number, int dot);
display.d1(int number, int dot);
display.d2(int number, int dot);
display.d3(int number, int dot);

//number is the number to show on display
//dot is if you want to show a dot or not with the number
//if you dont use the dot on display, just dont send it:

display.d0(int number);
display.d1(int number);
display.d2(int number);
display.d3(int number);
```

To change the brightness of the display you can use the following function:

```	
display.brightness(int brightness);
//max brightness is 8, min brightness is 1
```

To send to all numbers of the display you can use the following function:

```	
display.showWithDots(int digit0, int dot0, int digit1, int dot1, int digit2, int dot2, int digit3, int dot3);
```

If you want so set the dot of all numbers use the following function:

```	
display.dotPosition(int dot0, int dot1, int dot2, int dot3);
```

Now with the dot position set you can call the show function without need to set the dot of each number:

```	
display.show(int digit0, int digit1, int digit2, int digit3);
```

If you use less than 4 digits on your ch455 display, you dont need to set the digit or dot of each digit, only the first digit and dot (depending on the function) is obligatory

This library only show numbers, dont show letters, dont show symbols, dont show anything else.