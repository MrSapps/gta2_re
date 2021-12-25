#include "sound_obj.hpp"
#include "cSampleManager.hpp"

sound_obj gSound_obj_66F680;

int dword_674CD8;

// match
void sound_obj::ClearRequestedQueue_41B700()
{
    for (unsigned int i = 0; i < field_10_nActiveSamples; i++)
    {
        field_D9C_abSampleQueueIndexTable[field_98_nActiveQueue][i] = field_10_nActiveSamples;
    }

    field_DBC_SampleRequestQueuesStatus[field_98_nActiveQueue] = 0;
}

// match
void sound_obj::ClearActivateSamples_41B7A0()
{
    for (unsigned __int8 i = 0; i < field_10_nActiveSamples; i++ )
    {
        field_DC0[i].field_0 = 0;
        field_DC0[i].field_4 = 0;
        field_DC0[i].field_14_samp_idx = 321;
        field_DC0[i].field_8_obj = dword_674CD8; // vec3 type ?
        field_DC0[i].field_C = dword_674CD8;
        field_DC0[i].field_10 = dword_674CD8;
        field_DC0[i].field_18 = 0;
        field_DC0[i].field_1C = 4;
        field_DC0[i].field_20_rate = 22050;
        field_DC0[i].field_58_type = 0;
        field_DC0[i].field_24 = 0;
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
        field_DC0[i].field_48 = 0;
        field_DC0[i].field_4C = 0;
        field_DC0[i].field_50 = -1;
        field_DC0[i].field_5C = 0;
    }
}

// match
void sound_obj::sub_41A2A0()
{
    field_98_nActiveQueue = 1;
    ClearRequestedQueue_41B700();
    field_98_nActiveQueue = 0;

    ClearRequestedQueue_41B700();
    ClearActivateSamples_41B7A0();

    field_1450 = 0;

    gSampManager_6FFF00.sub_58E2A0();
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
        for (unsigned int idx = 0; idx < field_DBC_SampleRequestQueuesStatus[field_98_nActiveQueue]; idx++)
        {
            sound_0x68 *pIter = &field_9C[field_98_nActiveQueue][field_D9C_abSampleQueueIndexTable[field_98_nActiveQueue][idx]];
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

void sound_obj::AddDetailsToRequestedOrderList_41A910(unsigned __int8 a2)
{
    unsigned __int8 idx = 0;
    for (; idx < a2; idx++)
    {
        if (field_9C[field_98_nActiveQueue][field_D9C_abSampleQueueIndexTable[field_98_nActiveQueue][idx]].field_48 >
            field_9C[field_98_nActiveQueue][a2].field_48)
        {
            memmove(
                &field_D9C_abSampleQueueIndexTable[field_98_nActiveQueue][idx + 1],
                &field_D9C_abSampleQueueIndexTable[field_98_nActiveQueue][idx],
                field_10_nActiveSamples - idx - 1);
            break;
        }
    }

    field_D9C_abSampleQueueIndexTable[field_98_nActiveQueue][idx] = a2;
   
}
