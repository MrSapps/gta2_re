#include "gtx_0x106C.hpp"
#include "error.hpp"
#include "file.hpp"
#include <string.h>
#include <stdio.h>
#include <windows.h>

struct sty_header
{
    char field_0_type[4];
    short field_4_version;
};

struct chunk_header
{
    char field_0_type[4];
    int field_4_size;
};

void gtx_0x106C::LoadSty_5AB750(const char *pStyFileName)
{
    sty_header header;// Str2[4]; // [esp+4h] [ebp-10h] BYREF
    //__int16 v4; // [esp+8h] [ebp-Ch]
    
    chunk_header chunk;
    //char Buffer[4]; // [esp+Ch] [ebp-8h] BYREF
    //int chunk_size; // [esp+10h] [ebp-4h]

    File::Global_Open_4A7060(pStyFileName);
    DWORD len = 6;
    File::Global_Read_4A71C0(header.field_0_type, &len);

    if (strncmp("GBST", header.field_0_type, 4u))
    {
        FatalError_4A38C0(93, "C:\\Splitting\\Gta2\\Source\\chunk.h", 37);
    }

    if (header.field_4_version != 700)
    {
        FatalError_4A38C0(94, "C:\\Splitting\\Gta2\\Source\\chunk.h", 33);
    }

    for (len = 8; File::Global_Read_4A7210(&chunk, &len); len = 8)
    {
        if (chunk.field_4_size)
        {
            LoadChunk_5AB4B0(chunk.field_0_type, chunk.field_4_size);
        }

    }
    File::Global_Close_4A70C0();

    sub_5AB720();
}
