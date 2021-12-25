#include "keybrd_0x204.hpp"
#include "error.hpp"
#include <stdlib.h>
#include <windows.h>

keybrd_0x204* gKeybrd_0x204_6F52F4;

void __stdcall keybrd_0x204::create_4D5F50()
{
    if (!gKeybrd_0x204_6F52F4)
    {
        gKeybrd_0x204_6F52F4 = new keybrd_0x204();
        if (!gKeybrd_0x204_6F52F4)
        {
            FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\keybrd.cpp", 244);
        }
    }
    gKeybrd_0x204_6F52F4->LoadKbCfg_4D5E00();
}

void keybrd_0x204::destroy_4D5FA0()
{
    if (gKeybrd_0x204_6F52F4)
    {
        delete gKeybrd_0x204_6F52F4;
        gKeybrd_0x204_6F52F4 = 0;
    }
}

keybrd_0x204::keybrd_0x204()
{
    field_200_keyBoardLayout = 0;
    memset(field_0_keys, 0, sizeof(field_0_keys));
}

keybrd_0x204::~keybrd_0x204()
{

}

void keybrd_0x204::LoadKbCfg_4D5E00()
{
    int Layout_4D6000; // eax
    const char *pKeyboardCfgFile; // edi
    FILE *hConfigFile; // edi
    __int16  *pKeyArrayIter; // esi
    int k256Counter; // ebp
    wchar_t tmpBuffer[16]; // [esp+10h] [ebp-A0h] BYREF
    char FileName[128]; // [esp+30h] [ebp-80h] BYREF

    this->field_200_keyBoardLayout = 0;
    Layout_4D6000 = GetLayout_4D6000();
    field_200_keyBoardLayout = Layout_4D6000;

    switch (Layout_4D6000)
    {
    case 1:
        pKeyboardCfgFile = "data\\keyboard\\fre_kb.cfg";
        break;
    case 2:
        pKeyboardCfgFile = "data\\keyboard\\ger_kb.cfg";
        break;
    case 3:
        pKeyboardCfgFile = "data\\keyboard\\ita_kb.cfg";
        break;
    case 4:
        pKeyboardCfgFile = "data\\keyboard\\spa_kb.cfg";
        break;
    case 5:
        pKeyboardCfgFile = "data\\keyboard\\por_kb.cfg";
        break;
    case 6:
        pKeyboardCfgFile = "data\\keyboard\\rus_kb.cfg";
        break;
    default:
        pKeyboardCfgFile = "data\\keyboard\\eng_kb.cfg";
        break;
    }

    strcpy(FileName, pKeyboardCfgFile);
    hConfigFile = fopen(FileName, "rt");
    if (!hConfigFile)
    {
        FatalError_4A38C0(151, "C:\\Splitting\\Gta2\\Source\\keybrd.cpp", 187);
    }

    pKeyArrayIter = this->field_0_keys;
    k256Counter = 256;
    do
    {
        ReadCfg_4D5DA0(hConfigFile, tmpBuffer);
        if (tmpBuffer[0] == 126)
        {
            *pKeyArrayIter = 0;
        }
        else
        {
            *pKeyArrayIter = tmpBuffer[0] != '`' ? 0 : tmpBuffer[1];
        }
        ++pKeyArrayIter;
        --k256Counter;
    } while (k256Counter);

    fclose(hConfigFile);
}

DWORD dword_620D2C = 0x2020;

int keybrd_0x204::GetLayout_4D6000()
{
    int result; // eax
    char Buffer[4]; // [esp+0h] [ebp-14h] BYREF
    int v2; // [esp+4h] [ebp-10h] BYREF
    CHAR pwszKLID[12]; // [esp+8h] [ebp-Ch] BYREF

    *(WORD *)&Buffer[2] = HIWORD(dword_620D2C);
    GetKeyboardLayoutNameA(pwszKLID);
    Buffer[0] = pwszKLID[6];
    Buffer[1] = pwszKLID[7];
    sscanf(Buffer, "%x", &v2);
    switch (v2)
    {
    case 7:
        result = 2;
        break;
    case 10:
        result = 4;
        break;
    case 12:
        result = 1;
        break;
    case 16:
        result = 3;
        break;
    case 22:
        result = 5;
        break;
    case 25:
        result = 6;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

void keybrd_0x204::ReadCfg_4D5DA0(FILE *Stream, wchar_t *pOut)
{
    __int16 read_char; // ax
    unsigned __int8 i; // [esp+8h] [ebp-4h]

    for (i = 0; ; ++i)
    {
        read_char = fgetc(Stream);
        if (read_char == '\n' || read_char == ' ')
            break;
        pOut[i] = read_char;
    }
    pOut[i] = 0;
}

void keybrd_0x204::RecreateIfLayoutChanged_4D5FD0()
{
    if (gKeybrd_0x204_6F52F4)
    {
        int curLayout = gKeybrd_0x204_6F52F4->field_200_keyBoardLayout;
        if (curLayout == keybrd_0x204::GetLayout_4D6000())
        {
            return;
        }
        keybrd_0x204::destroy_4D5FA0();
    }
    keybrd_0x204::create_4D5F50();
}
