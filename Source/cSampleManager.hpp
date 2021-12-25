#pragma once

#include "3rdParty/mss.h"
#include "types.hpp"

struct sdt_entry_0x18
{
    int field_0_offset;
    int field_4_sample_length;
    int field_8_playBackRate;
    int field_C; // enable random displacement ?
    int field_10; // loop start?
    int field_14; // loop end? -1 if no loop?
};

class cSampleManager
{
public:
    EXPORT cSampleManager();

    EXPORT char sub_58D620();

    EXPORT char SoundInit_58D6C0(int *a2);

    EXPORT char sub_58D720(char a2, char a3, int sampleRate);

    // todo: order

    EXPORT char AllocSamples_58D9F0(int a2);

    EXPORT void sub_58E8C0(unsigned int idx, unsigned int a3);

    EXPORT char sub_58D820(BYTE *pMaxSamples);

    EXPORT void Reset3DSamples_58D960();

    EXPORT void AllocSample_58DA80();

    EXPORT void ReleaseSample_58DAC0();

    EXPORT void Terminate_58DAE0();

    EXPORT void Shutdown_58DB30();

    EXPORT int GetPlayBackRateIdx_58DBF0(int idx);

    EXPORT int sub_58DC10(int idx);

    EXPORT int sub_58DC30(int a2);

    EXPORT int sub_58DC50(int a2);

    EXPORT int GetSampleLength_maybe_58DC70(int a2);

    EXPORT void sub_58DC90(int channel, int a3);

    EXPORT void SetChannelVolume_58DCE0(int channel, int volume);

    EXPORT void SetChannelPan_58DD00(int channel, int pan);

    EXPORT void SetChannelFrequency_58DD20(int channel, int frequency);

    EXPORT void SetChannelLoopPoints_58DD40(int channel, int startOffset, int endOffset);

    EXPORT void SetChannelLoopCount_58DD60(int channel, int loopCount);

    EXPORT bool GetChannelUsedFlag_58DD80(int channel);

    EXPORT void StartChannel_58DDB0(int channel);

    EXPORT void StopChannel_58DDD0(int channel);

    EXPORT bool InitialiseChannel3D_58DDF0(int channel, int nSfx, int rate);

    EXPORT void SetChannel3DVolume_58DE80(int idx, int vol);

    EXPORT void SetChannel3DPosition_58DEA0(int channel, float x, float y, float z);

    EXPORT void SetChannel3DDistances_58DED0(int a2, float a3, float a4);

    EXPORT void SetChannel3DFrequency_58DF00(int a2, int a3);

    EXPORT void SetChannel3DLoopPoints_58DF20(int a2, int a3, int a4);

    EXPORT void SetChannel3DLoopCount_58DF50(int channel, int a3);

    EXPORT bool GetChannel3DUsedFlag_58DF70(int a2);

    EXPORT void StartChannel3D_58DFA0(int samp_idx);

    EXPORT void StopChannel3D_58DFC0(int samp_idx);

    EXPORT void sub_58E010(int a2);

    EXPORT char sub_58E140(int a2);

    // todo order
    EXPORT void Close3DProvider_58E1C0();

    // todo order
    EXPORT void Enum3DProviders_58E1F0();

    // order func

    EXPORT bool StreamStatus_58E2C0();

    EXPORT void StreamSetVolume_58E2F0(unsigned __int8 vol);

    EXPORT void OpenStream_58E320(unsigned int a2);

    EXPORT void CloseStream_58E460();

    EXPORT void FadeOut_58E490();

    EXPORT char MusicFileExists_58E500();

    EXPORT void PlayVocal_58E510(int stream_idx, int voc_idx, char bAppendA);

    EXPORT void CloseVocalStream_58E6A0(int stream_idx);

    EXPORT void SetVocalVolume_58E6D0(int stream_idx, unsigned __int8 vol);

    EXPORT void SetVocalSpeed_58E700(int stream_idx, int playbackRate);

    EXPORT int GetVocalSpeed_58E720(int stream_idx);

    EXPORT void SetVocalPosMs_58E750(int stream_idx, int ms_pos);

    EXPORT int GetVocalPosMs_58E770(long stream_idx);

    EXPORT int GetVocalLengthMs_58E7A0(long stream_idx);

    EXPORT void SetSampleVol_58E7D0(unsigned __int8 vol);

    EXPORT void PlayAtIdx_58E7F0(int idx);

    EXPORT bool SampleNotDone_58E880();

    EXPORT void EndSample_58E960();

    EXPORT char LoadWavSdtData_58E980(const char *pRawOrSdtName);

    EXPORT BYTE sub_58E2A0();

    EXPORT void Release_58E290();

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
    sdt_entry_0x18 field_A8_sdt_entries[320];
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

extern cSampleManager gSampManager_6FFF00;
