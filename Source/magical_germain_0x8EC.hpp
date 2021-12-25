#pragma once

#include <windows.h>

struct STexture;
struct sprite_index;

struct kanji_header
{
    char field_0_id[4];
    __int16 field_4_version;
};

struct kanji_0x10
{
    char field_0_v1;
    char field_1_v2;
    __int16 field_2_text_char;
    STexture *field_4_pTexture;
    sprite_index *field_8_sprt_index;
    int field_C_id;
};

struct kanji_0x2
{
    char field_0;
    char field_1;
};

struct kanji_0x20
{
    kanji_0x2 field_0[16];
};

class magical_germain_0x8EC
{
public:
    kanji_0x10 field_0[120];
    kanji_0x10 field_780[20];
    int field_8C0_count;
    WORD *field_8C4_pKidX;
    kanji_0x20 *field_8C8_pKBIT;
    int field_8CC_kidx_size_words;
    BYTE *field_8D0_pSprtData;
    sprite_index *field_8D4_sprite_index;
    STexture *field_8D8_pTexture;
    BYTE *field_8DC_pSprtData;
    sprite_index *field_8E0_sprite_index;
    STexture *field_8E4_pTexture;
    unsigned __int8 field_8E8_v1;
    char field_8E9_v2;
    __int16 field_8EA_pad;

    magical_germain_0x8EC();

    ~magical_germain_0x8EC();

    void sub_4D2B40();

    void sub_4D2090();

    int sub_4D29D0(unsigned __int16 a2);

    int sub_4D28A0(unsigned __int16 a2);


    STexture * sub_4D27D0(unsigned int *a2);

    STexture * sub_4D2710(unsigned int *a2);
};

extern magical_germain_0x8EC *gMagical_germain_0x8EC_6F5168;
