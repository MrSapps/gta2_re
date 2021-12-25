#include "winmain.hpp"
#include <windows.h>
#include "error.hpp"
#include "debug.hpp"
#include "input.hpp"
#include "registry.hpp"
#include "Game_0x40.hpp"
#include "jolly_poitras_0x2BC0.hpp"
#include "goofy_thompson.hpp"
#include "lucid_hamilton.hpp"
#include "root_sound.hpp"
#include "laughing_blackwell_0x1EB54.hpp"
#include <direct.h>
#include <stdio.h>

HINSTANCE gHInstance_708220;
HANDLE gMutex_707078;

int gGTA2VersionMajor_708280;
int gGTA2VersionMajor_708284;

extern HWND gHwnd_707F04;

char gWorkingDir_707F64[652];

bool bDoFrontEnd_626B68 = true;

int window_width_706630;
int window_height_706B50;

int gWindowX_706B60;
int gWindowY_706B64;

int bNetworkGame_7081F0;

BYTE byte_70827C;
BYTE byte_706C5D;
BYTE byte_6F5B71;

extern char gTmpBuffer_67C598[256];

// todo move to another file for ordering
void sub_5D96C0()
{
    // todo
}

// todo move to another file for ordering
void __stdcall Init_keybrd_jolly_and_sound_4DA440()
{
    // todo
}

// todo move to another file for ordering
void __stdcall sub_4ACFA0()
{
    // todo
}

// todo move to another file for ordering
void __stdcall sub_4DA4D0()
{
    // todo
}

// todo move to another file for ordering
void __stdcall sub_5D9690()
{
    // todo
}

// todo move to another file for ordering
char sub_4DA850()
{
    // todo
    return 0;
}

// todo move to another file for ordering
void __stdcall GetDirectXVersion_4C4EC0(DWORD *a1, DWORD *a2)
{
    // todo
}

// todo move to another file for ordering
void __stdcall Video_Render_Inits_5D90E0()
{
    // todo
}

// todo move to another file for ordering
void __stdcall UpdateWinXY_5D8E70()
{
    // todo
}

// todo move to another file for ordering
void __stdcall j_gbh_init_5D7CA0()
{
    // todo
}

// todo move to another file for ordering
void __stdcall CleanUpInputAndOthers_4DA700()
{
    // todo
}

char bPlay_replay_67D4F4 = 0;
char bConstant_replay_save_67D5C4 = 0;
int bStartNetworkGame_7081F0 = 0;

// todo move to another file for ordering
void __stdcall sub_4AD070()
{
    // todo
}

// todo move to another file for ordering
int __stdcall SkipWhiteSpace_4DA390(char *pStr)
{
    // todo
    return 0;
}

// todo move to another file for ordering
char *__stdcall sub_4DA3F0(char *pStr)
{
    // todo
    return 0;
}

// todo move to another file for ordering
// MATCH
void __stdcall ParseCommandLine_4DA320(char *pCommandLine)
{
    char* pIter = pCommandLine;
    int len = SkipWhiteSpace_4DA390(pCommandLine);
    _strupr(pCommandLine);
    while (len > 0)
    {
        if (*pIter == '-' || *pIter == '/')
        {
            const char cmd_char = *(++pIter);
            switch (cmd_char)
            {
            case 'R':
                bPlay_replay_67D4F4 = 1;
                break;

            case 'Q':
                bConstant_replay_save_67D5C4 = 1;
                break;

            case 'N':
                bStartNetworkGame_7081F0 = 1;
                break;

            default:
                break;
            }
        }

        pIter = sub_4DA3F0(pIter);
        --len;
    }
}


// match
void Start_GTA2Manager_5E4DE0()
{
    HANDLE v1; // eax
    HWND Window; // eax
    HWND v3; // esi
    LPARAM lParam; // [esp+4h] [ebp-4h]

    ShowWindow(gHwnd_707F04, 7);
    v1 = OpenMutexA(0x1F0001u, 0, "GBH_BOB_MUTEX");
    if (v1)
    {
        if (!CloseHandle(v1))
        {
            FatalError_4A38C0(126, "C:\\Splitting\\Gta2\\Source\\winmain.cpp", 118);
        }

        Window = FindWindowExA(0, 0, 0, "GTA2 Manager");
        v3 = Window;
        if (Window)
        {
            PostMessageA(gHwnd_707F04, 6u, 0, (LPARAM)Window);
            if (!SetForegroundWindow(v3))
            {
                FatalError_4A38C0(126, "C:\\Splitting\\Gta2\\Source\\winmain.cpp", 125);
            }
        }
    }
    else
    {
        PostMessageA(gHwnd_707F04, 6u, 0, lParam);
        if ((unsigned int)ShellExecuteA(0, 0, "GTA2 Manager.EXE", 0, gWorkingDir_707F64, 1) <= 0x20)
        {
            FatalError_4A38C0(126, "C:\\Splitting\\Gta2\\Source\\winmain.cpp", 136);
        }
    }
}

// match
void __stdcall ErrorMsgBox_5E4EC0(LPCSTR lpText)
{
    MessageBoxA(gHwnd_707F04, lpText, "Error!", 0);
}

LRESULT __stdcall WindowProc_5E4EE0(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    // todo
    return 0;
}

void __stdcall laughing_blackwell_0x1EB54_sub_5E53C0(BYTE *a1)
{
    // todo
}

int __stdcall WinMain_5E53F0(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    HINSTANCE hInstance_; // esi
    HWND Window; // eax
    int bQuit; // ebx
    DWORD v8; // esi
    DWORD v9; // edi
    int v10; // eax
    int state; // esi
    int v14; // eax
    int v15; // eax
    DWORD v16; // [esp+10h] [ebp-68h] BYREF
    struct tagRECT clientRec; // [esp+14h] [ebp-64h] BYREF
    struct tagRECT windowRec; // [esp+24h] [ebp-54h] BYREF
    struct tagMSG msg; // [esp+34h] [ebp-44h] BYREF
    WNDCLASSA WndClass; // [esp+50h] [ebp-28h] BYREF
    DWORD dxVer;

    hInstance_ = hInstance;
    gHInstance_708220 = hInstance;
    if (CoInitialize(0) < 0)
    {
        return 0;
    }

    if (OpenMutexA(0x1F0001u, 0, "GBH_COOP_MUTEX"))
    {
        return 0;
    }

    gMutex_707078 = CreateMutexA(0, 0, "GBH_COOP_MUTEX");
    GetGTA2Version_5E5D60(&gGTA2VersionMajor_708280, &gGTA2VersionMajor_708284);
    GetDirectXVersion_4C4EC0(&dxVer, &v16);

    if ((unsigned int)dxVer < 0x601)
    {
        ErrorMsgBox_5E4EC0("ERROR: Incorrect version of DirectX");
        ReleaseMutex(gMutex_707078);
        CloseHandle(gMutex_707078);
        return -1;
    }

    gDebug_67D52C.Init_4ABBD0();
    gLucid_hamilton_67E8E0.sub_4C53D0();
    bDoFrontEnd_626B68 = bSkip_frontend_67D53B == 0;
    WndClass.style = 3;
    WndClass.lpfnWndProc = WindowProc_5E4EE0;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIconA(hInstance, (LPCSTR)0x65);
    WndClass.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
    WndClass.hbrBackground = 0;
    WndClass.lpszMenuName = "WinMain";
    WndClass.lpszClassName = "WinMain";
    RegisterClassA(&WndClass);
    Video_Render_Inits_5D90E0();
    
    _getcwd(gWorkingDir_707F64, 256);

    ParseCommandLine_4DA320(lpCmdLine);
    if (!Start_NetworkGame_5E5A30((int)hInstance))
    {
        ReleaseMutex(gMutex_707078);
        CloseHandle(gMutex_707078);
        return 0;
    }
    sprintf(gTmpBuffer_67C598, "GTA2");
    Window = CreateWindowExA(0, "WinMain", gTmpBuffer_67C598, 0xCF0000u, 0, 0, 100, 100, 0, 0, hInstance, 0);
    gHwnd_707F04 = Window;
    if (!Window)
    {
        return 0;
    }

    bQuit = nShowCmd;
    ShowWindow(Window, nShowCmd);
    UpdateWindow(gHwnd_707F04);
    GetClientRect(gHwnd_707F04, &clientRec);
    GetWindowRect(gHwnd_707F04, &windowRec);

    v8 = window_width_706630 + windowRec.right + clientRec.left - clientRec.right - windowRec.left;
    v9 = window_height_706B50 + windowRec.bottom + clientRec.top - clientRec.bottom - windowRec.top;

    if (bDo_corner_window_67D4EE)
    {
        gWindowX_706B60 = 0;
        gWindowY_706B64 = 0;
    }
    else
    {
        gWindowX_706B60 = (int)(GetSystemMetrics(0) - v8) / 2;
        gWindowY_706B64 = (int)(GetSystemMetrics(1) - v9) / 2;
    }

    if (!SetWindowPos(gHwnd_707F04, 0, gWindowX_706B60, gWindowY_706B64, v8, v9, 0x314u))
    {
        FatalError_4A38C0(7, "C:\\Splitting\\Gta2\\Source\\winmain.cpp", 661);
    }

    Input::DirectInputCreate_4986D0(gHInstance_708220);
    sub_5D96C0(); // todo: cc/arg?
    ShowWindow(gHwnd_707F04, bQuit);
    UpdateWindow(gHwnd_707F04);
    j_gbh_init_5D7CA0();
    Init_keybrd_jolly_and_sound_4DA440();

    if (laughing_blackwell_0x1EB54::intro_bik_exists_4B5FF0())
    {
        state = gRegistry_6FF968.Get_Screen_Setting_5870D0("do_play_movie", 1) != 1 ? 0 : 8;
    }
    else
    {
        state = 0; //  xor     esi, esi
    }

    if (bIsFrench_67D53C)
    {
        state = 14; // mov     esi, 0Eh
    }

    if (bNetworkGame_7081F0)
    {
        bDoFrontEnd_626B68 = 0;
        gRoot_sound_66B038.Set3DSound_40F160(gRegistry_6FF968.Get_Sound_Settting_586A70("do_3d_sound"));
        gRegistry_6FF968.Clear_Or_Delete_Sound_Setting_586BF0("do_3d_sound", gRoot_sound_66B038.Get3DSound_40F180());
    }

LABEL_23:
    while (1)
    {
        bQuit = 0;
        if (!bDoFrontEnd_626B68)
        {
            break;
        }
        sub_4ACFA0();
        gLaughing_blackwell_0x1EB54_67DC84.sub_4B3170(state);
    LABEL_27:
        UpdateWinXY_5D8E70();
        sub_5D9690();
        while (1)
        {
            do
            {
                while (1)
                {
                    do
                    {
                        while (PeekMessageA(&msg, 0, 0, 0, 1u))
                        {
                            if (msg.message == 18) // WM_QUIT
                            {
                                Input::DInputRelease_498710();
                                return msg.wParam;
                            }
                            TranslateMessage(&msg);
                            DispatchMessageA(&msg);
                        }
                    } while ((BYTE)bQuit || byte_70827C == 2 || byte_706C5D);
                    if (!bDoFrontEnd_626B68)
                    {
                        break;
                    }

                    v14 = gLaughing_blackwell_0x1EB54_67DC84.sub_4AEDB0(bQuit);
                    switch (v14)
                    {
                    case 1:
                        bQuit = 1;
                        sub_4AD070();
                        DestroyWindow(gHwnd_707F04);
                        break;
                    case 3:
                        sub_4AD070();
                        bDoFrontEnd_626B68 = 0;
                        goto LABEL_23;
                    case 4:
                        sub_4AD070();
                        bDoFrontEnd_626B68 = 0;
                        byte_6F5B71 = 1;
                        goto LABEL_23;
                    }
                }
                bQuit = sub_4DA850();
            } while (!(BYTE)bQuit);

            if (!bSkip_frontend_67D53B)
            {
                break;
            }

            DestroyWindow(gHwnd_707F04);
        }

        if (bNetworkGame_7081F0)
        {
            if (gGame_0x40_67E008->field_2C_main_state == 1)
            {
            LABEL_50:
                DestroyWindow(gHwnd_707F04);
            }
            else
            {
            LABEL_47:
                state = 7;
                CleanUpInputAndOthers_4DA700();
                bDoFrontEnd_626B68 = 1;
            }
        }
        else
        {
            switch (gGame_0x40_67E008->field_2C_main_state)
            {
            case 1:
                goto LABEL_50;

            case 2:
                gLucid_hamilton_67E8E0.sub_4C5A10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0.sub_56BB10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0.sub_56C010();
                v15 = -(gLucid_hamilton_67E8E0.sub_4C59A0() != 0);
                v15 = v15 & 0xFB; //lobyte
                state = v15 + 11; //loword
                CleanUpInputAndOthers_4DA700();
                bDoFrontEnd_626B68 = 1;
                break;

            case 3:
                gLucid_hamilton_67E8E0.sub_4C5A10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0.sub_56BB10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0.sub_56C010();
                state = gLucid_hamilton_67E8E0.sub_4C59A0() != 0 ? 6 : 2;
                CleanUpInputAndOthers_4DA700();
                bDoFrontEnd_626B68 = 1;
                break;

            case 4:
                gLucid_hamilton_67E8E0.sub_4C5A10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0.sub_56BB10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0.sub_56C010();
                state = gLucid_hamilton_67E8E0.sub_4C59A0() != 0 ? 6 : 3;
                CleanUpInputAndOthers_4DA700();
                bDoFrontEnd_626B68 = 1;
                break;

            case 5:
                goto LABEL_47;

            case 6:
                state = 0;
                CleanUpInputAndOthers_4DA700();
                bDoFrontEnd_626B68 = 1;
                break;

            default:
                continue;
            }
        }
    }
    
    sub_4DA4D0();

    if (!bNetworkGame_7081F0 || gGoofy_thompson_7071E8.sub_5213E0())
    {
        goto LABEL_27;
    }

    CoUninitialize();
    return 0;
}

char __stdcall Start_NetworkGame_5E5A30(int hInstance)
{
    // todo
    return 0;
}

void __stdcall GetGTA2Version_5E5D60(int *pVerMinor, int *pVerMajor)
{
    // todo
}
