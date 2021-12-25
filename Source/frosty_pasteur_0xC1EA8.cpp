#include "frosty_pasteur_0xC1EA8.hpp"
#include "file.hpp"
#include "error.hpp"
#include "debug.hpp"

// nomatch
void frosty_pasteur_0xC1EA8::Load_512330(const char *pScrName)
{
    if (!bSkip_mission_67D4E5)
    {
        strcpy(field_35C_full_scr_file_name, pScrName);
        Error_SetName_4A0770(field_35C_full_scr_file_name);
        File::Global_Open_4A7060(field_35C_full_scr_file_name);
        unsigned int len = sizeof(field_46C_base_pointers);
        File::Global_Read_4A71C0(field_46C_base_pointers, &len);
        len = sizeof(field_334C_script_data);
        File::Global_Read_4A71C0(field_334C_script_data, &len);
        unsigned __int16 tableSize;
        len = sizeof(tableSize);
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
    char *slash_pos; // eax
    char *pfullName; // esi
    const char *after_slash_pos; // edx
    unsigned int total_str_len; // kr04_4
    size_t copyLen; // ecx

    slash_pos = strrchr(this->field_35C_full_scr_file_name, '\\');
    if (slash_pos)
    {
        pfullName = this->field_45C_scr_file_name;
        after_slash_pos = slash_pos + 1;

        memset(field_45C_scr_file_name, 0, sizeof(field_45C_scr_file_name));

        total_str_len = strlen(slash_pos + 1);
        copyLen = total_str_len;
        if (total_str_len != 1)
        {
            while (after_slash_pos[copyLen] != '.')
            {
                if (!--copyLen)
                    return;
            }
            strncpy(pfullName, after_slash_pos, copyLen);
        }
    }
}

// stub
void frosty_pasteur_0xC1EA8::LoadSubScripts_5125F0()
{

}
