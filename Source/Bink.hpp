#pragma once

#include <windows.h>
#include "3rdParty/mss.h"

class Bink
{
public:
    static void __stdcall Reset_513210();

    static void __stdcall Close1_513340();

    static void __stdcall Close2_513390();

    static void __stdcall sub_5136D0(int *pNewWindowX, int *pNewWindowY);

    static BOOL sub_513770();

    static BOOL sub_513760();

    static void sub_513720();

    static char sub_513240();

    static char sub_513790();

    static void __stdcall sub_5137A0(char a1);

    static void __stdcall sub_5133E0(const char *a1, HDIGDRIVER  a2);

    static void __stdcall sub_5137B0(char a1);

    static void __stdcall sub_513560(const char *pFileName, HDIGDRIVER  a2);
};
