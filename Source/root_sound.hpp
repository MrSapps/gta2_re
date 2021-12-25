#pragma once

#include "types.hpp"
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

    EXPORT infallible_turing* CreateSoundObject_40EF40(infallible_turing *pObject, int objectType);

    EXPORT void sub_40EF80();

    EXPORT void Service_40EFA0();

    EXPORT int AddSoundObject_40EFB0(infallible_turing* a2);

    EXPORT void FreeSoundEntry_40EFD0(int a2);

    EXPORT char LoadStyle_40EFF0(const char *pStyleName);

    EXPORT void sub_40F010();

    EXPORT void sub_40F020();

    EXPORT char* sub_40F030(int a1, int a2, int a3);

    EXPORT char sub_40F050(int a1, int a2);

    EXPORT void sub_40F070(char a1);

    EXPORT int sub_40F090(int state);

    EXPORT void SetSfxVol_40F0B0(unsigned __int8 cdVol);

    EXPORT void SetCDVol_40F0F0(unsigned int cdVol);

    EXPORT unsigned __int8 GetCDVol_40F120();

    EXPORT void Release_40F130();

    EXPORT void sub_40F140();

    EXPORT char GetAudioDriveLetter_40F150();

    EXPORT char Set3DSound_40F160(char b3dSound);

    EXPORT char Get3DSound_40F180();

    EXPORT root_sound();

    EXPORT ~root_sound();
};


extern root_sound gRoot_sound_66B038;
