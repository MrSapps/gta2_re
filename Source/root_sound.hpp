#pragma once

#include <windows.h>

// todo: move
struct infallible_turing
{
    int field_0_object_type;
    char field_4;
    char field_5;
    char field_6;
    char field_7;
    int field_8;
    
    // Type depends on what field_0_object_type is
    void *field_C_pObject;

    void release_40EF20();
};

class root_sound
{
public:

    infallible_turing *field_0;
    infallible_turing field_4[999+1];
    /*
    int field_3E74;
    int field_3E78;
    int field_3E7C;
    int field_3E80_count;
    */
    // todo: ordering

    infallible_turing* CreateSoundObject_40EF40(infallible_turing *pObject, int objectType);

    void sub_40EF80();

    void Service_40EFA0();

    int AddSoundObject_40EFB0(infallible_turing* a2);

    void FreeSoundEntry_40EFD0(int a2);

    char LoadStyle_40EFF0(const char *pStyleName);

    void sub_40F010();

    void sub_40F020();

    char* sub_40F030(int a1, int a2, int a3);

    char sub_40F050(int a1, int a2);

    void sub_40F070(char a1);

    int sub_40F090(int state);

    void SetSfxVol_40F0B0(unsigned __int8 cdVol);

    void SetCDVol_40F0F0(unsigned int cdVol);

    unsigned __int8 GetCDVol_40F120();

    void Release_40F130();

    void sub_40F140();

    char GetAudioDriveLetter_40F150();

    char Set3DSound_40F160(char b3dSound);

    char Get3DSound_40F180();

    root_sound();

    ~root_sound();
};


extern root_sound gRoot_sound_66B038;
