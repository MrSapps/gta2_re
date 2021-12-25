#pragma once

#include <windows.h>
#include "types.hpp"


#pragma pack(push)
#pragma pack(1)
struct str_table_entry
{
    __int16 field_0_str_id;
    __int16 field_2_zone_idx;
    __int16 field_4_type;
    __int16 field_6;
    unsigned __int8 field_8_length;
};
#pragma pack(pop)

struct str_table_normalized
{
    __int16 field_0_string_count;
    __int16 field_2; // pad ?
    str_table_entry* field_4[999];
};

class frosty_pasteur_0xC1EA8
{
public:
    EXPORT void Load_512330(const char *pScrName);

    EXPORT void LoadStringTbl_5121E0(unsigned __int16 tableSize);

    EXPORT void GetScrFileName_5122D0();

    EXPORT void LoadSubScripts_5125F0();

    __int16 field_0;
    __int16 field_2;
    int field_4[96];
    __int16 field_184;
    __int16 field_186;
    int field_188[60];
    __int16 field_278;
    __int16 field_27A;
    BYTE field_27C[120];
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int field_310;
    int field_314;
    int field_318;
    int field_31C;
    int field_320;
    int field_324;
    int field_328;
    int field_32C;
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    char field_354;
    char field_355;
    __int16 field_356;
    __int16 field_358;
    __int16 field_35A;
    char field_35C_full_scr_file_name[256];
    char field_45C_scr_file_name[9];
    char field_465;
    char field_466;
    char field_467;
    int field_468;
    unsigned __int16 field_46C_base_pointers[6000];
    BYTE field_334C_script_data[65536];
    str_table_entry *field_1334C_strings;
    str_table_normalized* field_13350_pStringTbl;
    BYTE field_13354[620000];
    BYTE field_AA934[95232];
    __int16 field_C1D34[30];
    __int16 field_C1D70;
    __int16 field_C1D72[30];
    __int16 field_C1DAE;
    int field_C1DB0[31];
    char field_C1E2C;
    char field_C1E2D;
    char field_C1E2E;
    char field_C1E2F;
    char field_C1E30;
    char field_C1E31;
    WORD field_C1E32[32];
    __int16 field_C1E72;
    WORD field_C1E74[25];
    __int16 field_C1EA6;
};
