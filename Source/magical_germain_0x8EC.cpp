#include "magical_germain_0x8EC.hpp"

magical_germain_0x8EC *gMagical_germain_0x8EC_6F5168;

// nomatch 0x4D2C80
magical_germain_0x8EC::magical_germain_0x8EC()
{
    field_8E8_v1 = -2;
    field_8E9_v2 = -9;
    field_8C8_pKBIT = 0;
    field_8C4_pKidX = 0;
    field_8CC_kidx_size_words = 0;
    field_8C0_count = 0;
    sub_4D2090();
}

// nomatch 0x4D2CC0
magical_germain_0x8EC::~magical_germain_0x8EC()
{
    if (field_8C8_pKBIT)
    {
        delete field_8C8_pKBIT;
    }

    if (field_8C4_pKidX)
    {
        delete field_8C4_pKidX;
    }

    field_8CC_kidx_size_words = 0;
}

// stub
void magical_germain_0x8EC::sub_4D2B40()
{
    // todo
}

// stub
void magical_germain_0x8EC::sub_4D2090()
{
    // todo
}

// stub
int magical_germain_0x8EC::sub_4D29D0(unsigned __int16 a2)
{
    return 0;
}

// stub
int magical_germain_0x8EC::sub_4D28A0(unsigned __int16 a2)
{
    return 0;
}

// stub
STexture * magical_germain_0x8EC::sub_4D27D0(unsigned int *a2)
{
    return 0;
}

// stub
STexture * magical_germain_0x8EC::sub_4D2710(unsigned int *a2)
{
    return 0;
}
