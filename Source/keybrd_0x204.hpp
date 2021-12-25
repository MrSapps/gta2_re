#pragma once

#include <stdio.h>

class keybrd_0x204
{
public:
    __int16 field_0_keys[256];
    int field_200_keyBoardLayout;

    // todo: func order

    static void __stdcall create_4D5F50();

    static void destroy_4D5FA0();

    keybrd_0x204();

    ~keybrd_0x204();

    void LoadKbCfg_4D5E00();

    static int GetLayout_4D6000();

    void ReadCfg_4D5DA0(FILE *Stream, wchar_t *pOut);

    static void RecreateIfLayoutChanged_4D5FD0();
};
