#include "wizardly_margulis.hpp"

wizardly_margulis gWizardly_margulis_6FFF00;

S32 AILCALL AIL_digital_handle_reacquire(HDIGDRIVER drvr)
{
    // stub
    return 0;
}

// match
BYTE wizardly_margulis::sub_58E2A0()
{
    BYTE ret = field_0_hDriver && AIL_digital_handle_reacquire(field_0_hDriver) ? 1 : 0;
    return ret;
}
