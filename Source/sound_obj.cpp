#include "sound_obj.hpp"
#include "cSampleManager.hpp"
#include <math.h>

sound_obj gSound_obj_66F680;

int dword_674CD8;

// match
void serene_brattain::sub_419DF0()
{

}

// 0x419CD0 match
sound_obj::sound_obj()
{
    sound_0x68 * pIter = &field_9C_asSamples[0][0];
    for (int t = 0; t < 2*16; t++)
    {
        pIter->field_8_obj.sub_419DF0();
        pIter++;
    }

    for (int j = 0; j < 16; j++)
    {
        field_DC0[j].field_8_obj.sub_419DF0();
    }

    field_1474 = 0;
    field_0 = 0;
    field_4 = 81920;
    field_8 = 30;
    field_C = 491520;
    field_2 = 1;
    field_24_sfx_vol = 127;
    field_25_cdVol = 127;
    field_28 = dword_674CD8;
    field_2C = 0;
    
    field_98_nActiveSampleQueue = 1;
    ClearRequestedQueue_41B700();
    
    field_98_nActiveSampleQueue = 0;
    ClearRequestedQueue_41B700();
    
    ClearActivateSamples_41B7A0();
    
    field_1450 = 0;
    field_1468_v1 = 0;
    field_146C_v2 = 0;
    field_1470_v3 = 0;
    
    GenerateIntegerRandomNumberTable_41BA90();

    field_1478_type5Idx = 0;
    field_1B = 0;
    field_1C_samp_count = 0;
    field_10_nActiveSamples = 0;
    field_5444 = 0;
    field_5440 = 0;
    field_1D_b3d_sound = 0;
    field_14_sample_rate = 22050;
    field_18 = 1;
    field_19 = 1;
    field_1 = 0;
    field_1A = 1;

    for (int i = 0; i < 1020; i++)
    {
        field_147C[i].field_0_bUsed = 0;
        field_444C_pEntities[i] = 0;
    }

    field_543C_444C_max_idx = 0;
    field_5448_m_FrameCounter = 0;
    field_544C[0].field_0 = 0; // todo: type check
    field_544C[0].field_18 = 0; // todo: type check
    field_3 = 1;
}

// match
void sound_obj::ClearRequestedQueue_41B700()
{
    for (unsigned int i = 0; i < field_10_nActiveSamples; i++)
    {
        field_D9C_abSampleQueueIndexTable[field_98_nActiveSampleQueue][i] = field_10_nActiveSamples;
    }

    field_DBC_SampleRequestQueuesStatus[field_98_nActiveSampleQueue] = 0;
}

// match
void sound_obj::ClearActivateSamples_41B7A0()
{
    for (unsigned __int8 i = 0; i < field_10_nActiveSamples; i++ )
    {
        field_DC0[i].field_0 = 0;
        field_DC0[i].field_4 = 0;
        field_DC0[i].field_14_samp_idx = 321;
        field_DC0[i].field_8_obj.field_0 = dword_674CD8; // vec3 type ?
        field_DC0[i].field_8_obj.field_4 = dword_674CD8;
        field_DC0[i].field_8_obj.field_8 = dword_674CD8;
        field_DC0[i].field_18 = 0;
        field_DC0[i].field_1C_ReleasingVolumeModificator = 4;
        field_DC0[i].field_20_rate = 22050;
        field_DC0[i].field_58_type = 0;
        field_DC0[i].field_24_nVolume = 0;
        field_DC0[i].field_60 = 0;
        field_DC0[i].field_64 = 10;
        field_DC0[i].field_28 = 0;
        field_DC0[i].field_2C = 0;
        field_DC0[i].field_2D = 0;
        field_DC0[i].field_30 = 1;
        field_DC0[i].field_34 = 0;
        field_DC0[i].field_38 = -1;
        field_DC0[i].field_3C = 0;
        field_DC0[i].field_54 = 0x190000;
        field_DC0[i].field_40_pan = 63;
        field_DC0[i].field_41 = 0;
        field_DC0[i].field_44 = -3;
        field_DC0[i].field_48_nCalculatedVolume = 0;
        field_DC0[i].field_4C = 0;
        field_DC0[i].field_50 = -1;
        field_DC0[i].field_5C = 0;
    }
}

// match
void sound_obj::sub_41A2A0()
{
    field_98_nActiveSampleQueue = 1;
    ClearRequestedQueue_41B700();
    field_98_nActiveSampleQueue = 0;

    ClearRequestedQueue_41B700();
    ClearActivateSamples_41B7A0();

    field_1450 = 0;

    gSampManager_6FFF00.sub_58E2A0();
}

// match
void sound_obj::SetSfxVol_41A250(char sfxVol)
{
    field_24_sfx_vol = sfxVol;
}

// match
void sound_obj::SetCDVol_41A270(unsigned char cdVol)
{
    field_25_cdVol = cdVol;
}

// match
char sound_obj::Set3DSound_41A2F0(char b3dSound)
{
    if (field_0 != 0)
    {
        if (b3dSound != field_1D_b3d_sound)
        {
            if (b3dSound)
            {
                if (gSampManager_6FFF00.sub_58D820(&field_1C_samp_count))
                {
                    field_1D_b3d_sound = 1;
                    field_10_nActiveSamples = field_1C_samp_count; // note: regswap from redundant local
                    return 1;
                }
                else
                {
                    gSampManager_6FFF00.AllocSamples_58D9F0(1);
                    field_1D_b3d_sound = 0;
                    field_10_nActiveSamples = 16;
                    return 0;
                }
            }

            if (gSampManager_6FFF00.AllocSamples_58D9F0(1))
            {
                field_1D_b3d_sound = 0;
                field_10_nActiveSamples = 16;
                return 1;
            }

            gSampManager_6FFF00.sub_58D820(&field_1C_samp_count);
            field_1D_b3d_sound = 1;
            field_10_nActiveSamples = field_1C_samp_count;
            return 0;
        }
        return 1;
    }
    return 0;
}

// match
char sound_obj::Get3dSound_41A390()
{
    if (field_0)
    {
        return field_1D_b3d_sound;
    }
    else
    {
        return 0;
    }
}

// match
void sound_obj::Init_15_Array_427180()
{
    for (int i = 0; i < 15; i++)
    {
        field_552C_15array[i] = 121;
    }
    field_5528_idx15_cur = 0;
    field_5529_idx15 = 0;
}

// match
void sound_obj::GenerateIntegerRandomNumberTable_41BA90()
{
    for (int i = 0; i < 5; i++)
    {
        field_1454_anRandomTable[i] = rand();
    }
}

// match
void sound_obj::sub_41B540()
{
    if (field_1D_b3d_sound)
    {
        for (unsigned int idx = 0; idx < field_DBC_SampleRequestQueuesStatus[field_98_nActiveSampleQueue]; idx++)
        {
            sound_0x68 *pIter = &field_9C_asSamples[field_98_nActiveSampleQueue][field_D9C_abSampleQueueIndexTable[field_98_nActiveSampleQueue][idx]];
            if (!pIter->field_18)
            {
                float f28_conv;
                sub_41B520(pIter->field_28, &f28_conv);
                pIter->field_60 = sub_41B660(pIter->field_60, pIter->field_64, (unsigned int)f28_conv);
            }
        }
    }
}

// match
void sound_obj::sub_41B520(int a1, float *a2) // todo: prob a ref ?
{
    *a2 = a1 / 16384.0f;
}

// todo
char sound_obj::sub_41B660(unsigned __int8 a1, unsigned int a2, unsigned int a3)
{
    unsigned int v3; // eax
    int v4; // eax

    v3 = a2 - (a2 >> 2);
    if (a3 <= v3)
    {
        //LOBYTE(v4) = a1;
        v4 = a1;
    }
    else
    {
        return a1 * ((a2 >> 2) + v3 - a3) / (a2 >> 2);
    }
    return v4;
}

// match
void sound_obj::AddDetailsToRequestedOrderList_41A910(unsigned __int8 sample)
{
    unsigned __int8 i = 0;
    while (i < sample)
    {
        if (field_9C_asSamples[field_98_nActiveSampleQueue][field_D9C_abSampleQueueIndexTable[field_98_nActiveSampleQueue][i]].field_48_nCalculatedVolume >
            field_9C_asSamples[field_98_nActiveSampleQueue][sample].field_48_nCalculatedVolume)
        {
            memmove(
                &field_D9C_abSampleQueueIndexTable[field_98_nActiveSampleQueue][i + 1],
                &field_D9C_abSampleQueueIndexTable[field_98_nActiveSampleQueue][i],
                field_10_nActiveSamples - i - 1);
            break;
        }
        i++;
    }

    field_D9C_abSampleQueueIndexTable[field_98_nActiveSampleQueue][i] = sample;
}

// match
void sound_obj::AddSampleToRequestedQueue_41A850()
{
    unsigned int newVol = field_30_sQueueSample.field_1C_ReleasingVolumeModificator * (127 - field_30_sQueueSample.field_24_nVolume);

    unsigned __int8 new_requested_count;
    if (field_DBC_SampleRequestQueuesStatus[field_98_nActiveSampleQueue] < field_10_nActiveSamples)
    {
        new_requested_count = field_DBC_SampleRequestQueuesStatus[field_98_nActiveSampleQueue];
        field_DBC_SampleRequestQueuesStatus[field_98_nActiveSampleQueue]++;
    }
    else
    {
        new_requested_count = field_D9C_abSampleQueueIndexTable[field_98_nActiveSampleQueue][field_10_nActiveSamples-1];

        if (field_9C_asSamples[field_98_nActiveSampleQueue][new_requested_count].field_48_nCalculatedVolume <= newVol)
        {
            return;
        }
    }

    field_30_sQueueSample.field_48_nCalculatedVolume = newVol;
    field_30_sQueueSample.field_2D = 0;

    memcpy(
        &field_9C_asSamples[field_98_nActiveSampleQueue][new_requested_count],
        &field_30_sQueueSample,
        sizeof(sound_0x68));

    AddDetailsToRequestedOrderList_41A910(new_requested_count);
}

// match
int sound_obj::RandomDisplacement_41A650(unsigned int seed)
{
    static bool bPos_61A6C8 = true;

    int value = gSampManager_6FFF00.sub_58DC10(seed);
    if (!value)
    {
        return 0;
    }

    value = field_1454_anRandomTable[seed % 5] % static_cast<unsigned int>(value);
    if (value % 2)
    {
        bPos_61A6C8 = bPos_61A6C8 == false;
    }

    if (!bPos_61A6C8)
    {
        return -value;
    }


    return value;
}

// match
void sound_obj::ServiceSoundEffects_41A3A0()
{
    if (field_2)
    {
        field_98_nActiveSampleQueue = field_98_nActiveSampleQueue != 1;
        ClearRequestedQueue_41B700();
        InterrogateAudioEntities_41A730();
        AddReleasingSounds_41A9D0();
        sub_41B540();
        ProcessActiveQueues_41AB80();
        sub_41A6F0();
    }
}

void sound_obj::InterrogateAudioEntities_41A730()
{
    // todo
}

void sound_obj::AddReleasingSounds_41A9D0()
{
    // todo
}

void sound_obj::ProcessActiveQueues_41AB80()
{
    // todo
}

void sound_obj::sub_41A6F0()
{
    // todo
}

char sound_obj::CalcVolume_41A3F0(unsigned __int8 a1, int a2, int a3)
{
    // todo
    return 0;
}

// match
bool sound_obj::VolCalc_419070(int a2, int a3, char a4)
{
    unsigned __int8 v5 = CalcVolume_41A3F0(a2, a3, field_30_sQueueSample.field_28);
    this->field_30_sQueueSample.field_24_nVolume = v5;
    if (a4)
    {
        this->field_30_sQueueSample.field_24_nVolume = v5 >> 1;
    }
    return this->field_30_sQueueSample.field_24_nVolume != 0 ? true : false;
}

// match
char sound_obj::sub_419020(int a2)
{
    if (field_28 < a2)
    {
        if (!field_2C)
        {
            field_2C = 1;
            field_30_sQueueSample.field_28 = static_cast<int>(sqrt(field_28 / 16384.0) * 16384.0);
        }
        return 1;
    }
    return 0;
}

// match
char sound_obj::sub_4186D0(sound_0x68 *pObj)
{
    pObj->field_3C = 600;
    pObj->field_30 = 1;
    pObj->field_34 = 0;
    pObj->field_38 = -1;
    pObj->field_20_rate = RandomDisplacement_41A650(pObj->field_14_samp_idx) + gSampManager_6FFF00.GetPlayBackRateIdx_58DBF0(pObj->field_14_samp_idx);
    return 1;
}

// match
char sound_obj::sub_4182A0(sound_0x68 *pObj)
{
    pObj->field_14_samp_idx = 0;
    pObj->field_3C = 700;
    pObj->field_30 = 0;
    pObj->field_34 = 0;
    pObj->field_38 = -1;
    pObj->field_20_rate = gSampManager_6FFF00.GetPlayBackRateIdx_58DBF0(0);
    pObj->field_4C = 5;
    return 1;
}

// match
char sound_obj::sub_418130(sound_0x68 *pObj)
{
    pObj->field_14_samp_idx = 24;
    pObj->field_3C = 400;
    pObj->field_4C = 2;
    pObj->field_20_rate = gSampManager_6FFF00.GetPlayBackRateIdx_58DBF0(24);
    pObj->field_30 = 0;
    pObj->field_34 = gSampManager_6FFF00.sub_58DC30(pObj->field_14_samp_idx);
    pObj->field_38 = gSampManager_6FFF00.sub_58DC50(pObj->field_14_samp_idx);
    return 1;
}

// match
char sound_obj::sub_417F40(int a1)
{
    switch (a1)
    {
    case 3:
    case 7:
    case 11:
    case 17:
    case 21:
    case 58:
    case 63:
    case 64:
    case 86:
        return 1;
    default:
        return 0;
    }
}

// match
int sound_obj::sub_417EF0(sound_0x68 *pObj)
{
    pObj->field_14_samp_idx = 29;
    pObj->field_3C = 400;
    pObj->field_20_rate = RandomDisplacement_41A650(29) + gSampManager_6FFF00.GetPlayBackRateIdx_58DBF0(29);
    pObj->field_30 = 1;
    pObj->field_34 = 0;
    pObj->field_38 = -1;
    return 1;
}

// match
int sound_obj::ConvertToPlayBackRate_417C60(int a1)
{
    switch (a1)
    {
    case 13:
    case 36:
        return 22000;
    case 2:
    case 8:
    case 19:
    case 40:
    case 53:
    case 71:
        return 18000;
    case 10:
    case 16:
    case 23:
    case 24:
    case 25:
    case 26:
    case 28:
    case 29:
    case 37:
    case 42:
    case 62:
    case 67:
    case 85:
        return 24000;
    case 1:
    case 22:
    case 30:
    case 46:
    case 49:
    case 83:
        return 16000;
    case 5:
    case 31:
    case 38:
    case 57:
        return 14000;
    case 3:
    case 11:
    case 54:
        return 11000;
    case 17:
    case 21:
    case 63:
        return 10300;
    case 7:
    case 64:
    case 86:
        return 11700;
    case 60:
        return 15000;
    case 27:
        return 11025;
    case 4:
    case 32:
    case 35:
    case 41:
    case 44:
    case 50:
    case 56:
    case 70:
    case 82:
        return 19000;
    default:
        return 22050;
    }
}

// match
char sound_obj::sub_4153F0(sound_0x68 *pObj)
{
    pObj->field_14_samp_idx = 36;
    pObj->field_3C = 400;
    pObj->field_4C = 3;
    pObj->field_20_rate = gSampManager_6FFF00.GetPlayBackRateIdx_58DBF0(36);
    pObj->field_30 = 0;
    pObj->field_34 = gSampManager_6FFF00.sub_58DC30(36);
    pObj->field_38 = gSampManager_6FFF00.sub_58DC50(36);
    return 1;
}

// match
void sound_obj::ResetEntry_41A6C0(int idx)
{
    field_147C[idx].field_0_bUsed = 0;
    field_147C[idx].field_1 = 0;
    field_147C[idx].field_4_pObj = 0;
    field_147C[idx].field_8_pAlloc = 0;
}

void sound_obj::null_412240()
{

}

void sound_obj::sub_418C20()
{
    // todo
}

// match
void sound_obj::sub_419E10()
{
    if (!field_0)
    {
        null_412240();
        field_0 = gSampManager_6FFF00.SoundInit_58D6C0(&field_5440);
        if (field_0)
        {
            field_1D_b3d_sound = 0;
            field_10_nActiveSamples = 16;
            sub_418C20();
        }
    }
}

// match
char sound_obj::LoadStyle_41A1B0(const char *pStyleName)
{
    if (field_0)
    {
        return gSampManager_6FFF00.LoadWavSdtData_58E980(GetFileName_41A1E0(pStyleName));
    }
    return 0;
}

char byte_674E28[80];

const char* sound_obj::GetFileName_41A1E0(const char *pStr)
{
    const char *pSlashStr; // eax
    const char *pAfterSlash; // eax
    char after_slash_char; // dl
    unsigned __int8 total_idx; // si
    int dst_idx; // ecx
    const char *result; // eax
    unsigned __int8 src_idx; // [esp+8h] [ebp+4h]

    pSlashStr = strrchr(pStr, '\\');
    if (pSlashStr)
        pAfterSlash = pSlashStr + 1;
    else
        pAfterSlash = pStr;
    after_slash_char = *pAfterSlash;
    src_idx = 0;
    if (*pAfterSlash == '.')
    {
        total_idx = 0;
    }
    else
    {
        total_idx = 0;
        dst_idx = 0;
        do
        {
            if (!after_slash_char)
                break;
            byte_674E28[dst_idx] = after_slash_char;
            total_idx = ++src_idx;
            dst_idx = src_idx;
            after_slash_char = pAfterSlash[src_idx];
        } while (after_slash_char != '.');
    }
    result = byte_674E28;
    byte_674E28[total_idx] = 0;
    return result;
}

struct naughty_elion_0x4C;
struct inspiring_cori_0xBC;
struct naughty_elion_0x4C;

struct brave_archimedes_0x3C
{
    __int16 field_0;
    __int16 field_2;
    naughty_elion_0x4C *field_4_pUnk;
    inspiring_cori_0xBC *field_8_cori_or_leaky;
    naughty_elion_0x4C *field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    __int16 field_20;
    __int16 field_22;
    __int16 field_24;
    __int16 field_26;
    int field_28;
    char field_2C;
    char field_2D;
    char field_2E;
    char field_2F;
    int field_30;
    int field_34;
    char field_38;
    char field_39;
    char field_3A;
    char field_3B;
};

// todo
int sound_obj::AddSoundObject_419FA0(infallible_turing* pTuring)
{
    unsigned int idx = 1;
    if (!this->field_0 || !pTuring)
    {
        return 0;
    }

    vigilant_maxwell *pMaxwellIter = &this->field_147C[1];
    while(idx < 1020)
    {
        if (!pMaxwellIter->field_0_bUsed)
        {
            if (pTuring->field_0_object_type == 5) // DrawUnk_0xBC ?
            {
                if (!this->field_1478_type5Idx)
                {
                    this->field_1478_type5Idx = idx;
                }
                else
                {
                    return 0;
                }
            }

            ResetEntry_41A6C0(idx);

            field_147C[idx].field_4_pObj = pTuring;
            field_147C[idx].field_0_bUsed = 1;
            field_147C[idx].field_1 = 1;
            this->field_444C_pEntities[this->field_543C_444C_max_idx++] = idx;

            switch (pTuring->field_0_object_type)
            {
            case 1: // brave_archimedes_0x3C ?
            {
                brave_archimedes_0x3C *v7 = (brave_archimedes_0x3C*)field_147C[idx].field_4_pObj->field_C_pObject;
                if (v7)
                {
                    switch(v7->field_30)
                    {
                    case 2: // note: sub eax, 2 added via switch case instead of if
                        sound_unknown_0xC *pNewObj = new sound_unknown_0xC();
                        field_147C[idx].field_8_pAlloc = pNewObj;
                        pNewObj->field_0 = dword_674CD8;
                        pNewObj->field_8 = 0;
                        pNewObj->field_A = 0;
                        break;
                    }
                }
                break;
            }

            case 2:
            {
                sub_57EA10();
                break;
            }
            }

            return idx;
        }
        idx++;
       
        ++pMaxwellIter;
    }

    return 0;

    
}

void sound_obj::FreeSoundEntry_41A090(unsigned int idx)
{
    vigilant_maxwell *pMaxwell; // ebx
    infallible_turing *pTuring; // eax
    vigilant_maxwell *pUnknown; // edi
    brave_archimedes_0x3C *pAny; // eax
    unsigned int idx_iter; // eax
    unsigned int field_543C_444C_max_idx; // ecx
    int *pEntityIter; // edx
    int new_max; // eax

    if (!this->field_0)
    {
        return;
    }
    
    if (idx >= 1020)
    {
        return;
    }

    pMaxwell = &this->field_147C[idx];

    if (!pMaxwell->field_0_bUsed)
    {
        return;
    }

    pTuring = this->field_147C[idx].field_4_pObj;
    pUnknown = (vigilant_maxwell *)((char *)this + 0xC * idx);

    // 1-1 = 0 looking for 1
    switch(pTuring->field_0_object_type)
    {
    case 1:
    {
        pAny = (brave_archimedes_0x3C *)pTuring->field_C_pObject;
        if (pAny)
        {
            switch (pAny->field_30)
            {
            case 2:
                if (pUnknown[0x1B5].field_8_pAlloc)// type is 1 or 2
                {
                    delete (pUnknown[0x1B5].field_8_pAlloc);
                }
                break;
            }

        }
        else
        {
            goto do_fade;
        }
    }
    break;

    case 2:
    {
    do_fade:
        this->field_3 = 0;
        gSampManager_6FFF00.FadeOut_58E490();
        goto not_type1_or_2_and_after_fade;
    }

    }

not_type1_or_2_and_after_fade:
    pMaxwell->field_0_bUsed = 0;
    idx_iter = 0;
    pUnknown[437].field_4_pObj->field_C_pObject = 0;
    pUnknown[437].field_1 = 0;
    if (pUnknown[437].field_4_pObj->field_0_object_type == 5)
    {
        this->field_1478_type5Idx = 0;
    }

    field_543C_444C_max_idx = this->field_543C_444C_max_idx;
   // if (field_543C_444C_max_idx)
    {
        while (idx_iter < field_543C_444C_max_idx)
        {
            if (idx == field_444C_pEntities[idx_iter])
            {
                if (idx_iter < 1019)
                {
                    memmove(
                        &this->field_444C_pEntities[idx_iter],
                        &this->field_444C_pEntities[idx_iter + 1],
                        4 * (field_543C_444C_max_idx + 0x3FFFFFFF * (idx_iter + 1)));
                }

                new_max = this->field_543C_444C_max_idx - 1;
                this->field_543C_444C_max_idx = new_max;
                this->field_444C_pEntities[new_max] = 0;
                break;
            }
            idx_iter++;
        }



      
    }
}

void sound_obj::Release_41A290()
{
    // todo
}

unsigned __int8 sound_obj::GetCDVol_41A280()
{
    return field_25_cdVol;
}

void sound_obj::sub_57EA10()
{
    // todo
}
