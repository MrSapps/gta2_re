#include "laughing_blackwell_0x1EB54.hpp"
#include "registry.hpp"
#include "error.hpp"
#include "debug.hpp"
#include "root_sound.hpp"
#include "jolly_poitras_0x2BC0.hpp"
#include "lucid_hamilton.hpp"
#include "text_0x14.hpp"
#include <io.h>
#include <wchar.h>

int __stdcall SetGamma_5D9910(int gamma)
{
    // todo
    return 0;
}

laughing_blackwell_0x1EB54* gLaughing_blackwell_0x1EB54_67DC84;

void laughing_blackwell_0x1EB54::sub_4B3170(unsigned __int16 arg0)
{
    // todo

}

int laughing_blackwell_0x1EB54::sub_4AEDB0()
{
    // todo
    return 0;
}

const char* laughing_blackwell_0x1EB54::intro_bik_4B5E50()
{
    // todo
    return "meh.dat";
}

// match
bool laughing_blackwell_0x1EB54::intro_bik_exists_4B5FF0()
{
    // ecx wasn't first due to global being an object instead of a pointer
    _finddata_t findData;

    // note: put call in argument rather than local to change inst ordering
    const  long hFind = _findfirst(gLaughing_blackwell_0x1EB54_67DC84->intro_bik_4B5E50(), &findData);

    if (hFind == -1)
    {
        return 0;
    }

    _findclose(hFind);
    return 1;

}

int dword_67D818;
BYTE byte_67D81C;
unsigned int counter_706C4C;

void sub_SetGamma()
{
    const int gammaVal = gRegistry_6FF968.Get_Screen_Setting_5870D0("gamma", 10);
    if (counter_706C4C)
    {
        if (SetGamma_5D9910(gammaVal))
        {
            --counter_706C4C;
        }
        else
        {
            counter_706C4C = 0;
        }
    }
}

// match
void laughing_blackwell_0x1EB54::sub_4AEC00()
{
    sub_4AFEB0();
    sub_4B6780();

    dword_67D818 = 0;

    switch (field_110_state)
    {
    case 3:
        sub_4B2F60();
        break;

    case 5:
        sub_4B8280();
        break;

    case 1:
        if (field_132_f136_idx == 9)
        {
            byte_67D81C = 1;
            sub_4B7A10();
        }
        else
        {
            byte_67D81C = 0;
            sub_4AE2D0();
        }
        break;

    case 2:
        sub_4AE990();
        break;

    case 4:
        sub_4AE9A0();
        break;

    default:
        FatalError_4A38C0(1006, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2059, field_110_state);
    }

    if (!bSkip_audio_67D6BE)
    {
        gRoot_sound_66B038.sub_40EFA0();
    }

    if (counter_706C4C > 0)
    {
        sub_SetGamma();
    }
}

void laughing_blackwell_0x1EB54::sub_4AFEB0()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4B6780()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4B7A10()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4AE2D0()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4AE990()
{
    field_108 = 3;
}

void laughing_blackwell_0x1EB54::sub_4B2F60()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4AE9A0()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4B8280()
{
    // todo
}

// match
void laughing_blackwell_0x1EB54::sub_4B4410()
{
    sub_4B43E0()->sub_56B630();
    gJolly_poitras_0x2BC0_6FEAC0->sub_56BA60(field_136[1].field_4[0].field_6E_count);
    sub_4B42E0();
}

// match
dreamy_clarke_0xA4* laughing_blackwell_0x1EB54::sub_4B43E0()
{
    // note: movsx vs movzx due to signedness
    unsigned short idx = gLucid_hamilton_67E8E0.sub_4C59B0();
    return &gJolly_poitras_0x2BC0_6FEAC0->field_26A0[idx];
}

void laughing_blackwell_0x1EB54::sub_4B42E0()
{
    // todo
}

// match
void laughing_blackwell_0x1EB54::sub_4B4230()
{
    unsigned __int16 count = field_136[1].field_4[0].field_6E_count;
    wchar_t* pStr = gJolly_poitras_0x2BC0_6FEAC0->field_26A0[count].field_90_str;
    wcsncpy(pStr, field_C9A0, 9u);
    HandleCheatCode_4B3DD0(pStr);
    gJolly_poitras_0x2BC0_6FEAC0->sub_56BA60(count);
}

void laughing_blackwell_0x1EB54::HandleCheatCode_4B3DD0(const wchar_t *String)
{
    // todo
}

// match
void laughing_blackwell_0x1EB54::sub_4B4280()
{
    wcsncpy(
        field_C9A0,
        gJolly_poitras_0x2BC0_6FEAC0->field_26A0[field_136[1].field_4[0].field_6E_count].field_90_str,
        9u);
}

void laughing_blackwell_0x1EB54::sub_4B8530()
{
    short total = field_C9CA;
    if (total < 9)
    {
        int remainder = 9 - total;
        //remainder &= 0xFFFF;
        wchar_t* pStart = &field_C9B8[total];
        while (remainder)
        {
            *pStart = 0;
            pStart++;
            remainder--;
        }
//        wmemset(&field_C9B8[total], 0, remainder);
    }
}

// match
void laughing_blackwell_0x1EB54::sub_4B8560()
{
    if (!wcscmp(field_C9B8, L"WFUSDFCF")) // french bonus mission unlocks?
    {
        if (intro_bik_exists_4B5FF0()
            && gRegistry_6FF968.Get_Screen_Setting_5870D0("do_play_movie", 1) == 1)
        {
            sub_4B3170(8u);
        }
        else
        {
            sub_4B3170(0);
        }
    }
    else
    {
        field_110_state = 5;
        field_C9CA = 0;

        sub_4B8530();

        field_C9B3 = 1;
        field_C9B4 = 28;
        field_C9B6 = 5;

        wcsncpy(field_136[14].field_518[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("fr_rnt1"), 0x32u);
        wcsncpy(field_136[14].field_518[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("fr_rnt2"), 0x32u);
        wcsncpy(field_136[14].field_518[2].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("fr_rnt3"), 0x32u);
        
        field_C9CB = 1;
    }
}
