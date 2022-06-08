#include "ch455.h"
#include "Wire.h"

ch455::ch455(int sda, int scl, int brightness)
{
    if (brightness > 8 || brightness < 1)
        brightness = 8;
    Wire.begin(sda, scl);
    switch (brightness)
    {
    case 1:
        Wire.beginTransmission(36);
        Wire.write(0x11);
        Wire.endTransmission();
        break;
    case 2:
        Wire.beginTransmission(36);
        Wire.write(0x21);
        Wire.endTransmission();
        break;
    case 3:
        Wire.beginTransmission(36);
        Wire.write(0x31);
        Wire.endTransmission();
        break;
    case 4:
        Wire.beginTransmission(36);
        Wire.write(0x41);
        Wire.endTransmission();
        break;
    case 5:
        Wire.beginTransmission(36);
        Wire.write(0x51);
        Wire.endTransmission();
        break;
    case 6:
        Wire.beginTransmission(36);
        Wire.write(0x61);
        Wire.endTransmission();
        break;
    case 7:
        Wire.beginTransmission(36);
        Wire.write(0x71);
        Wire.endTransmission();
        break;
    case 8:
        Wire.beginTransmission(36);
        Wire.write(0x01);
        Wire.endTransmission();
        break;
    }
}

void ch455::brightness(int brightness)
{
    if (brightness > 8 || brightness < 1)
        return;
    switch (brightness)
    {
    case 1:
        Wire.beginTransmission(36);
        Wire.write(0x11);
        Wire.endTransmission();
        break;
    case 2:
        Wire.beginTransmission(36);
        Wire.write(0x21);
        Wire.endTransmission();
        break;
    case 3:
        Wire.beginTransmission(36);
        Wire.write(0x31);
        Wire.endTransmission();
        break;
    case 4:
        Wire.beginTransmission(36);
        Wire.write(0x41);
        Wire.endTransmission();
        break;
    case 5:
        Wire.beginTransmission(36);
        Wire.write(0x51);
        Wire.endTransmission();
        break;
    case 6:
        Wire.beginTransmission(36);
        Wire.write(0x61);
        Wire.endTransmission();
        break;
    case 7:
        Wire.beginTransmission(36);
        Wire.write(0x71);
        Wire.endTransmission();
        break;
    case 8:
        Wire.beginTransmission(36);
        Wire.write(0x01);
        Wire.endTransmission();
        break;
    }
}

void ch455::d0(int digit0, int dot)
{
    if (digit0 > 9)
        return;
    if (!digit0)
    {
        if (dot)
        {
            Wire.beginTransmission(52);
            Wire.write(0xBF);
            Wire.endTransmission();
        }
        else
        {
            Wire.beginTransmission(52);
            Wire.write(0x3F);
            Wire.endTransmission();
        }
    }
    else
    {
        switch (digit0)
        {
        case 1:
            if (dot)
            {
                Wire.beginTransmission(52);
                Wire.write(0x86);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(52);
                Wire.write(0x06);
                Wire.endTransmission();
            }
            break;
        case 2:
            if (dot)
            {
                Wire.beginTransmission(52);
                Wire.write(0xDB);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(52);
                Wire.write(0x5B);
                Wire.endTransmission();
            }
            break;
        case 3:
            if (dot)
            {
                Wire.beginTransmission(52);
                Wire.write(0xCF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(52);
                Wire.write(0x4F);
                Wire.endTransmission();
            }
            break;
        case 4:
            if (dot)
            {
                Wire.beginTransmission(52);
                Wire.write(0xE6);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(52);
                Wire.write(0x66);
                Wire.endTransmission();
            }
            break;
        case 5:
            if (dot)
            {
                Wire.beginTransmission(52);
                Wire.write(0xED);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(52);
                Wire.write(0x6D);
                Wire.endTransmission();
            }
            break;
        case 6:
            if (dot)
            {
                Wire.beginTransmission(52);
                Wire.write(0xFD);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(52);
                Wire.write(0x7D);
                Wire.endTransmission();
            }
            break;
        case 7:
            if (dot)
            {
                Wire.beginTransmission(52);
                Wire.write(0xA7);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(52);
                Wire.write(0x27);
                Wire.endTransmission();
            }
            break;
        case 8:
            if (dot)
            {
                Wire.beginTransmission(52);
                Wire.write(0xFF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(52);
                Wire.write(0x7F);
                Wire.endTransmission();
            }
            break;
        case 9:
            if (dot)
            {
                Wire.beginTransmission(52);
                Wire.write(0xEF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(52);
                Wire.write(0x6F);
                Wire.endTransmission();
            }
            break;
        }
    }
}

void ch455::d1(int digit1, int dot)
{
    if (digit1 > 9)
        return;
    if (!digit1)
    {
        if (dot)
        {
            Wire.beginTransmission(53);
            Wire.write(0xBF);
            Wire.endTransmission();
        }
        else
        {
            Wire.beginTransmission(53);
            Wire.write(0x3F);
            Wire.endTransmission();
        }
    }
    else
    {
        switch (digit1)
        {
        case 1:
            if (dot)
            {
                Wire.beginTransmission(53);
                Wire.write(0x86);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(53);
                Wire.write(0x06);
                Wire.endTransmission();
            }
            break;
        case 2:
            if (dot)
            {
                Wire.beginTransmission(53);
                Wire.write(0xDB);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(53);
                Wire.write(0x5B);
                Wire.endTransmission();
            }
            break;
        case 3:
            if (dot)
            {
                Wire.beginTransmission(53);
                Wire.write(0xCF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(53);
                Wire.write(0x4F);
                Wire.endTransmission();
            }
            break;
        case 4:
            if (dot)
            {
                Wire.beginTransmission(53);
                Wire.write(0xE6);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(53);
                Wire.write(0x66);
                Wire.endTransmission();
            }
            break;
        case 5:
            if (dot)
            {
                Wire.beginTransmission(53);
                Wire.write(0xED);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(53);
                Wire.write(0x6D);
                Wire.endTransmission();
            }
            break;
        case 6:
            if (dot)
            {
                Wire.beginTransmission(53);
                Wire.write(0xFD);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(53);
                Wire.write(0x7D);
                Wire.endTransmission();
            }
            break;
        case 7:
            if (dot)
            {
                Wire.beginTransmission(53);
                Wire.write(0xA7);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(53);
                Wire.write(0x27);
                Wire.endTransmission();
            }
            break;
        case 8:
            if (dot)
            {
                Wire.beginTransmission(53);
                Wire.write(0xFF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(53);
                Wire.write(0x7F);
                Wire.endTransmission();
            }
            break;
        case 9:
            if (dot)
            {
                Wire.beginTransmission(53);
                Wire.write(0xEF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(53);
                Wire.write(0x6F);
                Wire.endTransmission();
            }
            break;
        }
    }
}

void ch455::d2(int digit2, int dot)
{
    if (digit2 > 9)
        return;
    if (!digit2)
    {
        if (dot)
        {
            Wire.beginTransmission(54);
            Wire.write(0xBF);
            Wire.endTransmission();
        }
        else
        {
            Wire.beginTransmission(54);
            Wire.write(0x3F);
            Wire.endTransmission();
        }
    }
    else
    {
        switch (digit2)
        {
        case 1:
            if (dot)
            {
                Wire.beginTransmission(54);
                Wire.write(0x86);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(54);
                Wire.write(0x06);
                Wire.endTransmission();
            }
            break;
        case 2:
            if (dot)
            {
                Wire.beginTransmission(54);
                Wire.write(0xDB);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(54);
                Wire.write(0x5B);
                Wire.endTransmission();
            }
            break;
        case 3:
            if (dot)
            {
                Wire.beginTransmission(54);
                Wire.write(0xCF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(54);
                Wire.write(0x4F);
                Wire.endTransmission();
            }
            break;
        case 4:
            if (dot)
            {
                Wire.beginTransmission(54);
                Wire.write(0xE6);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(54);
                Wire.write(0x66);
                Wire.endTransmission();
            }
            break;
        case 5:
            if (dot)
            {
                Wire.beginTransmission(54);
                Wire.write(0xED);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(54);
                Wire.write(0x6D);
                Wire.endTransmission();
            }
            break;
        case 6:
            if (dot)
            {
                Wire.beginTransmission(54);
                Wire.write(0xFD);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(54);
                Wire.write(0x7D);
                Wire.endTransmission();
            }
            break;
        case 7:
            if (dot)
            {
                Wire.beginTransmission(54);
                Wire.write(0xA7);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(54);
                Wire.write(0x27);
                Wire.endTransmission();
            }
            break;
        case 8:
            if (dot)
            {
                Wire.beginTransmission(54);
                Wire.write(0xFF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(54);
                Wire.write(0x7F);
                Wire.endTransmission();
            }
            break;
        case 9:
            if (dot)
            {
                Wire.beginTransmission(54);
                Wire.write(0xEF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(54);
                Wire.write(0x6F);
                Wire.endTransmission();
            }
            break;
        }
    }
}

void ch455::d3(int digit3, int dot)
{
    if (digit3 > 9)
        return;
    if (!digit3)
    {
        if (dot)
        {
            Wire.beginTransmission(55);
            Wire.write(0xBF);
            Wire.endTransmission();
        }
        else
        {
            Wire.beginTransmission(55);
            Wire.write(0x3F);
            Wire.endTransmission();
        }
    }
    else
    {
        switch (digit3)
        {
        case 1:
            if (dot)
            {
                Wire.beginTransmission(55);
                Wire.write(0x86);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(55);
                Wire.write(0x06);
                Wire.endTransmission();
            }
            break;
        case 2:
            if (dot)
            {
                Wire.beginTransmission(55);
                Wire.write(0xDB);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(55);
                Wire.write(0x5B);
                Wire.endTransmission();
            }
            break;
        case 3:
            if (dot)
            {
                Wire.beginTransmission(55);
                Wire.write(0xCF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(55);
                Wire.write(0x4F);
                Wire.endTransmission();
            }
            break;
        case 4:
            if (dot)
            {
                Wire.beginTransmission(55);
                Wire.write(0xE6);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(55);
                Wire.write(0x66);
                Wire.endTransmission();
            }
            break;
        case 5:
            if (dot)
            {
                Wire.beginTransmission(55);
                Wire.write(0xED);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(55);
                Wire.write(0x6D);
                Wire.endTransmission();
            }
            break;
        case 6:
            if (dot)
            {
                Wire.beginTransmission(55);
                Wire.write(0xFD);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(55);
                Wire.write(0x7D);
                Wire.endTransmission();
            }
            break;
        case 7:
            if (dot)
            {
                Wire.beginTransmission(55);
                Wire.write(0xA7);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(55);
                Wire.write(0x27);
                Wire.endTransmission();
            }
            break;
        case 8:
            if (dot)
            {
                Wire.beginTransmission(55);
                Wire.write(0xFF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(55);
                Wire.write(0x7F);
                Wire.endTransmission();
            }
            break;
        case 9:
            if (dot)
            {
                Wire.beginTransmission(55);
                Wire.write(0xEF);
                Wire.endTransmission();
            }
            else
            {
                Wire.beginTransmission(55);
                Wire.write(0x6F);
                Wire.endTransmission();
            }
            break;
        }
    }
}

void ch455::show(int digit0, int dot0, int digit1, int dot1, int digit2, int dot2, int digit3, int dot3)
{
    d0(digit0, dot0);
    d1(digit1, dot1);
    d2(digit2, dot2);
    d3(digit3, dot3);
}

void ch455::show(int digit0, int digit1, int digit2, int digit3)
{
    if (!dotset)
    {
        Serial.println("Dot not set");
        return;
    }
    d0(digit0, dotP0);
    d1(digit1, dotP1);
    d2(digit2, dotP2);
    d3(digit3, dotP3);
}

void ch455::dotPosition(int dot0, int dot1, int dot2, int dot3)
{
    dotP0 = dot0;
    dotP1 = dot1;
    dotP2 = dot2;
    dotP3 = dot3;
    dotset = 1;
}