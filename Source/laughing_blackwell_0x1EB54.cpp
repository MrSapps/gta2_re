#include "laughing_blackwell_0x1EB54.hpp"
#include "registry.hpp"
#include "error.hpp"
#include "debug.hpp"
#include "root_sound.hpp"
#include "jolly_poitras_0x2BC0.hpp"
#include "lucid_hamilton.hpp"
#include "text_0x14.hpp"
#include "gbh_graphics.hpp"
#include <io.h>
#include <stdio.h>
#include <wchar.h>

struct struc_61F0C8
{
    char field_0_tga_name[128];
    int field_80_len;
    int field_84_img;
};

struc_61F0C8 tgaArray_61F0C8[25] =
{
  { "data\\frontend\\1.tga", 347564, 0 },
  { "data\\frontend\\1_Options.tga", 266924, 0 },
  { "data\\frontend\\1_Play.tga", 266924, 0 },
  { "data\\frontend\\1_Quit.tga", 266924, 0 },
  { "data\\frontend\\2.tga", 347564, 0 },
  { "data\\frontend\\2_Bonus1.tga", 266924, 0 },
  { "data\\frontend\\2_Bonus2.tga", 266924, 0 },
  { "data\\frontend\\2_Bonus3.tga", 266924, 0 },
  { "data\\frontend\\2_League.tga", 266924, 0 },
  { "data\\frontend\\2_Level1.tga", 266924, 0 },
  { "data\\frontend\\2_Level2.tga", 266924, 0 },
  { "data\\frontend\\2_Level3.tga", 266924, 0 },
  { "data\\frontend\\2_Name.tga", 266924, 0 },
  { "data\\frontend\\2_Restart.tga", 266924, 0 },
  { "data\\frontend\\3.tga", 347564, 0 },
  { "data\\frontend\\3_Tables.tga", 614444, 0 },
  { "data\\frontend\\GameComplete.tga", 614444, 0 },
  { "data\\frontend\\LevelComplete.tga", 614444, 0 },
  { "data\\frontend\\MPLose.tga", 614444, 0 },
  { "data\\frontend\\PlayerDead.tga", 614444, 0 },
  { "data\\frontend\\Mask.tga", 104300, 0 },
  { "data\\frontend\\Mask2.tga", 53594, 0 },
  { "data\\frontend\\Credits.tga", 614444, 0 },
  { "data\\frontend\\Mask3.tga", 130427, 0 },
  { "data\\frontend\\DemoInfo.tga", 614939, 0 }
};


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

void laughing_blackwell_0x1EB54::sub_4B8020()
{
    dreamy_clarke_0xA4* pClarke = sub_4B43E0();
    unsigned __int8 idx = gLucid_hamilton_67E8E0.sub_4C5980();

    if (sub_4B7FB0())
    {
        sub_4B3170(4);
    }
    else if (idx == field_1EB50_idx - 1)
    {
        sub_4B3170(10);
    }
    else
    {
        // note: reg swap + push swap due to redundant local
        unsigned __int8 i = 3;
        while (
            !pClarke->field_0[idx][i].field_0 || 
            i >= field_1EB51_blocks[idx])
        {
            i--;
        }

        sub_4B4D00(idx, i);
        gLucid_hamilton_67E8E0.sub_4C5AD0(0);
        field_EE08 = 16;
        field_110_state = 2;
    }
}

char laughing_blackwell_0x1EB54::sub_4B7FB0()
{
    dreamy_clarke_0xA4 *v2; // eax
    unsigned __int16 v3; // bx
    unsigned __int16 v4; // dx

    v2 = sub_4B43E0();
    v3 = 0;
    if (!this->field_1EB50_idx)
        return 1;
    while (1)
    {
        v4 = 0;
        if (this->field_1EB51_blocks[v3])
            break;
    LABEL_5:
        if (++v3 >= (unsigned __int8)this->field_1EB50_idx)
            return 1;
    }
    while (v2->field_0[v3][v4].field_0)
    {
        if (++v4 >= this->field_1EB51_blocks[v3])
            goto LABEL_5;
    }
    return 0;
}

void laughing_blackwell_0x1EB54::sub_4B4D00(unsigned __int8 mainBlockIdx, unsigned __int8 bonusBlockIdx)
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4ADFB0(int a2)
{
    // todo
    /*
    sub_5D7D30();

    gbh_BeginScene();
    DrawBackground_4B6E10();
    sub_4ADF50(a2);
    gbh_EndScene();

    FreeSurface_5D7DC0();

    Vid_FlipBuffers(gVidSys_7071D0);

    Vid_ClearScreen(
        gVidSys_7071D0,
        0,
        0,
        0,
        0,
        0,
        gVidSys_7071D0->field_48_rect_right,
        gVidSys_7071D0->field_4C_rect_bottom);
    */
}


void laughing_blackwell_0x1EB54::DrawBackground_4B6E10()
{
    // todo
    BYTE tga_idx; // [esp+50h] [ebp-8h] BYREF
    BYTE not_used; // [esp+54h] [ebp-4h] BYREF

    if (field_EE08 == 13
        || field_EE08 == 16
        || field_EE08 == 14
        || field_EE08 == 15
        || field_EE08 == 12
        || field_EE08 == 17)
    {
        sub_4B6B00(field_EE08, &tga_idx, &not_used);
        int blitRet = gbh_BlitImage(tgaArray_61F0C8[tga_idx].field_84_img, 0, 0, 640, 480, 0, 0);
        if (blitRet == -10)
        {
            // need to reload image
            Load_tga_4B6520(tga_idx);
            gbh_BlitImage(tgaArray_61F0C8[tga_idx].field_84_img, 0, 0, 640, 480, 0, 0);
        }
        
    }
    else
    {
        sub_4B6B00(field_EE08, &tga_idx, &not_used);

        int blitRet = gbh_BlitImage(tgaArray_61F0C8[tga_idx].field_84_img, 0, 0, 278, 480, 0, 0);
        if (blitRet == -10)
        {
            Load_tga_4B6520(tga_idx);
            blitRet = gbh_BlitImage(tgaArray_61F0C8[tga_idx].field_84_img, 0, 0, 278, 480, 0, 0);
        }

        if (blitRet == 0)
        {
            blitRet = gbh_BlitImage(tgaArray_61F0C8[not_used].field_84_img, 0, 0, 362, 480, 278, 0);
            if (blitRet == -10)
            {
                Load_tga_4B6520(not_used);
                gbh_BlitImage(tgaArray_61F0C8[not_used+1].field_84_img, 0, 0, 362, 480, 278, 0);
            }
        }
    }
    
}

// match
void laughing_blackwell_0x1EB54::sub_4B6B00(unsigned __int8 a1, BYTE *pTgaIdx, BYTE *a3)
{
    switch (a1)
    {
    case 0u:
        *pTgaIdx = 1;
        *a3 = 0;
        break;

    case 1u:
        *pTgaIdx = 2;
        *a3 = 0;
        break;

    case 2u:
        *pTgaIdx = 3;
        *a3 = 0;
        break;

    case 3u:
        *pTgaIdx = 5;
        *a3 = 4;
        break;

    case 4u:
        *pTgaIdx = 6;
        *a3 = 4;
        break;
    case 5u:
        *pTgaIdx = 7;
        *a3 = 4;
        break;

    case 6u:
        *pTgaIdx = 8;
        *a3 = 4;
        break;

    case 7u:
        *pTgaIdx = 9;
        *a3 = 4;
        break;
    case 8u:
        *pTgaIdx = 10;
        *a3 = 4;
        break;

    case 9u:
        *pTgaIdx = 11;
        *a3 = 4;
        break;

    case 10u:
        *pTgaIdx = 12;
        *a3 = 4;
        break;

    case 11u:
        *pTgaIdx = 13;
        *a3 = 4;
        break;
    case 12u:
        *pTgaIdx = 15;
        *a3 = 0;
        break;

    case 13u:
        *pTgaIdx = 19;
        *a3 = 0;
        break;

    case 16u:
        *pTgaIdx = 17;
        *a3 = 0;
        break;

    case 14u:
        *pTgaIdx = 18;
        *a3 = 0;
        break;

    case 15u:
        *pTgaIdx = 16;
        *a3 = 0;
        break;

    case 17u:
        *pTgaIdx = 22;
        *a3 = 0;
        break;

    default:
        return;
    }
}


void laughing_blackwell_0x1EB54::Load_tga_4B6520(unsigned __int16 idx)
{
    Error_SetName_4A0770(tgaArray_61F0C8[idx].field_0_tga_name);

    FILE* hFile = fopen(tgaArray_61F0C8[idx].field_0_tga_name, "rb");
    if (!hFile)
    {
        FatalError_4A38C0(16, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 6516);
    }

    void* pAlloc = malloc(tgaArray_61F0C8[idx].field_80_len);
    if (!pAlloc)
    {
        FatalError_4A38C0(174, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 6523);
    }

    if (fread(pAlloc, 1u, tgaArray_61F0C8[idx].field_80_len, hFile) != tgaArray_61F0C8[idx].field_80_len)
    {
        FatalError_4A38C0(187, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 6529);
    }

    tgaArray_61F0C8[idx].field_84_img = gbh_LoadImage((SImage*)pAlloc);

    fclose(hFile);
    free(pAlloc);


}
