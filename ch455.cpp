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

    brightness -= 1;

    bitWrite(brightness, 4, bitRead(brightness, 0));
    bitWrite(brightness, 5, bitRead(brightness, 1));
    bitWrite(brightness, 6, bitRead(brightness, 2));

    bitWrite(brightness, 0, enabled);
    bitWrite(brightness, 1, 0);
    bitWrite(brightness, 2, sleep);
    bitWrite(brightness, 3, sevenSegment);
    bitWrite(brightness, 7, 0);

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

uint8_t *ch455::readKeyboard()
{
    Wire.requestFrom(0x4f, 1);
    uint8_t readKey = Wire.read();

    uint8_t digitRead = 0x00;
    bitWrite(digitRead, 0, bitRead(readKey, 0));
    bitWrite(digitRead, 1, bitRead(readKey, 1));

    uint8_t segRead = 0x00;
    bitWrite(segRead, 0, bitRead(readKey, 3));
    bitWrite(segRead, 1, bitRead(readKey, 4));
    bitWrite(segRead, 2, bitRead(readKey, 5));

    uint8_t keyPressed = bitRead(readKey, 6);

    uint8_t returnData[3] = {digitRead, segRead, keyPressed};

    return returnData;
}

void ch455::customDigit(uint8_t digit, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool dot)
{
    uint8_t digitData = 0x00;
    bitWrite(digitData, 0, a);
    bitWrite(digitData, 1, b);
    bitWrite(digitData, 2, c);
    bitWrite(digitData, 3, d);
    bitWrite(digitData, 4, e);
    bitWrite(digitData, 5, f);
    bitWrite(digitData, 6, g);
    bitWrite(digitData, 7, dot);

    uint8_t digitToSend = 0x00;
    bitWrite(digitToSend, 0, 0);
    bitWrite(digitToSend, 1, bitRead(digit, 0));
    bitWrite(digitToSend, 2, bitRead(digit, 1));
    bitWrite(digitToSend, 3, 1);
    bitWrite(digitToSend, 4, 0);
    bitWrite(digitToSend, 5, 1);
    bitWrite(digitToSend, 6, 1);
    bitWrite(digitToSend, 7, 0);

    send(digitToSend, digitData); // send data
}

void ch455::digit(uint8_t digit, uint8_t number, bool dot)
{
    uint8_t digitToSend = 0x00;
    bitWrite(digitToSend, 0, 0);
    bitWrite(digitToSend, 1, bitRead(digit, 0));
    bitWrite(digitToSend, 2, bitRead(digit, 1));
    bitWrite(digitToSend, 3, 1);
    bitWrite(digitToSend, 4, 0);
    bitWrite(digitToSend, 5, 1);
    bitWrite(digitToSend, 6, 1);
    bitWrite(digitToSend, 7, 0);

    uint8_t digitData = 0x3F; // zero by default

    switch (number)
    {
    case 1:
        digitData = 0x06; // one
        break;
    case 2:
        digitData = 0x5B; // two
        break;
    case 3:
        digitData = 0x4F; // three
        break;
    case 4:
        digitData = 0x66; // four
        break;
    case 5:
        digitData = 0x6D; // five
        break;
    case 6:
        digitData = 0x7D; // six
        break;
    case 7:
        digitData = 0x27; // seven
        break;
    case 8:
        digitData = 0x7F; // eight
        break;
    case 9:
        digitData = 0x6F; // nine
        break;
    }

    bitWrite(digitData, 7, dot); // dot

    send(digitToSend, digitData); // send data
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
    dotset = 1;
}