#pragma once

#include "3rdParty/mss.h"

struct serene_proskuriakova_0x18
{
    int field_0_offset;
    int field_4_sample_length;
    int field_8_playBackRate;
    int field_C;
    int field_10;
    int field_14;
};

class wizardly_margulis
{
public:
    wizardly_margulis();

    char sub_58D620();

    char SoundInit_58D6C0(int *a2);

    char sub_58D720(char a2, char a3, int sampleRate);

    // todo: order
    void Enum3DProviders_58E1F0();

    char AllocSamples_58D9F0(int a2);

    HDIGDRIVER field_0_hDriver;
    char field_4_gtaAudioDriveLetter;
    char field_5_str[83];
    int field_58_hSamples[16];
    int field_98_hSample;
    int field_9C_hStreams[2];
    char field_A4_bLoaded;
    char field_A5_pad;
    char field_A6_pad;
    char field_A7_pad;
    serene_proskuriakova_0x18 field_A8_sdt_entries[320];
    void *field_1EA8_pAudioBuffer1;
    int field_1EAC_pAudioBuffer2;
    unsigned __int8 field_1EB0_count_samples;
    unsigned __int8 field_1EB1_unknown;
    unsigned __int8 field_1EB2_3d_samp_count;
    char field_1EB3_pad;
    int field_1EB4_h3dProvider[256];
    const char *field_22B4_str[256];
    int field_26B4_env_idx;
    int field_26B8_bHave_env;
    int field_26BC_k17;
    int field_26C0_3d_provider;
    int field_26C4_3d_sample[16];
    float field_2704_float;
    float field_2708_float;
    float field_270C_float;
    int field_2710_3d_provider_count;
    char field_2714_bUnknown;
    char field_2715_pad;
    char field_2716_pad;
    char field_2717_pad;

    BYTE sub_58E2A0();

    char sub_58D9F0(int a2);

    char sub_58D820(BYTE *a2);
};

extern wizardly_margulis gWizardly_margulis_6FFF00;
