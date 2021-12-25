#include "wizardly_margulis.hpp"
#include <stdio.h>

wizardly_margulis gWizardly_margulis_6FFF00;

struct voc_name
{
    char field_0_str[30];
};

const voc_name gVocNames_5FEA5C[98] =
{
    { "accuracyb.wav" },
    { "back2front.wav" },
    { "busted.wav" },
    { "carjacker.wav" },
    { "copkilla.wav" },
    { "elvis.wav" },
    { "expiditious.wav" },
    { "freeze.wav" },
    { "frenzyfail.wav" },
    { "frenzypassed.wav" },
    { "fryingtonite.wav" },
    { "gameover.wav" },
    { "genocide.wav" },
    { "gta.wav" },
    { "insanestunt.wav" },
    { "jobcomplete.wav" },
    { "jobfail.wav" },
    { "killfrenzy.wav" },
    { "medicalemer.wav" },
    { "respectis.wav" },
    { "shocking.wav" },
    { "somethingscookin.wav" },
    { "timesup.wav" },
    { "toasted.wav" },
    { "wasted.wav" },
    { "wipeout.wav" },
    { "bombarmed.wav" },
    { "macgun.wav" },
    { "dualpist.wav" },
    { "electro.wav" },
    { "flamet.wav" },
    { "grenades.wav" },
    { "molotovs.wav" },
    { "oilslick.wav" },
    { "pistolp.wav" },
    { "rocketl.wav" },
    { "shotgun.wav" },
    { "silentmg.wav" },
    { "vehbomb.wav" },
    { "vehbomb2.wav" },
    { "vehmacgun.wav" },
    { "vehmines.wav" },
    { "armour.wav" },
    { "copbribe.wav" },
    { "doubledamage.wav" },
    { "electrofingers.wav" },
    { "fastreload.wav" },
    { "getoutjail.wav" },
    { "health.wav" },
    { "instantgang.wav" },
    { "invisibility.wav" },
    { "invulnerability.wav" },
    { "life.wav" },
    { "multiplyer.wav" },
    { "respect.wav" },
    { "raceover.wav" },
    { "2ndlap.wav" },
    { "finallap.wav" },
    { "raceon.wav" },
    { "30peopledown.wav" },
    { "60peopledown.wav" },
    { "90peopledown.wav" },
    { "120peopledown.wav" },
    { "150peopledown.wav" },
    { "timeout.wav" },
    { "timeextended.wav" },
    { "timesup.wav" },
    { "sorrydidthathurt.wav" },
    { "nicework.wav" },
    { "choctastic.wav" },
    { "raspberryripple.wav" },
    { "youshotyourload.wav" },
    { "oohdidthathurt.wav" },
    { "deathtoicvans.wav" },
    { "crispycritter.wav" },
    { "youretoastbuddy.wav" },
    { "eatleaddeath.wav" },
    { "thatsgottahurt.wav" },
    { "sorryaboutthat.wav" },
    { "xinloimyman.wav" },
    { "damnsundaydrivers.wav" },
    { "suckitandsee.wav" },
    { "tastemywrath.wav" },
    { "hallelujah.wav" },
    { "damnation.wav" },
    { "laugh1.wav" },
    { "laugh2.wav" },
    { "laugh3.wav" },
    { "laugh4.wav" },
    { "laugh5.wav" },
    { "laugh6.wav" },
    { "laugh7.wav" },
    { "laugh8.wav" },
    { "laugh9.wav" },
    { "laugha.wav" },
    { "laughb.wav" },
    { "laughc.wav" },
    { "laughd.wav" }
};



// 0x58D400
wizardly_margulis::wizardly_margulis()
{
    field_1EA8_pAudioBuffer1 = 0;
    field_1EAC_pAudioBuffer2 = 0;

    memset(field_58_hSamples, 0, sizeof(field_58_hSamples));
 
    field_9C_hStreams[0] = 0;
    field_9C_hStreams[1] = 0;

    memset(field_26C4_3d_sample, 0, sizeof(field_26C4_3d_sample));

    field_A4_bLoaded = 0;

    for (int i = 0; i < 320; i++)
    {
        field_A8_sdt_entries[i].field_0_offset = 0;
        field_A8_sdt_entries[i].field_4_sample_length = 0;
        field_A8_sdt_entries[i].field_8_playBackRate = 11025;
        field_A8_sdt_entries[i].field_C = 0;
        field_A8_sdt_entries[i].field_10 = 0;
        field_A8_sdt_entries[i].field_14 = -1;

    }

    field_0_hDriver = 0;
    field_1EB0_count_samples = 16;
    field_1EB1_unknown = 2;
    field_1EB2_3d_samp_count = 0;
    field_26B4_env_idx = -1;
    field_26B8_bHave_env = 0;
    field_26C0_3d_provider = 0;
    field_2704_float = -1.0;
    field_2708_float = -1.0;
    field_270C_float = -1.0;
    field_26BC_k17 = 0;
    field_2710_3d_provider_count = 0;
    field_2714_bUnknown = 0;
    
    sub_58D620();

    field_4_gtaAudioDriveLetter = 0;

    field_5_str[80] = 0;

    unsigned int driveLetter = 'C';
    while (driveLetter <= 'Z')
    {
        char driveStr[2];
        driveStr[0] = driveLetter;
        driveStr[1] = 0;
        strcpy(field_5_str, driveStr);
        strcat(field_5_str, ":\\GTAUDIO\\");

        char FileName[80];
        strcpy(FileName, field_5_str);
        strcat(FileName, "1.wav");

        FILE* hFile = fopen(FileName, "rb");
        if (hFile)
        {
            fclose(hFile);
            field_5_str[80] = 1;
            field_4_gtaAudioDriveLetter = driveLetter;
            break;
        }
        driveLetter++;
    }

}

char wizardly_margulis::sub_58D620()
{
    // todo
    return 0;
    /*
    char v1; // bl
    char v2; // [esp+3h] [ebp-Dh]
    int Data; // [esp+4h] [ebp-Ch] BYREF
    HKEY phkResult; // [esp+8h] [ebp-8h] BYREF
    DWORD dwDisposition; // [esp+Ch] [ebp-4h] BYREF

    if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, "Software\\Aureal\\A3D", 0, 0, 0, 0x20006u, 0, &phkResult, &dwDisposition))
        return 0;
    Data = 0;
    if (RegSetValueExA(phkResult, "SplashScreen", 0, 4u, (const BYTE *)&Data, 4u))
        v1 = 0;
    else
        v1 = v2;
    Data = 0;
    if (RegSetValueExA(phkResult, "SplashAudio", 0, 4u, (const BYTE *)&Data, 4u))
        v1 = 0;
    RegCloseKey(phkResult);
    return v1;
    */
}

// match
char wizardly_margulis::SoundInit_58D6C0(int *a2)
{
    AIL_startup();

    if (!sub_58D720(1, this->field_2714_bUnknown, 22050))
    {
        AIL_shutdown();
        return 0;
    }

    Enum3DProviders_58E1F0();
    
    field_1EB0_count_samples = 16;
    AllocSamples_58D9F0(1);

    if (field_0_hDriver)
    {
        AIL_set_digital_master_volume(field_0_hDriver, 127);
    }
    return 1;
}

// match
char wizardly_margulis::sub_58D720(char a2, char a3, int sampleRate)
{
    struct lol
    {
        WAVEFORMAT waveFormat; // [esp+Ch] [ebp-10h] BYREF
        __int16 t;
    };
    lol l;

    if (a2)
    {
        this->field_1EB1_unknown = 2;
    }
    else
    {
        this->field_1EB1_unknown = 1;
    }

    l.waveFormat.nChannels = 2;
    l.waveFormat.nSamplesPerSec = sampleRate;
    l.waveFormat.nAvgBytesPerSec = 2 * sampleRate * field_1EB1_unknown;
    l.waveFormat.wFormatTag = 1;
    l.waveFormat.nBlockAlign = (unsigned __int8)(2 * field_1EB1_unknown);

    // todo: not sure how/why this is here ??
    l.t = (unsigned __int8)(8 * field_1EB1_unknown);

    AIL_set_preference(1, 37);                    // DIG_MIXER_CHANNELS
    AIL_set_preference(15, 0);                    // DIG_USE_WAVEOUT

    if (a3 != 0)
    {
        AIL_set_preference(33, 1);
    }
    else
    {
        AIL_set_preference(33, 0);
    }

    AIL_set_preference(31, 1);                    // DIG_ENABLE_RESAMPLE_FILTER 

    if (AIL_waveOutOpen(&this->field_0_hDriver, 0, -1, &l.waveFormat))
    {
        return 0;
    }

    this->field_2714_bUnknown = a3;
    
    AllocSample_58DA80();

    this->field_1EA8_pAudioBuffer1 = AIL_mem_alloc_lock(6100000);
    if (!field_1EA8_pAudioBuffer1)
    {
        ReleaseSample_58DAC0();
        AIL_waveOutClose(this->field_0_hDriver);
        return 0;
        
    }
    this->field_1EAC_pAudioBuffer2 = field_1EA8_pAudioBuffer1;
    return 1;
}

// match
void wizardly_margulis::Enum3DProviders_58E1F0()
{
    HPROENUM hEnum = 0;
    unsigned int prov_counter = 0;
    while (prov_counter < 256)
    {
        char* pName;
        if (!AIL_enumerate_3D_providers(&hEnum, &field_1EB4_h3dProvider[prov_counter], &pName))
        {
            break;
        }

        field_22B4_str[prov_counter] = (char *)operator new(0x50u);
        strcpy(field_22B4_str[prov_counter], pName);

        prov_counter++;
    }
    field_2710_3d_provider_count = prov_counter;
}

bool wizardly_margulis::StreamStatus_58E2C0()
{
    if (!this->field_5_str[80])
        return 0;
    if (this->field_9C_hStreams[0])
        return AIL_stream_status(this->field_9C_hStreams[0]) == 2;
    return 1;
}

// match
char wizardly_margulis::AllocSamples_58D9F0(int a2)
{
    Terminate_58DAE0();
    Reset3DSamples_58D960();

    if (this->field_2714_bUnknown)
    {
        AIL_waveOutClose(this->field_0_hDriver);

        if (sub_58D720(1, 0, 22050) == 0)
        {
            return 0;
        }
    }

    for (unsigned int i = 0; i < field_1EB0_count_samples; i++)
    {
        field_58_hSamples[i] = AIL_allocate_sample_handle(field_0_hDriver);
        AIL_init_sample(field_58_hSamples[i]);
        AIL_set_sample_type(field_58_hSamples[i], 1, 1);
    }

    return 1;
}

// match
void wizardly_margulis::Terminate_58DAE0()
{
    for (unsigned __int8 i = 0; i < field_1EB0_count_samples; i++)
    {
        AIL_release_sample_handle(field_58_hSamples[i]);
        field_58_hSamples[i] = 0;
    }
}

void wizardly_margulis::Shutdown_58DB30()
{
    unsigned int i; // ebx
    int v3; // esi
    int v4; // ebp
    HDIGDRIVER  field_0_hDriver; // edx
    unsigned __int8 v6; // [esp+10h] [ebp-4h]

    for (i = 0; i < 2; ++i)
    {
        if (!i)
        {
            if (this->field_5_str[80])
            {
                if (this->field_9C_hStreams[0])
                {
                    v6 = AIL_stream_volume(this->field_9C_hStreams[0]);
                    if (v6)
                    {
                        v3 = v6;
                        v4 = v6;
                        do
                        {
                            AIL_set_stream_volume(this->field_9C_hStreams[0], v3);
                            AIL_delay(1);
                            --v3;
                            --v4;
                        } while (v4);
                    }
                }
            }
        }
        if (this->field_9C_hStreams[i])
        {
            AIL_close_stream(this->field_9C_hStreams[i]);
            this->field_9C_hStreams[i] = 0;
        }
    }

    ReleaseSample_58DAC0();
    Reset3DSamples_58D960();
    Terminate_58DAE0();

    AIL_mem_free_lock(this->field_1EA8_pAudioBuffer1);
    field_0_hDriver = this->field_0_hDriver;
    this->field_1EA8_pAudioBuffer1 = 0;
    this->field_1EAC_pAudioBuffer2 = 0;
    AIL_waveOutClose(field_0_hDriver);
    AIL_shutdown();
}

int wizardly_margulis::GetPlayBackRateIdx_58DBF0(int idx)
{
    int result; // eax

    result = this->field_A8_sdt_entries[idx].field_8_playBackRate;
    if (!result)
    {
        return 1;
    }
    return result;
}

int wizardly_margulis::sub_58DC10(int idx)
{
    return this->field_A8_sdt_entries[idx].field_C;
}

// match
void wizardly_margulis::Reset3DSamples_58D960()
{
    for (unsigned int i = 0; i < field_1EB2_3d_samp_count; i++)
    {
        if (field_26C4_3d_sample[i])
        {
            AIL_release_3D_sample_handle(field_26C4_3d_sample[i]);
            field_26C4_3d_sample[i] = 0;
        }
    }

    Close3DProvider_58E1C0();

    field_1EB0_count_samples = 16;
    field_1EB2_3d_samp_count = 0;
    field_26B4_env_idx = -1;
    field_26B8_bHave_env = 0;
    field_26C0_3d_provider = 0;
    field_2704_float = -1.0;
    field_2708_float = -1.0;
    field_270C_float = -1.0;
    field_26BC_k17 = 0;
}

int wizardly_margulis::sub_58DC30(int a2)
{
    return field_A8_sdt_entries[a2].field_10;
}

int wizardly_margulis::sub_58DC50(int a2)
{
    return field_A8_sdt_entries[a2].field_14;
}

int wizardly_margulis::GetSampleLength_maybe_58DC70(int a2)
{
    return field_A8_sdt_entries[a2].field_4_sample_length;
}

void wizardly_margulis::sub_58DC90(int channel, int a3)
{
    HSAMPLE  v3; // edx

    v3 = this->field_58_hSamples[channel];
    if (v3)
    {
        if (this->field_A4_bLoaded)
            AIL_set_sample_address(
                v3,
                (BYTE*)this->field_1EAC_pAudioBuffer2 + this->field_A8_sdt_entries[a3].field_0_offset,
                this->field_A8_sdt_entries[a3].field_4_sample_length);
    }
}

void wizardly_margulis::SetChannelVolume_58DCE0(int a2, int a3)
{
    HSAMPLE  v3; // eax

    v3 = this->field_58_hSamples[a2];
    if (v3)
    {
        AIL_set_sample_volume(v3, a3);
    }
}

void wizardly_margulis::SetChannelPan_58DD00(int a2, int a3)
{
    HSAMPLE  v3; // eax

    v3 = this->field_58_hSamples[a2];
    if (v3)
    {
        AIL_set_sample_pan(v3, a3);
    }
}

void wizardly_margulis::SetChannelFrequency_58DD20(int a2, int a3)
{
    HSAMPLE  v3; // eax

    v3 = this->field_58_hSamples[a2];
    if (v3)
    {
        AIL_set_sample_playback_rate(v3, a3);
    }
}

void wizardly_margulis::SetChannelLoopPoints_58DD40(int a2, int a3, int a4)
{
    HSAMPLE  v4; // eax

    v4 = this->field_58_hSamples[a2];
    if (v4)
    {
        AIL_set_sample_loop_block(v4, a3, a4);
    }
}

void wizardly_margulis::SetChannelLoopCount_58DD60(int a2, int a3)
{
    HSAMPLE  v3; // eax

    v3 = this->field_58_hSamples[a2];
    if (v3)
    {
        AIL_set_sample_loop_count(v3, a3);
    }
}

bool wizardly_margulis::GetChannelUsedFlag_58DD80(int a2)
{
    return field_58_hSamples[a2] && AIL_sample_status(field_58_hSamples[a2]) == 4;
}

void wizardly_margulis::StartChannel_58DDB0(int a2)
{
    if (this->field_58_hSamples[a2])
    {
        AIL_start_sample(this->field_58_hSamples[a2]);
    }
}

void wizardly_margulis::StopChannel_58DDD0(int idx)
{
    if (this->field_58_hSamples[idx])
    {
        AIL_end_sample(this->field_58_hSamples[idx]);
    }
}

bool wizardly_margulis::InitialiseChannel3D_58DDF0(int channel, int nSfx, int rate)
{
    H3DSAMPLE  hSample; // edx
    void* field_1EAC_pAudioBuffer2; // esi
    int field_0_offset; // edi
    int v7; // eax
    AILSOUNDINFO soundInfo; // [esp+0h] [ebp-24h] BYREF

    hSample = this->field_26C4_3d_sample[channel];
    if (!hSample || !this->field_A4_bLoaded)
    {
        return 0;
    }

    field_1EAC_pAudioBuffer2 = this->field_1EAC_pAudioBuffer2;
    soundInfo.format = 1;
    soundInfo.channels = 1;
    field_0_offset = this->field_A8_sdt_entries[nSfx].field_0_offset;
    soundInfo.data_len = this->field_A8_sdt_entries[nSfx].field_4_sample_length;
    soundInfo.rate = rate;
    v7 = 8 * this->field_1EB1_unknown;
    soundInfo.data_ptr = ((BYTE *)field_1EAC_pAudioBuffer2 + field_0_offset);
    soundInfo.bits = v7;
    return AIL_set_3D_sample_info(hSample, &soundInfo) != 0;
}

void wizardly_margulis::SetChannel3DVolume_58DE80(int idx, int vol)
{
    H3DSAMPLE  v3; // eax

    v3 = this->field_26C4_3d_sample[idx];
    if (v3)
    {
        AIL_set_3D_sample_volume(v3, vol);
    }
}

void wizardly_margulis::SetChannel3DPosition_58DEA0(int a2, int a3, int a4, int a5)
{
    H3DSAMPLE  v5; // eax

    v5 = this->field_26C4_3d_sample[a2];
    if (v5)
    {
        AIL_set_3D_position(v5, a3, a4, a5);
    }
}

void wizardly_margulis::SetChannel3DDistances_58DED0(int a2, float a3, float a4)
{
    H3DSAMPLE  hSample; // eax

    hSample = this->field_26C4_3d_sample[a2];
    if (hSample)
    {
        // todo: not in the import lib ??
        AIL_set_3D_sample_distances(hSample, a3, a4, a3, a4);
    }
}

void wizardly_margulis::SetChannel3DFrequency_58DF00(int a2, int a3)
{
    H3DSAMPLE  v3; // eax

    v3 = this->field_26C4_3d_sample[a2];
    if (v3)
    {
        AIL_set_3D_sample_playback_rate(v3, a3);
    }
}

void wizardly_margulis::SetChannel3DLoopPoints_58DF20(int a2, int a3, int a4)
{
    H3DSAMPLE  v4; // eax

    v4 = this->field_26C4_3d_sample[a2];
    if (v4)
    {
        AIL_set_3D_sample_loop_block(v4, a3, a4);
    }
}

void wizardly_margulis::SetChannel3DLoopCount_58DF50(int channel, int a3)
{
    H3DSAMPLE  v3; // eax

    v3 = this->field_26C4_3d_sample[channel];
    if (v3)
    {
        AIL_set_3D_sample_loop_count(v3, a3);
    }
}

bool wizardly_margulis::GetChannel3DUsedFlag_58DF70(int a2)
{
    return this->field_26C4_3d_sample[a2] && AIL_3D_sample_status(this->field_26C4_3d_sample[a2]) == 4;
}

void wizardly_margulis::StartChannel3D_58DFA0(int samp_idx)
{
    if (this->field_26C4_3d_sample[samp_idx])
    {
        AIL_start_3D_sample(this->field_26C4_3d_sample[samp_idx]);
    }
}

void wizardly_margulis::StopChannel3D_58DFC0(int samp_idx)
{
    if (this->field_26C4_3d_sample[samp_idx])
    {
        if (AIL_3D_sample_status(this->field_26C4_3d_sample[samp_idx]) == 4)
        {
            AIL_end_3D_sample(this->field_26C4_3d_sample[samp_idx]);
        }
    }
}

void wizardly_margulis::sub_58E010(int a2)
{
    int field_26C0_3d_provider; // eax

    field_26C0_3d_provider = this->field_26C0_3d_provider;
    if (field_26C0_3d_provider && this->field_26B8_bHave_env && a2 < 26)
    {
        this->field_26BC_k17 = a2;
        AIL_set_3D_provider_preference(field_26C0_3d_provider, "EAX environment selection", &a2);
    }
}

char wizardly_margulis::sub_58E140(int a2)
{
    int v2; // edi
    bool v4; // zf
    int pProvider; // [esp-Ch] [ebp-14h]

    v2 = a2;
    v4 = a2 == -1;
    this->field_26B4_env_idx = a2;
    if (v4)
    {
        return 0;
    }

    a2 = AIL_open_3D_provider(this->field_1EB4_h3dProvider[v2]);
    if (a2)
    {
        this->field_26B4_env_idx = -1;
        return 0;
    }

    pProvider = this->field_1EB4_h3dProvider[v2];
    this->field_26C0_3d_provider = pProvider;
    AIL_3D_provider_attribute(pProvider, "EAX environment selection", &a2);
    if (a2 != -1)
    {
        this->field_26B8_bHave_env = 1;
        sub_58E010(17);
    }
    return 1;
}

// match
void wizardly_margulis::Close3DProvider_58E1C0()
{
    if (field_26C0_3d_provider)
    {
        AIL_close_3D_provider(field_26C0_3d_provider);
        field_26C0_3d_provider = 0;
        Sleep(1500u);
    }
}

void wizardly_margulis::AllocSample_58DA80()
{
    HSAMPLE sample_handle; // eax

    if (!this->field_98_hSample)
    {
        sample_handle = AIL_allocate_sample_handle(this->field_0_hDriver);
        this->field_98_hSample = sample_handle;
        AIL_init_sample(sample_handle);
        AIL_set_sample_type(this->field_98_hSample, 0, 0);
    }
}

void wizardly_margulis::ReleaseSample_58DAC0()
{
    if (this->field_98_hSample)
    {
        AIL_release_sample_handle(this->field_98_hSample);
        this->field_98_hSample = 0;
    }
}

void wizardly_margulis::sub_58E8C0(unsigned int idx, unsigned int a3)
{
    if (idx < a3 && this->field_98_hSample && !SampleNotDone_58E880())
    {
        if (this->field_A4_bLoaded)
        {
            AIL_set_sample_address(
                this->field_98_hSample,
                (BYTE*)this->field_1EAC_pAudioBuffer2 + this->field_A8_sdt_entries[idx].field_0_offset,
                this->field_A8_sdt_entries[a3].field_0_offset - this->field_A8_sdt_entries[idx].field_0_offset);
            AIL_set_sample_playback_rate(this->field_98_hSample, 18050);
            AIL_set_sample_pan(this->field_98_hSample, 64);
            AIL_set_sample_loop_count(this->field_98_hSample, 1);
            AIL_start_sample(this->field_98_hSample);
        }
    }
}

void wizardly_margulis::StreamSetVolume_58E2F0(unsigned __int8 vol)
{
    HSTREAM  v2; // eax

    if (this->field_5_str[80])
    {
        v2 = this->field_9C_hStreams[0];
        if (v2)
        {
            AIL_set_stream_volume(v2, vol);
        }
    }
}

const char dma_wav_5FF5D8[3][6] = { "d.wav", "m.wav", "a.wav" };

void wizardly_margulis::OpenStream_58E320(unsigned int a2)
{
    HSTREAM  hStream; // eax
    char wavPath[80]; // [esp+14h] [ebp-50h] BYREF

    if (this->field_5_str[80])
    {
        if (!this->field_9C_hStreams[0] && a2 < 3)
        {
            strcpy(wavPath, this->field_5_str);
            strcat(wavPath, dma_wav_5FF5D8[a2]);
            hStream = AIL_open_stream(this->field_0_hDriver, wavPath, 0);
            this->field_9C_hStreams[0] = hStream;
            if (hStream
                || a2 == 1
                && (strcpy(wavPath, this->field_5_str),
                    strcat(wavPath, "d.wav"),
                    hStream = AIL_open_stream(this->field_0_hDriver, wavPath, 0),
                    (this->field_9C_hStreams[0] = hStream) != 0))
            {
                AIL_set_stream_loop_count(hStream, 0);
                AIL_start_stream(this->field_9C_hStreams[0]);
            }
        }
    }
}

void wizardly_margulis::CloseStream_58E460()
{
    if (this->field_5_str[80])
    {
        if (this->field_9C_hStreams[0])
        {
            AIL_close_stream(this->field_9C_hStreams[0]);
            this->field_9C_hStreams[0] = 0;
        }
    }
}

void wizardly_margulis::FadeOut_58E490()
{
    int new_vol; // esi
    int vol_fader; // ebx
    unsigned __int8 cur_vol; // [esp+4h] [ebp-4h]

    if (this->field_5_str[80] && this->field_9C_hStreams[0])
    {
        cur_vol = AIL_stream_volume(this->field_9C_hStreams[0]);
        if (cur_vol)
        {
            new_vol = cur_vol;
            vol_fader = cur_vol;
            do
            {
                AIL_set_stream_volume(this->field_9C_hStreams[0], new_vol);
                AIL_delay(1);
                --new_vol;
                --vol_fader;
            } while (vol_fader);
        }
        AIL_close_stream(this->field_9C_hStreams[0]);
        this->field_9C_hStreams[0] = 0;
    }
}

char wizardly_margulis::GetAudioFileName_58E500()
{
    return this->field_5_str[80];
}

void wizardly_margulis::PlayVocal_58E510(int stream_idx, int voc_idx, char bAppendA)
{
    const char *filePart; // edi
    HSTREAM  hStream; // eax
    char Buffer[12]; // [esp+8h] [ebp-5Ch] BYREF
    char fileName[80]; // [esp+14h] [ebp-50h] BYREF

    if (stream_idx || this->field_5_str[80])
    {
        if (this->field_9C_hStreams[stream_idx])
        {
            CloseVocalStream_58E6A0(stream_idx);
        }

        if (stream_idx)
        {
            strcpy(fileName, "data\\audio\\vocals\\");
            filePart = gVocNames_5FEA5C[voc_idx].field_0_str;
        }
        else
        {
            strcpy(fileName, this->field_5_str);
            sprintf(Buffer, "%d", voc_idx);
            strcat(fileName, Buffer);
            if (!bAppendA)
            {
                strcat(fileName, "A");
            }
            filePart = ".WAV";
        }
        strcat(fileName, filePart);
        hStream = AIL_open_stream(this->field_0_hDriver, fileName, 0);
        this->field_9C_hStreams[stream_idx] = hStream;
        if (hStream)
        {
            AIL_set_stream_loop_count(hStream, stream_idx != 0);
            AIL_start_stream(this->field_9C_hStreams[stream_idx]);
        }
    }
}

void wizardly_margulis::CloseVocalStream_58E6A0(int stream_idx)
{
    if (this->field_9C_hStreams[stream_idx])
    {
        AIL_close_stream(this->field_9C_hStreams[stream_idx]);
        this->field_9C_hStreams[stream_idx] = 0;
    }
}

void wizardly_margulis::SetVocalVolume_58E6D0(int stream_idx, unsigned __int8 vol)
{
    HSTREAM  hStream; // eax

    hStream = this->field_9C_hStreams[stream_idx];
    if (hStream)
    {
        AIL_set_stream_volume(hStream, vol);
    }
}

void wizardly_margulis::SetVocalSpeed_58E700(int stream_idx, int playbackRate)
{
    HSTREAM hStream; // eax

    hStream = this->field_9C_hStreams[stream_idx];
    if (hStream)
    {
        AIL_set_stream_playback_rate(hStream, playbackRate);
    }
}

int wizardly_margulis::GetVocalSpeed_58E720(int stream_idx)
{
    if (this->field_9C_hStreams[stream_idx])
    {
        return AIL_stream_playback_rate(this->field_9C_hStreams[stream_idx]);
    }
    else
    {
        return 22050;
    }
}

void wizardly_margulis::SetVocalPosMs_58E750(int stream_idx, int ms_pos)
{
    HSTREAM  hStream; // eax

    hStream = this->field_9C_hStreams[stream_idx];
    if (hStream)
    {
        AIL_set_stream_ms_position(hStream, ms_pos);
    }
}

int wizardly_margulis::GetVocalPosMs_58E770(long stream_idx)
{
    HSTREAM  hStream; // eax

    hStream = this->field_9C_hStreams[stream_idx];
    if (!hStream)
    {
        return 0;
    }
    AIL_stream_ms_position(hStream, 0, &stream_idx);
    return stream_idx;
}

int wizardly_margulis::GetVocalLengthMs_58E7A0(long stream_idx)
{
    HSTREAM  hStream; // eax

    hStream = this->field_9C_hStreams[stream_idx];
    if (!hStream)
    {
        return 0;
    }
    AIL_stream_ms_position(hStream, &stream_idx, 0);
    return stream_idx;
}

void wizardly_margulis::SetSampleVol_58E7D0(unsigned __int8 vol)
{
    HSAMPLE  field_98_hSample; // eax

    field_98_hSample = this->field_98_hSample;
    if (field_98_hSample)
    {
        AIL_set_sample_volume(field_98_hSample, vol);
    }
}

void wizardly_margulis::PlayAtIdx_58E7F0(int idx)
{
    HSAMPLE hSample; // eax
    int playbackRate; // eax

    hSample = this->field_98_hSample;
    if (hSample)
    {
        if (this->field_A4_bLoaded)
        {
            AIL_set_sample_address(
                hSample,
                (BYTE*)this->field_1EAC_pAudioBuffer2 + this->field_A8_sdt_entries[idx].field_0_offset,
                this->field_A8_sdt_entries[idx].field_4_sample_length);
            playbackRate = GetPlayBackRateIdx_58DBF0(idx);
            AIL_set_sample_playback_rate(this->field_98_hSample, playbackRate);
            AIL_set_sample_pan(this->field_98_hSample, 64);
            AIL_set_sample_loop_count(this->field_98_hSample, 1);
            AIL_start_sample(this->field_98_hSample);
        }
    }
}

bool wizardly_margulis::SampleNotDone_58E880()
{
    return AIL_sample_status(this->field_98_hSample) != 2;
}

void wizardly_margulis::EndSample_58E960()
{
    if (field_98_hSample)
    {
        AIL_end_sample(field_98_hSample);
    }
}

// match
char wizardly_margulis::LoadWavSdtData_58E980(const char *pRawOrSdtName)
{
    FILE *hRawFile; // eax
    FILE *hRawFile_; // esi
    unsigned int rawFileSize; // edi
    FILE *hSdtFile; // edi
    char rawName[80]; // [esp+10h] [ebp-A0h] BYREF
    char sdtName[80]; // [esp+60h] [ebp-50h] BYREF

    this->field_A4_bLoaded = 0;
    strcpy(rawName, "data\\audio\\");
    strcat(rawName, pRawOrSdtName);
    strcat(rawName, ".RAW");
    strcpy(sdtName, "data\\audio\\");
    strcat(sdtName, pRawOrSdtName);
    strcat(sdtName, ".SDT");
    hRawFile = fopen(rawName, "rb");
    hRawFile_ = hRawFile;
    if (!hRawFile)
    {
        return 0;
    }

    fseek(hRawFile, 0, 2);
    rawFileSize = ftell(hRawFile_);
    if (rawFileSize > 6100000)
    {
        fclose(hRawFile_);
        return 0;
       
    }

    rewind(hRawFile_);
    fread(this->field_1EA8_pAudioBuffer1, 1u, rawFileSize, hRawFile_);
    fclose(hRawFile_);
    hSdtFile = fopen(sdtName, "rb");
    if (!hSdtFile)
    {
        fclose(hRawFile_);
    }

    fread(this->field_A8_sdt_entries, sizeof(serene_proskuriakova_0x18), 320u, hSdtFile);
    fclose(hSdtFile);
    this->field_A4_bLoaded = 1;
    return 1;
}

// match
BYTE wizardly_margulis::sub_58E2A0()
{
    BYTE ret = field_0_hDriver && AIL_digital_handle_reacquire(field_0_hDriver) ? 1 : 0;
    return ret;
}

char wizardly_margulis::sub_58D820(BYTE *pMaxSamples)
{
    int k256Counter; // edi
    char **i; // ebx
    unsigned int sampIdx; // ebp
    H3DSAMPLE  *field_26C4_3d_sample; // ebx
    H3DSAMPLE  _3D_sample_handle; // eax
    int field_26C0_3d_provider; // [esp-Ch] [ebp-1Ch]

    Terminate_58DAE0();
    Reset3DSamples_58D960();
    if (this->field_2714_bUnknown)
    {
        AIL_waveOutClose(this->field_0_hDriver);
        if (!sub_58D720(1, 0, 22050))
        {
            if (sub_58D720(1, 0, 22050))
            {
                AllocSamples_58D9F0(1);
            }
            return 0;
        }
    }
    k256Counter = 0;
    for (i = this->field_22B4_str;
        !*i
        || strncmp(*i, "Microsoft DirectSound3D hardware support", 0x1Eu)
        || !sub_58E140(k256Counter);
        ++i)
    {
        if ((unsigned int)++k256Counter >= 256)
        {
            return 0;
        }
    }

    if (!this->field_26C0_3d_provider)
    {
        return 0;
    }

    *pMaxSamples = 0;
    field_26C0_3d_provider = this->field_26C0_3d_provider;
    this->field_1EB2_3d_samp_count = 0;
    AIL_3D_provider_attribute(field_26C0_3d_provider, "Maximum supported samples", pMaxSamples);
    if (*pMaxSamples > 16u)
    {
        *pMaxSamples = 16;
    }
    if (*pMaxSamples < 8u)
    {
        goto LABEL_16;
    }
    sampIdx = 0;
    if (*pMaxSamples)
    {
        field_26C4_3d_sample = this->field_26C4_3d_sample;
        while (1)
        {
            _3D_sample_handle = AIL_allocate_3D_sample_handle(this->field_26C0_3d_provider);
            *field_26C4_3d_sample = _3D_sample_handle;
            if (!_3D_sample_handle)
            {
                break;
            }
            ++sampIdx;
            ++field_26C4_3d_sample;
            if (sampIdx >= (unsigned __int8)*pMaxSamples)
            {
                goto LABEL_21;
            }
        }

    LABEL_16:
        *pMaxSamples = 0;
        Close3DProvider_58E1C0();
        return 0;
    }

LABEL_21:
    this->field_1EB2_3d_samp_count = *pMaxSamples;
    return 1;
}
