#include "input.hpp"

#define DIRECTINPUT_VERSION 0x0500

#include <Dinput.h>
#include "error.hpp"

//#pragma comment(lib, "DInput.lib")

LPDIRECTINPUTA gpDInput_67B804;

void __stdcall Input::DirectInputCreate_4986D0(HINSTANCE hInstance)
{
    // todo
    /*
    if (DirectInputCreateA(hInstance, 1792, &gpDInput_67B804, 0) < 0)
    {
        FatalError_4A38C0(8, "C:\\Splitting\\Gta2\\Source\\diutil.cpp", 129);
    }
    */
}

void __stdcall Input::DInputRelease_498710()
{
    if (gpDInput_67B804)
    {
        gpDInput_67B804->Release();
        gpDInput_67B804 = 0;
    }
}
