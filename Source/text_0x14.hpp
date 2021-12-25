#pragma once

#include "types.hpp"
#include <windows.h>

struct text_0xC
{
    wchar_t* field_0_pwstr;
    const char* field_4_pKey;
    int field_8;
};


struct gtx_header
{
    char field_0_gbl_code[4];
    __int16 field_4_version;
};

struct text_tdat
{
    BYTE *field_0_data;
    int field_4_len;
    EXPORT void TDAT_Load_5B5A80(unsigned int size);
};


class text_0x14
{
public:
    text_0xC *field_0_tKey;
    int field_4_tKey_count;
    text_tdat field_8_tDat;
    char field_10_lang_code;
    char field_11_pad[3];

    EXPORT unsigned __int16 sub_5B58D0(unsigned __int16 a2);

    EXPORT void sub_5B5910(WORD *a2);

    EXPORT void sub_5B5930(WORD *a1);

    EXPORT void TKEY_Load_5B5960(unsigned int size);

    EXPORT void TDAT_Offsets2Strings_5B59B0(BYTE *pDat);

    EXPORT bool TKeyFind_5B59E0(const char *pIdStr);

    EXPORT static int __cdecl TKeySearch_5B5A10(const void* a, const void* b);

    EXPORT wchar_t *TKeyFind_5B5A50(const char *pIdStr);

    EXPORT unsigned __int16 sub_5B5AD0(wchar_t a2);

    EXPORT wchar_t *sub_5B5B80(wchar_t *pWideStr);

    EXPORT int __stdcall sub_5B5BC0(WORD *a1, int a2, int a3, int a4);

    EXPORT char * Wide2PesudoAscii_5B5D10(WORD *a1);

    EXPORT wchar_t *Ascii2Wide_5B5DF0(char *a1);

    EXPORT void load_chunk_5B5E20(const char *chunk_type, unsigned int chunk_len);

    EXPORT void Load_5B5E90();

    EXPORT wchar_t *Find_5B5F90(const char *pIdStr);

    EXPORT bool sub_5B5FA0(const char *pIdStr);

    // 0x5B5FB0
    EXPORT text_0x14();

    // 0x5B6050
    EXPORT ~text_0x14();
};

extern text_0x14* gText_0x14_704DFC;
