#include "laughing_blackwell_0x1EB54.hpp"
#include "registry.hpp"
#include "error.hpp"
#include "debug.hpp"
#include "root_sound.hpp"
#include "jolly_poitras_0x2BC0.hpp"
#include "lucid_hamilton.hpp"
#include "text_0x14.hpp"
#include "gbh_graphics.hpp"
#include "Bink.hpp"
#include "sharp_pare_0x15D8.hpp"
#include "gtx_0x106C.hpp"
#include "magical_germain_0x8EC.hpp"
#include <io.h>
#include <stdio.h>
#include <wchar.h>

laughing_blackwell_0x1EB54* gLaughing_blackwell_0x1EB54_67DC84;

DWORD dword_67D6F8;
int* dword_67D704;
BYTE byte_67D6FC;
DWORD gSoundIdx_67D700;
int dword_67D818;
BYTE byte_67D81C;
unsigned int counter_706C4C;
int dword_67D930;
unsigned short gTableSize_61FF20 = 25;

extern wchar_t word_67DC8C[50];

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

// match
void __stdcall laughing_blackwell_0x1EB54::create_4ACFA0()
{
    if (!gLaughing_blackwell_0x1EB54_67DC84)
    {
        gLaughing_blackwell_0x1EB54_67DC84 = new laughing_blackwell_0x1EB54();
    }

    if (!bSkip_audio_67D6BE)
    {
        dword_67D818 = 0;
        byte_67D81C = 0;
        dword_67D6F8 = 2;
        dword_67D704 = &dword_67D818;
        byte_67D6FC = 0;
        gSoundIdx_67D700 = gRoot_sound_66B038.sub_40EFB0(&dword_67D6F8);
        gRoot_sound_66B038.LoadStyle_40EFF0("data\\fstyle.sty");
        gRoot_sound_66B038.Set3DSound_40F160(0);
    }

    Bink::Reset_513210();
}

// match
void __stdcall laughing_blackwell_0x1EB54::destroy_4AD070()
{
    if (!bSkip_audio_67D6BE && gSoundIdx_67D700)
    {
        gRoot_sound_66B038.sub_40EFD0(gSoundIdx_67D700);
        gSoundIdx_67D700 = 0;
    }

    if (gLaughing_blackwell_0x1EB54_67DC84)
    {
        delete gLaughing_blackwell_0x1EB54_67DC84;
        gLaughing_blackwell_0x1EB54_67DC84 = 0;
    }

    Bink::Close1_513340();
    Bink::Close2_513390();
}

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
    // note: ecx wasn't first due to global being an object instead of a pointer
    _finddata_t findData;

    // note: put call in argument rather than local to change inst ordering
    const long hFind = _findfirst(gLaughing_blackwell_0x1EB54_67DC84->intro_bik_4B5E50(), &findData);

    if (hFind == -1)
    {
        return 0;
    }

    _findclose(hFind);
    return 1;

}

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
    __int16 v2; // ax
    int v3; // eax

    if (this->field_C9D0)
    {
        v2 = this->field_EE0A;
        if (v2 == 210)
        {
            if (this->field_EE0C != 1)
            {
                FatalError_4A38C0(1006, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 1934);
            }

            sub_4B4410();
        }
        else if (v2 != 230)
        {
            dword_67D818 = 5;
        }
        else
        {
            this->field_110_state = 1;
            dword_67D818 = 5;
        }
    }

    if (this->field_C9D1)
    {
        this->field_110_state = 1;
        dword_67D818 = 6;
    }

    if (this->field_C9CE)
    {
        if (this->field_EE0A == 190 || this->field_EE0A == 210)
        {
            this->field_EE0A = 230;
        }
        else
        {
            if (this->field_EE0A != 230)
            {
                FatalError_4A38C0(1006, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 1968);
            }
            this->field_EE0A = 210;
        }
        dword_67D818 = 1;
    }

    if (this->field_C9CF)
    {
        if (this->field_EE0A != 190)
        {
            if (this->field_EE0A == 210)
            {
                this->field_EE0A = 230;
                dword_67D818 = 2;
            }
            else if (this->field_EE0A != 230)
            {
                FatalError_4A38C0(1006, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 1991);
            }
        }
        else
        {
            this->field_EE0A = 210;
            dword_67D818 = 2;
        }
    }

    v3 = this->field_118 - 1;
    this->field_118 = v3;
    if (v3 <= 0)
    {
        this->field_114 = this->field_114 == 0;
        this->field_118 = 2;
    }
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
                gbh_BlitImage(tgaArray_61F0C8[not_used].field_84_img, 0, 0, 362, 480, 278, 0);
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

// match
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

// todo: move me
void __stdcall sub_5D7CB0()
{
    // todo
}

laughing_blackwell_0x1EB54::laughing_blackwell_0x1EB54()
{
    field_10D = 1;

    gText_0x14_704DFC = new text_0x14();
    if (!gText_0x14_704DFC)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2288);
    }

    gGtx_0x106C_703DD4 = new gtx_0x106C();
    if (!gGtx_0x106C_703DD4)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2290);
    }

    gSharp_pare_0x15D8_705064 = new sharp_pare_0x15D8();
    if (!gSharp_pare_0x15D8_705064)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2292);
    }

    if (gText_0x14_704DFC->field_10_lang_code == 'j')
    {
        // pmagical_germain_0x8EC = pmagical_germain_0x8EC_mem ? magical_germain_0x8EC::ctor_4D2C80(pmagical_germain_0x8EC_mem) : 0;
        gMagical_germain_0x8EC_6F5168 = new magical_germain_0x8EC();
        if (!gMagical_germain_0x8EC_6F5168)
        {
            FatalError_4A38C0(32, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2297);
        }
    }
    InitKeyBoardDevice_4AFBE0();
    
    gText_0x14_704DFC->Load_5B5E90();
    gGtx_0x106C_703DD4->LoadSty_5AB750("data\\fstyle.sty");

    gSharp_pare_0x15D8_705064->sub_5B9350();

    sub_5D7CB0();

    gbh_SetAmbient(1.0);
    
    if (gMagical_germain_0x8EC_6F5168)
    {
        gMagical_germain_0x8EC_6F5168->sub_4D2B40();
    }

    field_110_state = 1;
    field_114 = 0;
    field_118 = 0;
    field_C9D5 = 0;
    field_C9D6 = 0;
    field_C9D3 = 0;
    field_C9D4 = 0;
    field_C9D7 = 0;
    field_C9D8 = 0;
    field_C9D9 = 0;
    field_10C_bKeyboardAcquired = 0;
    field_108 = 2;
    field_C9E1_bCheatsEnabled = 0;
    
    sub_4AF0E0();
    
    field_C9DC = timeGetTime();
    field_C9E0 = 0;
    field_132_f136_idx = 0;
    field_C9E4 = 0;
    
    sub_4B0220();
    
    field_C9B2 = 0;
    field_C9B3 = 1;
    field_C9B4 = 256;
    field_C9B6 = 5;

    memset(&field_C9A0, 0, sizeof(field_C9A0));
    /*
    *(_DWORD *)this->field_C9A0 = 0;
    *(_DWORD *)&this->field_C9A0[2] = 0;
    *(_DWORD *)&this->field_C9A0[4] = 0;
    *(_DWORD *)&this->field_C9A0[6] = 0;
    this->field_C9A0[8] = 0;
    */

    memset(&field_C9B8, 0, sizeof(field_C9B8));
    /*
    *(_DWORD *)this->field_C9B8 = 0;
    *(_DWORD *)&this->field_C9B8[2] = 0;
    *(_DWORD *)&this->field_C9B8[4] = 0;
    *(_DWORD *)&this->field_C9B8[6] = 0;
    *(_WORD *)&this->field_C9C8 = 0;
    */
    field_C9CA = 0;
    field_C9CB = 0;
    field_1EB50_idx = 0;

    field_1EB51_blocks[0] = 0;
    field_1EB51_blocks[1] = 0;
    field_1EB51_blocks[2] = 0;
    
    sub_4B4440();
    LoadPlySlotSvgs_4B53C0();
    
    field_EE08 = 1;
    
    Load_tgas_4B66B0();

    field_EE0D = 0;
    field_EE0A = 190;
    field_EE0C = 0;
    field_1EB30 = 0;
    field_1EB38 = 0;
    field_1EB34 = dword_67D930;
    field_1EB4A = 0;
    field_1EB4B = 0;
    field_1EB4C = 0;
    field_1EB4D = 0;
    field_1EB4E = 0;
    field_1EB4F = 0;


    // todo: fix me
    /*
    for (int i = 0; i < 8; i++)
    {

    }

    v11 = &this->field_1EB42;
    v12 = 8;
    do
    {
        *((_BYTE *)v11 - 8) = -1;
        *(_BYTE *)v11 = -1;
        v11 = (__int16 *)((char *)v11 + 1);
        --v12;
    } while (v12);
    */
}

laughing_blackwell_0x1EB54::~laughing_blackwell_0x1EB54()
{
    FreeKeyBoardDevice_4AFD00();

    if (gSharp_pare_0x15D8_705064)
    {
        delete gSharp_pare_0x15D8_705064;
        gSharp_pare_0x15D8_705064 = 0;
    }

    if (gGtx_0x106C_703DD4)
    {
        delete gGtx_0x106C_703DD4;
        gGtx_0x106C_703DD4 = 0;
    }

    if (gText_0x14_704DFC)
    {
        delete gText_0x14_704DFC;
        gText_0x14_704DFC = 0;
    }

    if (gMagical_germain_0x8EC_6F5168)
    {
        delete gMagical_germain_0x8EC_6F5168;
        gMagical_germain_0x8EC_6F5168 = 0;
    }

    FreeImageTable_4B6750();
}

void laughing_blackwell_0x1EB54::FreeKeyBoardDevice_4AFD00()
{
    // todo
}

void laughing_blackwell_0x1EB54::FreeImageTable_4B6750()
{
    gbh_FreeImageTable();
}

void laughing_blackwell_0x1EB54::InitKeyBoardDevice_4AFBE0()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4AF0E0()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4B0220()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4B4440()
{
    // todo
}

void laughing_blackwell_0x1EB54::LoadPlySlotSvgs_4B53C0()
{
    unsigned __int8 k8Counter; // bl
    admiring_euler_4 *pIter; // esi
    BYTE idx; // [esp+10h] [ebp-104h]
    char FileName[256]; // [esp+14h] [ebp-100h] BYREF

    k8Counter = 0;
    idx = 0;
    pIter = this->field_EDE8_plySlots;
    do
    {
        if (PlySlotSvgExists_4B5370(idx))
        {
            GetPlySlotSvgName_4B51D0(idx, FileName);
            pIter->LoadPlySlotSvg_4B6480(FileName);
        }
        else
        {
            pIter->field_0 = 0;
            pIter->field_1 = 3;
            pIter->field_2 = 4;
            pIter->field_3 = 0;
        }
        ++k8Counter;
        ++pIter;
        idx = k8Counter;
    } while (k8Counter < 8u);
}

// match
void laughing_blackwell_0x1EB54::Load_tgas_4B66B0()
{
    if (gbh_InitImageTable(gTableSize_61FF20) != -1)
    {
        for (unsigned short i = 0; i < gTableSize_61FF20; ++i)
        {
            Load_tga_4B6520(i);
        }
    }
}

void laughing_blackwell_0x1EB54::GetPlySlotSvgName_4B51D0(unsigned __int8 idx, char *pStr)
{
    char Buffer[8];
    _itoa(idx, Buffer, 10);
    strcpy(pStr, "player\\plyslot");
    strcat(pStr, Buffer);
    strcat(pStr, ".svg");
}

char laughing_blackwell_0x1EB54::PlySlotSvgExists_4B5370(int idx)
{
    long hFind; // eax
    CHAR FileName[256]; // [esp+0h] [ebp-218h] BYREF
    _finddata_t v4; // [esp+100h] [ebp-118h] BYREF

    GetPlySlotSvgName_4B51D0(idx, FileName);
    hFind = _findfirst(FileName, &v4);
    if (hFind == -1)
    {
        return 0;
    }

    _findclose(hFind);
    return 1;
}

loving_borg_0xBCA::loving_borg_0xBCA()
{
    field_0 = 0;
    field_2 = 0;
    field_BC6_nifty_idx = 0;
    field_BC8 = 0;
}

loving_borg_0xBCA::~loving_borg_0xBCA()
{
    field_0 = 0;
    field_2 = 0;
    field_BC6_nifty_idx = 0;
    field_BC8 = 0;
}

competent_noyce_0x6E::competent_noyce_0x6E()
{
    field_0 = 0;
    field_2 = 0;
    field_4 = 0;
    field_1 = 1;
    wcscpy(field_6_wstr_buf, word_67DC8C);
    field_6A = -1;
    field_6C = -1;
}

competent_noyce_0x6E::~competent_noyce_0x6E()
{
    field_1 = 1;
    field_0 = 0;
    field_2 = 0;
    field_4 = 0;
    field_6A = -1;
    field_6C = -1;
}

nifty_maxwell_0x82::nifty_maxwell_0x82()
{
    field_6A = -1;
    field_6C = -1;
    field_0 = 0;
    field_1 = 1;
    field_2 = 0;
    field_4 = 0;
    field_6E_count = 0;
    field_70 = 0;
    memset(&field_72, 0, sizeof(field_72));
    field_76 = 0;
    field_7A = 0;
    wcscpy(field_6_wstr_buf, word_67DC8C);
    field_7E = 0;
    field_80 = 0;
}

nifty_maxwell_0x82::~nifty_maxwell_0x82()
{
    field_0 = 0;
    field_1 = 1;
    field_2 = 0;
    field_4 = 0;
    field_6A = -1;
    field_6C = -1;
    field_6E_count = 0;
    field_70 = 0;
    field_7E = 0;
    field_80 = 0;
}

kind_beaver_6::kind_beaver_6()
{
    field_0 = 0;
    field_2 = 0;
    field_4 = 1;
}

kind_beaver_6::~kind_beaver_6()
{
    field_0 = 0;
    field_2 = 0;
    field_4 = 1;
}

xenodochial_morse::xenodochial_morse()
{
    field_0 = 0;
}

sleepy_stonebraker_0x6C::sleepy_stonebraker_0x6C()
{
    field_0 = 0;
    field_2 = 0;
    field_4 = 0;
    field_6 = 0;
    memset(field_8_strBuf, 0u, sizeof(field_8_strBuf));
}

sleepy_stonebraker_0x6C::~sleepy_stonebraker_0x6C()
{

}

void admiring_euler_4::LoadPlySlotSvg_4B6480(const char *FileName)
{
    // todo
}
