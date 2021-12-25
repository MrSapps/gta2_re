#include "laughing_blackwell_0x1EB54.hpp"
#include <io.h>

laughing_blackwell_0x1EB54* gLaughing_blackwell_0x1EB54_67DC84;

char laughing_blackwell_0x1EB54::sub_4B3170(unsigned __int16 arg0)
{
    // todo
    return 0;
}

int laughing_blackwell_0x1EB54::sub_4AEDB0()
{
    // todo
    return 0;
}

const char* laughing_blackwell_0x1EB54::intro_bik_4B5E50()
{
    // todo
    return "meh.dat";
}

// match
bool laughing_blackwell_0x1EB54::intro_bik_exists_4B5FF0()
{
    // ecx wasn't first due to global being an object instead of a pointer
    _finddata_t findData;

    // note: put call in argument rather than local to change inst ordering
    const  long hFind = _findfirst(gLaughing_blackwell_0x1EB54_67DC84->intro_bik_4B5E50(), &findData);

    if (hFind == -1)
    {
        return 0;
    }

    _findclose(hFind);
    return 1;

}
