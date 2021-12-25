#include "root_sound.hpp"
#include "sound_obj.hpp"
#include "cSampleManager.hpp"
#include "debug.hpp"

root_sound gRoot_sound_66B038;

// match
void infallible_turing::release_40EF20()
{
    if (field_8)
    {
        gRoot_sound_66B038.sub_40EFD0(field_8);
    }
}

void root_sound::sub_40EF80()
{
    gSound_obj_66F680.sub_419E10();
}

void root_sound::Service_40EFA0()
{
    // todo
    //gSound_obj_66F680.Service_419EF0();
}

int root_sound::sub_40EFB0(infallible_turing* a2)
{
    return gSound_obj_66F680.sub_419FA0(a2);
}

void root_sound::sub_40EFD0(int a2)
{
    gSound_obj_66F680.sub_41A090(a2);
}

char root_sound::LoadStyle_40EFF0(const char *pStyleName)
{
    return gSound_obj_66F680.LoadStyle_41A1B0(pStyleName);
}

void root_sound::sub_40F010()
{
    // todo
}

void root_sound::sub_40F020()
{
    //gSound_obj_66F680.sub_57EA10();
    // todo
}

char* root_sound::sub_40F030(int a1, int a2, int a3)
{
    //return gSound_obj_66F680.sub_57ECB0(a1, a2, a3);
    // todo
    return 0;
}

char root_sound::sub_40F050(int a1, int a2)
{
    //return gSound_obj_66F680.sub_57EE30(a1, a2);
    // todo
    return 0;
}

void root_sound::sub_40F070(char a1)
{
    //gSound_obj_66F680.sub_57EEE0(a1);
    // todo
}

int root_sound::sub_40F090(int state)
{
    // todo
    //return gSound_obj_66F680.sub_418C80(state);
    return 0;
}

void root_sound::SetSfxVol_40F0B0(unsigned __int8 sfxVol)
{
    if (sfxVol <= 127u)
    {
        gSound_obj_66F680.SetSfxVol_41A250(sfxVol);
    }
    else
    {
        gSound_obj_66F680.SetSfxVol_41A250(127);
    }
}

void root_sound::SetCDVol_40F0F0(unsigned int cdVol)
{
    BYTE v = cdVol;
    if (v > 127)
    {
        v = 127;
        gSound_obj_66F680.SetCDVol_41A270(v);
    }
    else
    {
        gSound_obj_66F680.SetCDVol_41A270(v & 0xFF);
    }
}

unsigned __int8 root_sound::GetCDVol_40F120()
{
    return gSound_obj_66F680.field_25_cdVol;
}

void root_sound::Release_40F130()
{
    gSound_obj_66F680.Release_41A290();
}

// match
void root_sound::sub_40F140()
{
    gSound_obj_66F680.sub_41A2A0();
}

char root_sound::GetAudioDriveLetter_40F150()
{
    return gSampManager_6FFF00.field_4_gtaAudioDriveLetter;
}

// match
infallible_turing* root_sound::sub_40EF40(infallible_turing *a2, int a3)
{
    infallible_turing* pTuring = field_0;
    field_0 = field_0->field_C;
    pTuring->field_C = a2;
    pTuring->field_8 = 0;
    pTuring->field_4 = 0;
    pTuring->field_0 = a3;

    if (!bSkip_audio_67D6BE)
    {
        pTuring->field_8 = gRoot_sound_66B038.sub_40EFB0(pTuring);
    }

    return pTuring;
}

// match
char root_sound::Set3DSound_40F160(char b3dSound)
{
    return gSound_obj_66F680.Set3DSound_41A2F0(b3dSound);
}
// match
char root_sound::Get3DSound_40F180()
{
    return gSound_obj_66F680.Get3dSound_41A390();
}



// 0x411E30
root_sound::root_sound() // match
{
    infallible_turing* pIter = field_4;
    for (int i = 0; i < 999; i++)
    {
        pIter->field_C = pIter+1;
        pIter++;
    }

    field_0 = field_4;
    field_4[999].field_C = 0;
}

// 411E60
root_sound::~root_sound()
{
    field_0 = 0;
}
