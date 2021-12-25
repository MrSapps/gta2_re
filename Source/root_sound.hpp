#pragma once

#include <windows.h>

// todo: move
struct infallible_turing;
struct infallible_turing
{
    int field_0;
    char field_4;
    char field_5;
    char field_6;
    char field_7;
    int field_8;
    infallible_turing *field_C;
};

struct root_sound
{
    infallible_turing *field_0;
    infallible_turing field_4[999+1];
    /*
    int field_3E74;
    int field_3E78;
    int field_3E7C;
    int field_3E80_count;
    */
    // todo: ordering

    root_sound();

    char Set3DSound_40F160(char b3dSound);

    char Get3DSound_40F180();

    void sub_40EF80();

    void SetCDVol_40F0F0(unsigned int cdVol);

    void SetSfxVol_40F0B0(unsigned __int8 cdVol);
    
    void Service_40EFA0();

    int sub_40EFB0(infallible_turing* a2);

    char LoadStyle_40EFF0(const char *pStyleName);

    void sub_40EFD0(int a2);

    void Release_40F130();

    void sub_40F140();

    infallible_turing* sub_40EF40(infallible_turing *a2, int a3);

    char GetAudioDriveLetter_40F150();

    unsigned __int8 GetCDVol_40F120();

    int sub_40F090(int state);
};


extern root_sound gRoot_sound_66B038;
