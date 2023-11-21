#ifndef ch_455
#define ch_455

#include <Arduino.h>
#include "Wire.h"

class ch455
{
public:
	enum digitSegReadUnit_t
	{
		DIG0_SEG0 = 0x04,
		DIG0_SEG1 = 0x0c,
		DIG0_SEG2 = 0x14,
		DIG0_SEG3 = 0x1c,
		DIG0_SEG4 = 0x24,
		DIG0_SEG5 = 0x2c,
		DIG0_SEG6 = 0x34,
		DIG0_SEG0_1 = 0x3c,
		DIG1_SEG0 = 0x05,
		DIG1_SEG1 = 0x0d,
		DIG1_SEG2 = 0x15,
		DIG1_SEG3 = 0x1d,
		DIG1_SEG4 = 0x25,
		DIG1_SEG5 = 0x2d,
		DIG1_SEG6 = 0x35,
		DIG1_SEG0_1 = 0x3d,
		DIG2_SEG0 = 0x06,
		DIG2_SEG1 = 0x0e,
		DIG2_SEG2 = 0x16,
		DIG2_SEG3 = 0x1e,
		DIG2_SEG4 = 0x26,
		DIG2_SEG5 = 0x2e,
		DIG2_SEG6 = 0x36,
		DIG2_SEG0_1 = 0x3e,
		DIG3_SEG0 = 0x07,
		DIG3_SEG1 = 0x0f,
		DIG3_SEG2 = 0x17,
		DIG3_SEG3 = 0x1f,
		DIG3_SEG4 = 0x27,
		DIG3_SEG5 = 0x2f,
		DIG3_SEG6 = 0x37,
		DIG3_SEG0_1 = 0x3f,
	};

	ch455();
	void begin(uint8_t sda, uint8_t scl, uint8_t ledBrightness = 8, bool enabled = true, bool sleep = false, bool sevenSegment = false);
	void begin(uint8_t ledBrightness = 8, bool enabled = true, bool sleep = false, bool sevenSegment = false);
	void customDigit(uint8_t digit, bool seg0, bool seg1, bool seg2, bool seg3, bool seg4, bool seg5, bool seg6, bool seg7);
	void customDigit(uint8_t digit, uint8_t digitData);
	uint8_t readKeyboard();
	void digit(uint8_t digit, uint8_t number, bool dot = 0);
	void dotPosition(bool dot0, bool dot1 = 0, bool dot2 = 0, bool dot3 = 0);
	void show(uint8_t digit0, uint8_t digit1 = 0, uint8_t digit2 = 0, uint8_t digit3 = 0);
	void showWithDots(uint8_t digit0, bool dot0 = 0, uint8_t digit1 = 0, bool dot1 = 0, uint8_t digit2 = 0, bool dot2 = 0, uint8_t digit3 = 0, bool dot3 = 0);
	void configure(uint8_t brightness, bool enabled = true, bool sleep = false, bool sevenSegment = false);

private:
	void send(uint8_t id, uint8_t data);
	bool
		dotset = 0,
		dotP0,
		dotP1,
		dotP2,
		dotP3;
};

#endif
