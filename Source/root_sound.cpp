#include "root_sound.hpp"
#include "sound_obj.hpp"
#include "cSampleManager.hpp"

root_sound gRoot_sound_66B038;

// match
char root_sound::Set3DSound_40F160(char b3dSound)
{
    return gSound_obj_66F680.Set3DSound_41A2F0(b3dSound);
}

char root_sound::Get3DSound_40F180()
{
    // todo
    return 0;
}

void root_sound::sub_40EF80()
{
    // todo
    /*
    if (!gSound_obj_66F680.field_0)
    {
        gSound_obj_66F680.sub_412240();
        gSound_obj_66F680.field_0 = gWizardly_margulis_6FFF00.sub_58D6C0(&gSound_obj_66F680.field_5440);
        if (gSound_obj_66F680.field_0)
        {
            gSound_obj_66F680.field_1D_b3d_sound = 0;
            gSound_obj_66F680.field_10_samp_count2 = 16;
            gSound_obj_66F680.sub_418C20();
        }
    }
    */
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

void root_sound::sub_40EFA0()
{
    // todo
}

int root_sound::sub_40EFB0(DWORD *a2)
{
    // todo
    return 0;
}

char root_sound::LoadStyle_40EFF0(const char *pStyleName)
{
    // todo
    return 0;
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
