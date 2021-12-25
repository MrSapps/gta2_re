#pragma once

#include <windows.h>

struct STexture;

struct optimistic_moser
{
    BYTE *field_0_pPixelData;
    STexture *field_4_pTexture;
    __int16 field_8;
    __int16 field_A;
};

struct festive_hopper
{
    DWORD *field_0_pAlloc;
    unsigned __int16 field_4_item_alloc_count;
    unsigned __int16 field_6_count;
    int field_8_pal_type;
    int field_C_pal_type;
    char field_10_bDoFree;
    char field_11;
    char field_12;
    char field_13;

    void Free_5B9050();

    void Alloc_5B8E90(__int16 a2, __int16 a3, int a4, int a5);

    void sub_5B8F70();

    void LoadTextures_5B8F00();
};

struct sharp_pare_0x15D8
{
    STexture *field_0_textures1[1024];
    char field_1000_bFreeTextures2;
    char field_1001_bFreeTextures1;
    char field_1002;
    char field_1003;
    STexture *field_1004_textures2[48];
    optimistic_moser field_10C4[96];
    STexture *field_1544_pTexture;
    festive_hopper field_1548_unk;
    festive_hopper field_155C_unk;
    festive_hopper field_1570_unk;
    festive_hopper field_1584_unk;
    festive_hopper field_1598_unk;
    festive_hopper field_15AC_unk;
    festive_hopper field_15C0_unk;
    __int16 field_15D4_idx;
    __int16 field_15D6_pal_count;

    sharp_pare_0x15D8();

    ~sharp_pare_0x15D8();

    void sub_5B9350();

    void FreePals_5B9140();

    void LoadPals_5B90F0();

    void ReadTextures_5B92E0();

    void LoadTextures2_5B9180();
};

extern sharp_pare_0x15D8 *gSharp_pare_0x15D8_705064;
