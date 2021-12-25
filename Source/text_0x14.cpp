#include "text_0x14.hpp"
#include "registry.hpp"
#include "file.hpp"
#include "error.hpp"
#include "chunk.hpp"

extern char gTmpBuffer_67C598[256];

char byte_70488C[1280];

char byte_70462C[80];

// todo
unsigned __int16 text_0x14::sub_5B58D0(unsigned __int16 a2)
{
    // todo
    /*
    unsigned __int16 result; // ax

    result = a2;
    if (a2 >= 128u)
    {
        if (a2 >= 256u)
        {
            return 63;
        }

        result = this->field_10_lang_code == 'r' ? word_626390[a2] : *(WORD *)&aCSplittingGta2_27[2 * a2 + 24];
        if (!result)
        {
            return 63;
        }
    }
    return result;
    */
    return 0;
}

// match
void text_0x14::sub_5B5910(WORD *a2)
{
    if (field_10_lang_code != 'j')
    {
        sub_5B5930(a2);
    }
}

// todo
unsigned __int16 text_0x14::sub_5B5930(WORD *a1)
{
    WORD *v2; // esi
    unsigned __int16 result; // ax

    v2 = a1;
    for (result = *a1; result; ++v2)
    {
        *v2 = sub_5B58D0(result);
        result = v2[1];
    }
    return result;
}

// match
void text_0x14::TKEY_Load_5B5960(int chunkSize)
{
    field_4_tKey_count = chunkSize / sizeof(text_0xC);
    field_0_tKey = new text_0xC[field_4_tKey_count];
    if (!field_0_tKey)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\text.cpp", 218);
    }

    File::Global_Read_4A71C0(field_0_tKey, &chunkSize);
}

// match
void text_0x14::TDAT_Offsets2Strings_5B59B0(BYTE *pDat)
{
    text_0xC* ptKeyIter = field_0_tKey;
    
    for (unsigned int idx = 0; idx < field_4_tKey_count; idx++)
    {
        // The raw file record is an offset, convert it to point to the string data in the TDAT
        const int offsetInBytes = reinterpret_cast<int>(ptKeyIter->field_0_pwstr);
        ptKeyIter->field_0_pwstr = reinterpret_cast<wchar_t*>(&pDat[offsetInBytes]);
        ptKeyIter++;
    }
}

// match
bool text_0x14::TKeyFind_5B59E0(const char *pIdStr)
{
    return bsearch(
        pIdStr, // search key
        field_0_tKey, // array to search
        field_4_tKey_count, // array count
        sizeof(text_0xC), // element size
        TKeySearch_5B5A10) ? true : false;
}

// match
int __cdecl text_0x14::TKeySearch_5B5A10(const void* a, const void *b)
{
    const char *pIdStr = (const char*)a;
    const text_0xC *a2 = (const text_0xC *)b;
    return strcmp(pIdStr, (const char *)&a2->field_4_pKey); // TODO: ???
}

// match
wchar_t * text_0x14::TKeyFind_5B5A50(const char *pIdStr)
{
     text_0xC* pFound = (text_0xC *)bsearch(
        pIdStr, // key
        field_0_tKey, // array
        field_4_tKey_count, // array count
        sizeof(text_0xC), // element size
        TKeySearch_5B5A10);
    if (!pFound)
    {
        return L" ";
    }
    else
    {
        return pFound->field_0_pwstr;
    }
}

// match
void text_tdat::TDAT_Load_5B5A80( int size)
{
    field_4_len = size / sizeof(wchar_t);
    field_0_data = new BYTE[field_4_len * sizeof(wchar_t)];

    if (!field_0_data)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\text.cpp", 378);
    }

    File::Global_Read_4A71C0(field_0_data, &size);
}

// todo
unsigned __int16 text_0x14::sub_5B5AD0(unsigned __int16 a2)
{
    unsigned __int16 result; // ax

    result = a2;
    switch (this->field_10_lang_code)
    {
    case 'e':
        if ((unsigned int)a2 >= 'a' && (unsigned int)a2 <= 'z')
        {
            result = a2 - ' ';
        }
        break;

    case 'f':
        if (a2 < 0x61u || a2 > 0x7Au)
        {
            if (a2 >= 0x80u && a2 <= 0xFFu)
            {
                //result = word_626590[a2];
            }
        }
        else
        {
            result = a2 - 32;
        }
        break;

    case 'g':
    case 'i':
    case 'r':
    case 's':
        if (a2 < 0x61u || a2 > 0x7Au)
        {
            if (a2 >= 0x80u && a2 <= 0xFFu)
            {
                //result = word_626490[a2];
            }
        }
        else
        {
            result = a2 - 32;
        }
        break;

    default:
        return result;
    }

    return result;
}

// todo
WORD * text_0x14::sub_5B5B80(WORD *pWideStr)
{
    unsigned __int16 str_chr; // ax
    WORD *i; // esi

    str_chr = *pWideStr;
    for (i = pWideStr; str_chr; ++i)
    {
        *i = sub_5B5AD0(str_chr);
        str_chr = i[1];
    }
    return pWideStr;
}

// todo
int __stdcall text_0x14::sub_5B5BC0(WORD *a1, int a2, int a3, int a4)
{
    // todo
    return 0;
}

/*
WORD * pSrc = a1;
    // jnb forced to jge by changing unsigned int loop index to int
    int dstIdx = 0;
    while (pSrc) // bug: should be *pSrc
    {
        if (dstIdx < 79)
        {
            if (*pSrc >= 0x80u)
            {
                byte_70462C[dstIdx] = '#';
            }
            else
            {
                byte_70462C[dstIdx] = static_cast<char>(*pSrc);
            }
            pSrc++;
            dstIdx++;
        }
        else
        {
            break;
        }
    }

    // add null terminator
    byte_70462C[dstIdx] = 0;
    return byte_70462C;
*/

// match
char* text_0x14::Wide2PesudoAscii_5B5D10(WORD *a1)
{
    WORD * pSrc = a1;
    // jnb forced to jge by changing unsigned int loop index to int
    int dstIdx = 0;
    while (pSrc) // bug: should be *pSrc
    {
        // jnb also used if comparing to sizeof() value instead of
        // numerical literal! cast to int fixes (sizeof returns unsigned?)
        if (dstIdx >= static_cast<int>(sizeof(byte_70462C)-1))
        {
            break;
        }

        if (*pSrc >= 0x80u)
        {
            byte_70462C[dstIdx] = '#';
        }
        else
        {
            byte_70462C[dstIdx] = static_cast<char>(*pSrc);
        }

        pSrc++;
        dstIdx++;
    }

    // add null terminator
    byte_70462C[dstIdx] = 0;
    return byte_70462C;
}

// todo
char *__stdcall text_0x14::sub_5B5DF0(BYTE *a1)
{
    BYTE *v1; // edx
    char *v2; // ecx
    char i; // al

    v1 = a1;
    v2 = byte_70488C;
    for (i = *a1; i; ++v1)
    {
        *(WORD *)v2 = i;
        i = v1[1];
        v2 += 2;
    }
    *(WORD *)v2 = 0;
    return byte_70488C;
}

// match
void text_0x14::load_chunk_5B5E20(const char *chunk_type, int chunk_len)
{
    if (!strncmp(chunk_type, "TKEY", 4u))
    {
        TKEY_Load_5B5960(chunk_len);
    }
    else if (!strncmp(chunk_type, "TDAT", 4u))
    {
        field_8_tDat.TDAT_Load_5B5A80(chunk_len);
    }
    else
    {
        File::Global_Seek_4A7140(&chunk_len);
    }
}

// todo stack order wrong
void text_0x14::Load_5B5E90()
{
    char expected_code[8]; // [esp+8h] [ebp-2Ch] BYREF

    chunk_header chunkHeader; // [esp+18h] [ebp-1Ch] BYREF
    char gxtFileName[20]; // [esp+20h] [ebp-14h] BYREF
    sprintf(gxtFileName, "data\\%c.gxt", this->field_10_lang_code);
    
    sprintf(expected_code, "GBL%c", this->field_10_lang_code - ' ');
    
    File::Global_Open_4A7060(gxtFileName);

    int len = sizeof(gtx_header);
    gtx_header gtxHeader; // [esp+10h] [ebp-24h] BYREF
    File::Global_Read_4A71C0(&gtxHeader, &len);

    if (strncmp(expected_code, gtxHeader.field_0_gbl_code, 4u))
    {
        FatalError_4A38C0(93, "C:\\Splitting\\Gta2\\Source\\chunk.h", 37);
    }

    if (gtxHeader.field_4_version != 100)
    {
        FatalError_4A38C0(94, "C:\\Splitting\\Gta2\\Source\\chunk.h", 33);
    }

    for (len = sizeof(chunk_header); File::Global_Read_4A7210(&chunkHeader, &len); len = sizeof(chunk_header))
    {
        if (chunkHeader.field_4_size != 0)
        {
            load_chunk_5B5E20(chunkHeader.field_0_type, chunkHeader.field_4_size);
        }
    }
    File::Global_Close_4A70C0();
    TDAT_Offsets2Strings_5B59B0(field_8_tDat.field_0_data);
}

// match
wchar_t * text_0x14::Find_5B5F90(const char *pIdStr)
{
    return TKeyFind_5B5A50(pIdStr);
}

// match
bool text_0x14::sub_5B5FA0(const char *pIdStr)
{
    return TKeyFind_5B59E0(pIdStr);
}

// todo
text_0x14::text_0x14()
{
    field_0_tKey = 0;
    field_4_tKey_count = 0;
    field_8_tDat.field_0_data = 0;
    field_8_tDat.field_4_len = 0;

    gRegistry_6FF968.Get_Option_586F00("language", reinterpret_cast<BYTE*>(gTmpBuffer_67C598), sizeof(gTmpBuffer_67C598));

    if (gTmpBuffer_67C598[0] == 'e'
        || gTmpBuffer_67C598[0] == 'f'
        || gTmpBuffer_67C598[0] == 'g'
        || gTmpBuffer_67C598[0] == 'i'
        || gTmpBuffer_67C598[0] == 's'
        || gTmpBuffer_67C598[0] == 'j'
        || gTmpBuffer_67C598[0] == 'r')
    {
        field_10_lang_code = gTmpBuffer_67C598[0];
    }
    else
    {
        field_10_lang_code = 'e';
    }
}

// todo
text_0x14::~text_0x14()
{
    // todo: inlined dtor?
    if (field_8_tDat.field_0_data)
    {
        delete field_8_tDat.field_0_data;
    }
    field_8_tDat.field_0_data = 0;

    // todo: pointless if then delete set null is prob a macro ?
    if (field_0_tKey)
    {
        delete field_0_tKey;
    }
    field_0_tKey = 0;
}
