#pragma once

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
    void TDAT_Load_5B5A80(int size);
};


class text_0x14
{
public:
    text_0xC *field_0_tKey;
    int field_4_tKey_count;
    text_tdat field_8_tDat;
    char field_10_lang_code;
    char field_11_pad[3];

    unsigned __int16 sub_5B58D0(unsigned __int16 a2);

    void sub_5B5910(WORD *a2);

    void sub_5B5930(WORD *a1);

    void TKEY_Load_5B5960(int size);

    void TDAT_Offsets2Strings_5B59B0(BYTE *pDat);

    bool TKeyFind_5B59E0(const char *pIdStr);

    static int __cdecl TKeySearch_5B5A10(const void* a, const void* b);

    wchar_t *TKeyFind_5B5A50(const char *pIdStr);

    unsigned __int16 sub_5B5AD0(unsigned __int16 a2);

    WORD *sub_5B5B80(WORD *pWideStr);

    int __stdcall sub_5B5BC0(WORD *a1, int a2, int a3, int a4);

    char * Wide2PesudoAscii_5B5D10(WORD *a1);

    wchar_t *Ascii2Wide_5B5DF0(char *a1);

    void load_chunk_5B5E20(const char *chunk_type, int chunk_len);

    void Load_5B5E90();

    wchar_t *Find_5B5F90(const char *pIdStr);

    bool sub_5B5FA0(const char *pIdStr);

    // 0x5B5FB0
    text_0x14();

    // 0x5B6050
    ~text_0x14();
};
