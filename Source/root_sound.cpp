#include "root_sound.hpp"
#include "sound_obj.hpp"
#include "cSampleManager.hpp"
#include "debug.hpp"

root_sound gRoot_sound_66B038;

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

void root_sound::sub_40EF80()
{
    gSound_obj_66F680.sub_419E10();
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
    //return cdVol;
}

void root_sound::SetSfxVol_40F0B0(unsigned __int8 cdVol)
{
    // todo
}

void root_sound::Service_40EFA0()
{
    // todo
}

int root_sound::sub_40EFB0(infallible_turing* a2)
{
    // todo
    return 0;
}

char root_sound::LoadStyle_40EFF0(const char *pStyleName)
{
    return gSound_obj_66F680.LoadStyle_41A1B0(pStyleName);
}

void root_sound::sub_40EFD0(int a2)
{
    // todo
}

void root_sound::Release_40F130()
{
    // todo
}

// match
void root_sound::sub_40F140()
{
    gSound_obj_66F680.sub_41A2A0();
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
