#pragma once


#include "3rdParty/mss.h"

struct serene_proskuriakova_0x18
{
    int field_0;
    int field_4;
    int field_8_playBackRate;
    int field_C;
    int field_10;
    int field_14;
};

struct wizardly_margulis
{
    HDIGDRIVER field_0_hDriver;
    char field_4;
    char field_5_str[83];
    int field_58_hSamples[16];
    int field_98_hSample;
    int field_9C_hStreams[2];
    char field_A4_bLoaded;
    char field_A5;
    char field_A6;
    char field_A7;
    serene_proskuriakova_0x18 field_A8[320];
    void *field_1EA8_pAudioBuffer1;
    int field_1EAC_pAudioBuffer2;
    unsigned __int8 field_1EB0_count_samples;
    unsigned __int8 field_1EB1;
    unsigned __int8 field_1EB2_3d_samp_count;
    char field_1EB3;
    int field_1EB4_h3dProvider[256];
    const char *field_22B4_str[256];
    int field_26B4;
    int field_26B8;
    int field_26BC;
    int field_26C0_3d_provider;
    int field_26C4_3d_sample[16];
    int field_2704;
    int field_2708;
    int field_270C;
    int field_2710_3d_provider_count;
    char field_2714;
    char field_2715;
    char field_2716;
    char field_2717;

    BYTE sub_58E2A0();

    char sub_58D9F0(int a2);

    char sub_58D820(BYTE *a2);
};

extern wizardly_margulis gWizardly_margulis_6FFF00;
