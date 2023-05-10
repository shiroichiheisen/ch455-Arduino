#include "ch455.h"
#include "Wire.h"

void send(uint8_t id, uint8_t data)
{
    Wire.beginTransmission(id);
    Wire.write(data);
    Wire.endTransmission();
}

void ch455::brightness(uint8_t brightness)
{
    if (brightness > 8)
        brightness = 8;
    else if (brightness < 1)
        brightness = 1;

    uint8_t bright = 1;

    if (brightness < 8)
        bright += (16 * brightness);

    send(36, bright);
}

ch455::ch455() {}

void ch455::begin(uint8_t brightness)
{
    Wire.begin();
    ch455::brightness(brightness);
}

void ch455::begin(uint8_t sda, uint8_t scl, uint8_t brightness)
{
    Wire.begin(sda, scl);
    ch455::brightness(brightness);
}

void ch455::digit(uint8_t digit, uint8_t number, bool dot)
{
    if (number > 9 || digit > 3)
    {
        Serial.println("CH455 Library: Number or digit is too big, max 9 for number and max 3 for digit");
        return;
    }

    uint8_t digitId = 52 + digit;

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
    send(digitId, digitData);
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