#ifndef ch_455
#define ch_455

#include <Arduino.h>
#include "Wire.h"

class ch455
{
public:
	ch455();
	void begin(uint8_t sda, uint8_t scl, uint8_t ledBrightness = 8);
	void begin(uint8_t ledBrightness = 8);
	void digit(uint8_t digit, uint8_t number, bool dot = 0);
	void dotPosition(bool dot0, bool dot1 = 0, bool dot2 = 0, bool dot3 = 0);
	void show(uint8_t digit0, uint8_t digit1 = 0, uint8_t digit2 = 0, uint8_t digit3 = 0);
	void showWithDots(uint8_t digit0, bool dot0 = 0, uint8_t digit1 = 0, bool dot1 = 0, uint8_t digit2 = 0, bool dot2 = 0, uint8_t digit3 = 0, bool dot3 = 0);
	void brightness(uint8_t brightness);

private:
	bool
		dotset = 0,
		dotP0,
		dotP1,
		dotP2,
		dotP3;
};

#endif
