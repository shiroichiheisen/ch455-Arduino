#ifndef ch_455
#define ch_455

#include <Arduino.h>
#include "Wire.h"

class ch455
{
public:
	ch455(int sda, int scl, int ledBrightness = 8, int frequency = 100000);
	void d0(int digit0, int dot = 0);
	void d1(int digit1, int dot = 0);
	void d2(int digit2, int dot = 0);
	void d3(int digit3, int dot = 0);
	void dotPosition(int dot0, int dot1 = 0, int dot2 = 0, int dot3 = 0);
	void show(int digit0, int digit1 = 0, int digit2 = 0, int digit3 = 0);
	void showWithDots(int digit0, int dot0 = 0, int digit1 = 0, int dot1 = 0, int digit2 = 0, int dot2 = 0, int digit3 = 0, int dot3 = 0);
	void brightness(int brightness);

private:
	int
		dotset = 0,
		dotP0,
		dotP1,
		dotP2,
		dotP3,
		dg0,
		dg1,
		dg2,
		dg3;
};

#endif
