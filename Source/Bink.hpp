#pragma once

#include <windows.h>
#include "3rdParty/mss.h"
#include "types.hpp"

class Bink
{
public:
    EXPORT static void __stdcall Reset_513210();

    EXPORT static void __stdcall Close1_513340();

    EXPORT static void __stdcall Close2_513390();

    EXPORT static void __stdcall sub_5136D0(int *pNewWindowX, int *pNewWindowY);

    EXPORT static BOOL sub_513770();

    EXPORT static BOOL sub_513760();

    EXPORT static void sub_513720();

    EXPORT static char sub_513240();

    EXPORT static char sub_513790();

    EXPORT static void __stdcall sub_5137A0(char a1);

    EXPORT static void __stdcall sub_5133E0(const char *a1, HDIGDRIVER  a2);

    EXPORT static void __stdcall sub_5137B0(char a1);

    EXPORT static void __stdcall sub_513560(const char *pFileName, HDIGDRIVER  a2);
};
