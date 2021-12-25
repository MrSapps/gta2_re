#include "sound_obj.hpp"

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
