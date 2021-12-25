#include "sound_obj.hpp"
#include "wizardly_margulis.hpp"

sound_obj gSound_obj_66F680;

void sound_obj::sub_41B700()
{
    unsigned __int8 count = this->field_10_samp_count2;
    for (unsigned int i = 0; i < count; count = this->field_10_samp_count2)
    {
        unsigned int v3 = i + 0x10 * this->field_98;
        ++i;
        *((BYTE *)&this->field_A4[31].field_60 + v3) = count;
    }
    *((BYTE *)&this->field_DBC + this->field_98) = 0;
}

void sound_obj::sub_41B7A0()
{
    // todo
}

// match
void sound_obj::sub_41A2A0()
{
    field_98 = 1;
    sub_41B700();
    field_98 = 0;

    sub_41B700();
    sub_41B7A0();

    field_1450 = 0;

    gWizardly_margulis_6FFF00.sub_58E2A0();
}

// match
void sound_obj::SetCDVol_41A270(unsigned char cdVol)
{
    field_25_cdVol = cdVol;
}
