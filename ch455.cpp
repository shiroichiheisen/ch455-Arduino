#include "ch455.h"
#include "Wire.h"

void send(uint8_t id, uint8_t data)
{
    Wire.beginTransmission(id);
    Wire.write(data);
    Wire.endTransmission();
}

void ch455::configure(uint8_t brightness, bool enabled, bool sleep, bool sevenSegment)
{
    if (brightness > 8)
        brightness = 8;
    else if (brightness < 1)
        brightness = 1;

    if (brightness < 8)
        brightness = (16 * brightness);

    bitWrite(brightness, 0, enabled);
    bitWrite(brightness, 2, sleep);
    bitWrite(brightness, 3, sevenSegment);

    send(36, brightness);
}

ch455::ch455() {}

void ch455::begin(uint8_t brightness, bool enabled, bool sleep, bool sevenSegment)
{
    Wire.begin();
    ch455::configure(brightness);
}

void ch455::begin(uint8_t sda, uint8_t scl, uint8_t brightness, bool enabled, bool sleep, bool sevenSegment)
{
    Wire.begin(sda, scl);
    ch455::configure(brightness);
}

uint8_t ch455::readKeyboard()
{
    Wire.requestFrom(0x4f, 1);
    return Wire.read();
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
    if (number > 9 || digit > 3)
    {
        Serial.println("CH455 Library: Number or digit is too big, max 9 for number and max 3 for digit");
        return;
    }

    digit += 52;

    uint8_t digitData = 0x3F;

    switch (number)
    {
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
    if (!dotset)
    {
        Serial.println("CH455 Library: Please set dot position first.");
        return;
    }
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
    dotset = 1;
}
