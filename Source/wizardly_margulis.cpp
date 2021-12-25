#include "wizardly_margulis.hpp"
#include <stdio.h>

wizardly_margulis gWizardly_margulis_6FFF00;

#pragma comment(lib, "C:\\Program Files (x86)\\freeloader.com\\GTA2\\mss32.lib")

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

void wizardly_margulis::Enum3DProviders_58E1F0()
{
    // todo
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

// match
BYTE wizardly_margulis::sub_58E2A0()
{
    BYTE ret = field_0_hDriver && AIL_digital_handle_reacquire(field_0_hDriver) ? 1 : 0;
    return ret;
}

char wizardly_margulis::sub_58D820(BYTE *a2)
{
    // todo
    return 0;
}
