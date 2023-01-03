#include "ch455.h"
#include "Wire.h"

void send(int id, int data)
{
    Wire.beginTransmission(id);
    Wire.write(data);
    Wire.endTransmission();
}

void ch455::brightness(int brightness)
{
    if (brightness > 8)
        brightness = 8;
    else if (brightness < 1)
        brightness = 1;
    switch (brightness)
    {
    case 1:
        send(36, 0x11);
        break;
    case 2:
        send(36, 0x21);
        break;
    case 3:
        send(36, 0x31);
        break;
    case 4:
        send(36, 0x41);
        break;
    case 5:
        send(36, 0x51);
        break;
    case 6:
        send(36, 0x61);
        break;
    case 7:
        send(36, 0x71);
        break;
    case 8:
        send(36, 0x01);
        break;
    }
}

ch455::ch455() {}

void ch455::begin(int brightness)
{
    Wire.begin();
    ch455::brightness(brightness);
}

void ch455::begin(int sda, int scl, int brightness)
{
    Wire.begin(sda, scl);
    ch455::brightness(brightness);
}

void ch455::digit(int digit, int number, int dot)
{
    if (number > 9)
        Serial.println("Number is too big, max is 9");

    int digitId;

    switch (digit)
    {
    case 0:
        digitId = 52;
        break;
    case 1:
        digitId = 53;
        break;
    case 2:
        digitId = 54;
        break;
    case 3:
        digitId = 55;
        break;
    }

    if (!number)
    {
        if (dot)
            send(digitId, 0xBF);
        else
            send(digitId, 0x3F);
    }
    else
    {
        switch (number)
        {
        case 1:
            if (dot)
                send(digitId, 0x86);
            else
                send(digitId, 0x06);
            break;
        case 2:
            if (dot)
                send(digitId, 0xDB);
            else
                send(digitId, 0x5B);
            break;
        case 3:
            if (dot)
                send(digitId, 0xCF);
            else
                send(digitId, 0x4F);
            break;
        case 4:
            if (dot)
                send(digitId, 0xE6);
            else
                send(digitId, 0x66);
            break;
        case 5:
            if (dot)
                send(digitId, 0xED);
            else
                send(digitId, 0x6D);
            break;
        case 6:
            if (dot)
                send(digitId, 0xFD);
            else
                send(digitId, 0x7D);
            break;
        case 7:
            if (dot)
                send(digitId, 0xA7);
            else
                send(digitId, 0x27);
            break;
        case 8:
            if (dot)
                send(digitId, 0xFF);
            else
                send(digitId, 0x7F);
            break;
        case 9:
            if (dot)
                send(digitId, 0xEF);
            else
                send(digitId, 0x6F);
            break;
        }
    }
}

void ch455::showWithDots(int digit0, int dot0, int digit1, int dot1, int digit2, int dot2, int digit3, int dot3)
{
    digit(0, digit0, dot0);
    digit(1, digit1, dot1);
    digit(2, digit2, dot2);
    digit(3, digit3, dot3);
}

void ch455::show(int digit0, int digit1, int digit2, int digit3)
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

void ch455::dotPosition(int dot0, int dot1, int dot2, int dot3)
{
    dotP0 = dot0;
    dotP1 = dot1;
    dotP2 = dot2;
    dotP3 = dot3;
    dotset = 1;
}