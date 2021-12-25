#include "magical_germain_0x8EC.hpp"
#include "error.hpp"
#include "file.hpp"
#include "chunk.hpp"

magical_germain_0x8EC *gMagical_germain_0x8EC_6F5168;

// match
void magical_germain_0x8EC::LoadChunks_4D1FC0(const char *pChunkId, unsigned int chunk_len)
{
    if (!strncmp(pChunkId, "KIDX", 4u))
    {
        field_8CC_kidx_size_words = chunk_len >> 1;
        field_8C4_pKidX = new WORD[field_8CC_kidx_size_words];
        if (!field_8C4_pKidX)
        {
            FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\kanji.cpp", 142);
        }
        File::Global_Read_4A71C0(this->field_8C4_pKidX, &chunk_len);
    }
    else if (!strncmp(pChunkId, "KBIT", 4u))
    {
        field_8C8_pKBIT = new BYTE[chunk_len];
        if (!field_8C8_pKBIT)
        {
            FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\kanji.cpp", 148);
        }
        File::Global_Read_4A71C0(field_8C8_pKBIT, &chunk_len);
    }
    else
    {
        File::Global_Seek_4A7140(&chunk_len);
    }
}

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
