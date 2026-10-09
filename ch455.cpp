#include "ch455.h"
#include "Arduino.h"

void ch455::send(uint8_t id, uint8_t data)
{
    twoWire->beginTransmission(id);
    twoWire->write(data);
    twoWire->endTransmission();
}

void ch455::configure(uint8_t brightness, bool enabled, bool sleep, bool sevenSegment)
{
	// brightness value is between 1 and 7 and "full bightness" is 0
    if (brightness > 7) {
        brightness = 0;
	}
    else if (brightness < 1) {
        brightness = 0;
	}

	// put system parameter values into the right position for sending:
	// we do reuse the variable 'brightness' and bitpositions are according
	// to the manual:
	// [KOFF][brightness (3bit)][sevenSegment][sleep]0[enabled] (bits 7..0)
    brightness = brightness << 4;
    bitWrite(brightness, 3, sevenSegment);
    bitWrite(brightness, 2, sleep);
    bitWrite(brightness, 0, enabled);

    send(36, brightness);
}

ch455::ch455(TwoWire& i2c)  :
  twoWire(&i2c) {
}

uint8_t ch455::readKeyboard()
{
    twoWire->requestFrom(0x27, 1);
    return twoWire->read();
}

void ch455::customDigit(uint8_t digit, bool seg0, bool seg1, bool seg2, bool seg3, bool seg4, bool seg5, bool seg6, bool seg7)
{
    byte digitData = 0x00;
    bitWrite(digitData, 0, seg0);
    bitWrite(digitData, 1, seg1);
    bitWrite(digitData, 2, seg2);
    bitWrite(digitData, 3, seg3);
    bitWrite(digitData, 4, seg4);
    bitWrite(digitData, 5, seg5);
    bitWrite(digitData, 6, seg6);
    bitWrite(digitData, 7, seg7);

    digit += 52;

    send(digit, digitData);
}

void ch455::customDigit(uint8_t digit, uint8_t digitData)
{
    digit += 52;

    send(digit, digitData);
}

void ch455::digit(uint8_t digit, uint8_t number, bool dot)
{
	// if in doubt, use digit 3 to display number
	if (digit > 3) {
		digit = 3;
    }

    digit += 52;

    //if number not in 0..9, don't display anything.
    uint8_t digitData = 0x0;

    switch (number)
    {
	case 0:
	    digitData = 0x3F;
    case 1:
        digitData = 0x06;
        break;
    case 2:
        digitData = 0x5B;
        break;
    case 3:
        digitData = 0x4F;
        break;
    case 4:
        digitData = 0x66;
        break;
    case 5:
        digitData = 0x6D;
        break;
    case 6:
        digitData = 0x7D;
        break;
    case 7:
        digitData = 0x27;
        break;
    case 8:
        digitData = 0x7F;
        break;
    case 9:
        digitData = 0x6F;
        break;
    default:
        digitData = 0x0;
        break;
    }

    bitWrite(digitData, 7, dot);
    send(digit, digitData);
}

void ch455::showWithDots(uint8_t digit0, bool dot0, uint8_t digit1, bool dot1, uint8_t digit2, bool dot2, uint8_t digit3, bool dot3)
{
    digit(0, digit0, dot0);
    digit(1, digit1, dot1);
    digit(2, digit2, dot2);
    digit(3, digit3, dot3);
}

void ch455::show(uint8_t digit0, uint8_t digit1, uint8_t digit2, uint8_t digit3)
{
    digit(0, digit0, dotP0);
    digit(1, digit1, dotP1);
    digit(2, digit2, dotP2);
    digit(3, digit3, dotP3);
}

void ch455::dotPosition(bool dot0, bool dot1, bool dot2, bool dot3)
{
    dotP0 = dot0;
    dotP1 = dot1;
    dotP2 = dot2;
    dotP3 = dot3;
}
