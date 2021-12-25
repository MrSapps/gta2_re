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

class cSampleManager
{
public:
    cSampleManager();

    char sub_58D620();

    char SoundInit_58D6C0(int *a2);

    char sub_58D720(char a2, char a3, int sampleRate);

    // todo: order

    char AllocSamples_58D9F0(int a2);

    void sub_58E8C0(unsigned int idx, unsigned int a3);

    char sub_58D820(BYTE *pMaxSamples);

    void Reset3DSamples_58D960();

    void AllocSample_58DA80();

    void ReleaseSample_58DAC0();

    void Terminate_58DAE0();

    void Shutdown_58DB30();

    int GetPlayBackRateIdx_58DBF0(int idx);

    int sub_58DC10(int idx);

    int sub_58DC30(int a2);

    int sub_58DC50(int a2);

    int GetSampleLength_maybe_58DC70(int a2);

    void sub_58DC90(int channel, int a3);

    void SetChannelVolume_58DCE0(int channel, int volume);

    void SetChannelPan_58DD00(int channel, int pan);

    void SetChannelFrequency_58DD20(int channel, int frequency);

    void SetChannelLoopPoints_58DD40(int channel, int startOffset, int endOffset);

    void SetChannelLoopCount_58DD60(int channel, int loopCount);

    bool GetChannelUsedFlag_58DD80(int channel);

    void StartChannel_58DDB0(int channel);

    void StopChannel_58DDD0(int channel);

    bool InitialiseChannel3D_58DDF0(int channel, int nSfx, int rate);

    void SetChannel3DVolume_58DE80(int idx, int vol);

    void SetChannel3DPosition_58DEA0(int channel, float x, float y, float z);

    void SetChannel3DDistances_58DED0(int a2, float a3, float a4);

    void SetChannel3DFrequency_58DF00(int a2, int a3);

    void SetChannel3DLoopPoints_58DF20(int a2, int a3, int a4);

    void SetChannel3DLoopCount_58DF50(int channel, int a3);

    bool GetChannel3DUsedFlag_58DF70(int a2);

    void StartChannel3D_58DFA0(int samp_idx);

    void StopChannel3D_58DFC0(int samp_idx);

    void sub_58E010(int a2);

    char sub_58E140(int a2);

    // todo order
    void Close3DProvider_58E1C0();

    // todo order
    void Enum3DProviders_58E1F0();

    // order func

    bool StreamStatus_58E2C0();

    void StreamSetVolume_58E2F0(unsigned __int8 vol);

    void OpenStream_58E320(unsigned int a2);

    void CloseStream_58E460();

    void FadeOut_58E490();

    char MusicFileExists_58E500();

    void PlayVocal_58E510(int stream_idx, int voc_idx, char bAppendA);

    void CloseVocalStream_58E6A0(int stream_idx);

    void SetVocalVolume_58E6D0(int stream_idx, unsigned __int8 vol);

    void SetVocalSpeed_58E700(int stream_idx, int playbackRate);

    int GetVocalSpeed_58E720(int stream_idx);

    void SetVocalPosMs_58E750(int stream_idx, int ms_pos);

    int GetVocalPosMs_58E770(long stream_idx);

    int GetVocalLengthMs_58E7A0(long stream_idx);

    void SetSampleVol_58E7D0(unsigned __int8 vol);

    void PlayAtIdx_58E7F0(int idx);

    bool SampleNotDone_58E880();

    void EndSample_58E960();

    char LoadWavSdtData_58E980(const char *pRawOrSdtName);

    BYTE sub_58E2A0();

    HDIGDRIVER field_0_hDriver;
    char field_4_gtaAudioDriveLetter;
    char field_5_str[80];
    bool field_55_bMusicLoaded;
    short field_56_pad;
    HSAMPLE field_58_hSamples[16];
    HSAMPLE field_98_hSample;
    HSTREAM field_9C_hStreams[2];
    char field_A4_bLoaded;
    char field_A5_pad;
    char field_A6_pad;
    char field_A7_pad;
    serene_proskuriakova_0x18 field_A8_sdt_entries[320];
    void* field_1EA8_pAudioBuffer1;
    void* field_1EAC_pAudioBuffer2;
    unsigned __int8 field_1EB0_count_samples;
    unsigned __int8 field_1EB1_unknown;
    unsigned __int8 field_1EB2_3d_samp_count;
    char field_1EB3_pad;
    HPROVIDER field_1EB4_h3dProvider[256];
    char *field_22B4_str[256];
    HPROVIDER field_26B4_env_idx;
    int field_26B8_bEaxSupported;
    int field_26BC_k17;
    int field_26C0_3d_provider;
    H3DSAMPLE field_26C4_3d_sample[16];
    float field_2704_float;
    float field_2708_float;
    float field_270C_float;
    int field_2710_3d_provider_count;
    char field_2714_bUnknown;
    char field_2715_pad;
    char field_2716_pad;
    char field_2717_pad;
};

extern cSampleManager gWizardly_margulis_6FFF00;
