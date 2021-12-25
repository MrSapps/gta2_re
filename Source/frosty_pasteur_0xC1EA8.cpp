#include "frosty_pasteur_0xC1EA8.hpp"
#include "file.hpp"
#include "error.hpp"
#include "debug.hpp"

// nomatch
void frosty_pasteur_0xC1EA8::Load_512330(const char *pScrName)
{
    unsigned __int16 tableSize; // [esp+4h] [ebp-4h] BYREF
    unsigned int len; // [esp+Ch] [ebp+4h] FORCED BYREF

    if (!bSkip_mission_67D4E5)
    {
        strcpy(field_35C_full_scr_file_name, pScrName);
        Error_SetName_4A0770(field_35C_full_scr_file_name);
        File::Global_Open_4A7060(field_35C_full_scr_file_name);
        len = 12000;
        File::Global_Read_4A71C0(field_46C_base_pointers, &len);
        len = 65536;
        File::Global_Read_4A71C0(field_334C_script_data, &len);
        len = 2;
        File::Global_Read_4A71C0(&tableSize, &len);
        len = 5118;
        File::GetRemainderSize_4A7250(field_1334C_strings, &len);
        File::Global_Close_4A70C0();
        LoadStringTbl_5121E0(tableSize);
        GetScrFileName_5122D0();
        LoadSubScripts_5125F0();
    }
}

// stub
void frosty_pasteur_0xC1EA8::LoadStringTbl_5121E0(unsigned __int16 tableSize)
{

}

// stub
void frosty_pasteur_0xC1EA8::GetScrFileName_5122D0()
{

}

// stub
void frosty_pasteur_0xC1EA8::LoadSubScripts_5125F0()
{

}
