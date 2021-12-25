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
#include "Bink.hpp"
#include "dma_video.hpp"
#include "keybrd_0x204.hpp"
#include "gbh_graphics.hpp"
#include <direct.h>
#include <stdio.h>
#include "resource.h"

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

BYTE byte_6F4BF4;

int gStartMode_626A0C = 2;

char byte_706C5C;

extern char gTmpBuffer_67C598[256];

extern char bDestroyed_6F5B70;

DWORD gBufferMode_706B34;
char gRenderDllName_7067F0[256];
char gVideoDllName_706654[256];
int gVideodevice_70694C;

// todo: move
void __stdcall sub_5D92D0()
{
    // todo
}

// todo: move
void __stdcall SetSavedGamma_5D98E0()
{
    // todo
}

// todo: move
// match
bool Vid_FindDevice_5D9290()
{
    SDevice* pDevice = Vid_FindDevice(gVidSys_7071D0, gVideodevice_70694C);
    return pDevice && (pDevice->field_4_flags & 1) == 1;
}

// todo move to another file for ordering
// match
int GetHwndDCDeviceCaps_5D9800()
{
    HDC hdc = GetDC(gHwnd_707F04);
    int deviceCaps = GetDeviceCaps(hdc, 12);
    ReleaseDC(gHwnd_707F04, hdc);
    return deviceCaps;
}

// todo move to another file for ordering
// match
void __stdcall GBH_GraphicsInit_5D97C0()
{
    if (GBH_GraphicsLoad_5EB680(gRenderDllName_7067F0, gVidSys_7071D0))
    {
        FatalError_4A38C0(1011, "C:\\Splitting\\Gta2\\Source\\video.cpp", 206, gTmpBuffer_67C598);
    }
}

// todo move to another file for ordering
// match
void sub_5D96C0()
{
    int v1 = 0;
    if (DMA_Video_LoadDll_5EB970(gVideoDllName_706654))
    {
        FatalError_4A38C0(1011, "C:\\Splitting\\Gta2\\Source\\video.cpp", 1647, gVideoDllName_706654);
    }

    gVidSys_7071D0 = Vid_Init_SYS(gHInstance_708220, 0); // flags param ??
    
    Vid_SetDevice(gVidSys_7071D0, gVideodevice_70694C);

    if (!gVidSys_7071D0)
    {
        FatalError_4A38C0(2, "C:\\Splitting\\Gta2\\Source\\video.cpp", 1656);
    }

    if (gBufferMode_706B34 == 1)
    {
        v1 = 64;
    }

    gVidSys_7071D0->field_4_flags |= v1;


    if (GetHwndDCDeviceCaps_5D9800() == 0x10)
    {
        bool cVar1 = Vid_FindDevice_5D9290();
        byte_706C5C = 1;
        if (!cVar1)
        {
            byte_706C5C = 0;
        }
    }
    else
    {
        byte_706C5C = 0;
    }

    sub_5D92D0();
    
    GBH_GraphicsInit_5D97C0();

    SetSavedGamma_5D98E0();

    Vid_ClearScreen(
        gVidSys_7071D0,
        0,
        0,
        0,
        0,
        0,
        gVidSys_7071D0->field_48_rect_right,
        gVidSys_7071D0->field_4C_rect_bottom);

    Vid_FlipBuffers(gVidSys_7071D0);

    Vid_ClearScreen(
        gVidSys_7071D0,
        0,
        0,
        0,
        0,
        0,
        gVidSys_7071D0->field_48_rect_right,
        gVidSys_7071D0->field_4C_rect_bottom);
}

// todo move to another file for ordering
// match
void __stdcall Init_keybrd_jolly_and_sound_4DA440()
{
    keybrd_0x204::create_4D5F50();
    jolly_poitras_0x2BC0::create_56C2C0();

    if (!bSkip_audio_67D6BE)
    {
        gRoot_sound_66B038.sub_40EF80();
        gRoot_sound_66B038.SetCDVol_40F0F0(gRegistry_6FF968.Set_Sound_Setting_586AE0("CDVol", 127));
        gRoot_sound_66B038.SetSfxVol_40F0B0(gRegistry_6FF968.Set_Sound_Setting_586AE0("SFXVol", 127));
        gRoot_sound_66B038.Set3DSound_40F160(gRegistry_6FF968.Get_Sound_Settting_586A70("do_3d_sound"));
        gRegistry_6FF968.Clear_Or_Delete_Sound_Setting_586BF0("do_3d_sound", gRoot_sound_66B038.Get3DSound_40F180());
    }
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
// match
bool IsFullScreen_5D9280()
{
    return gStartMode_626A0C == 1;
}

// todo move to another file for ordering
// match
void __stdcall UpdateWinXY_5D8E70()
{
    if (!IsFullScreen_5D9280())
    {
        RECT winRec;
        GetWindowRect(gHwnd_707F04, &winRec);
        gWindowX_706B60 = winRec.left;
        gWindowY_706B64 = winRec.top;
    }
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

int bStartNetworkGame_7081F0 = 0;

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

// todo: move
void __stdcall sub_5D9230(int startMode)
{
    gStartMode_626A0C = startMode;
    gRegistry_6FF968.Set_Screen_Setting_587170("start_mode", startMode);
}

// todo: move
char sub_5D92C0()
{
    return byte_706C5C;
}

// todo: move
void sub_5D9680()
{
    // todo
}

// todo: move
void __stdcall Input_MouseAcquire_5D7C60()
{
    // todo
}

// todo: move
void __stdcall Input_ReleaseMouse_5D7C70()
{
    // todo
}

// todo: move
void Input_Read_498D10()
{
    // todo
}


// todo: move
void __stdcall sub_5D9250()
{
    // todo
}


LRESULT __stdcall WindowProc_5E4EE0(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
   
    case WM_WINDOWPOSCHANGED:
    {
        if (gLaughing_blackwell_0x1EB54_67DC84)
        {
            Bink::sub_513720();
        }
        break;
    }

    case WM_SETFOCUS: // order ok
        gRoot_sound_66B038.sub_40F140();
        gRoot_sound_66B038.SetCDVol_40F0F0(gRegistry_6FF968.Set_Sound_Setting_586AE0("CDVol", 127));
        gRoot_sound_66B038.SetSfxVol_40F0B0(gRegistry_6FF968.Set_Sound_Setting_586AE0("SFXVol", 127));

        if (bDoFrontEnd_626B68)
        {
            gRoot_sound_66B038.Set3DSound_40F160(0);
        }
        else
        {
            gRoot_sound_66B038.Set3DSound_40F160(gRegistry_6FF968.Get_Sound_Settting_586A70("do_3d_sound"));
            gRegistry_6FF968.Clear_Or_Delete_Sound_Setting_586BF0("do_3d_sound", gRoot_sound_66B038.Get3DSound_40F180());
        }

        if (!bDestroyed_6F5B70)
        {
            //LOBYTE(Msg) = 1;
            BYTE tmp = 1;
            laughing_blackwell_0x1EB54::sub_5E53C0(&tmp);
            if (!bDoFrontEnd_626B68)
            {
                Input_Read_498D10();
            }

            if (gVidSys_7071D0 && !Bink::sub_513770())
            {
                sub_5D92D0();
                sub_5D9680();
                byte_706C5D = 0;
            }

            if (gGame_0x40_67E008)
            {
                gGame_0x40_67E008->sub_4B9720();
            }

            SetSavedGamma_5D98E0();
        }
        break;

    case WM_KILLFOCUS: // order ok
        //LOBYTE(hWnd) = 0;
    {
        BYTE tmp = 0;
        laughing_blackwell_0x1EB54::sub_5E53C0(&tmp);
        Input_ReleaseMouse_5D7C70();
        gRoot_sound_66B038.Set3DSound_40F160(0);
        gRoot_sound_66B038.Release_40F130();

        if (gLaughing_blackwell_0x1EB54_67DC84 && Bink::sub_513760())
        {
            Bink::Close1_513340();
            Bink::Close2_513390();
            gLaughing_blackwell_0x1EB54_67DC84->sub_4B3170(0);
        }

        if (gVidSys_7071D0)
        {
            if (!Vid_FindDevice_5D9290())
            {
                Vid_CloseScreen(gVidSys_7071D0);
                byte_706C5D = 1;
                ShowWindow(gHwnd_707F04, 7);
            }
        }
        break;
    }

    case WM_ACTIVATE: // order ok
        switch (wParam)
        {
        case WA_ACTIVE:
        case WA_CLICKACTIVE:
        {
            BYTE tmp = 1;
            laughing_blackwell_0x1EB54::sub_5E53C0(&tmp);
            Input_MouseAcquire_5D7C60();
        }
            break;

        case WA_INACTIVE:
        {
            BYTE tmp = 0;
            laughing_blackwell_0x1EB54::sub_5E53C0(&tmp);
            Input_ReleaseMouse_5D7C70();
        }
            break;
        }
        break;

    case WM_SIZE:
        switch (wParam)
        {
        case 0u:
           // goto wm_size_case_2;
            byte_70827C = 0;
            gRoot_sound_66B038.sub_40F140();
            break;

        case 1u:
            byte_70827C = 2;
            gRoot_sound_66B038.Release_40F130();
            break;

        case 2u:
       // wm_size_case_2:
            byte_70827C = 0;
            gRoot_sound_66B038.sub_40F140();
            break;
        }
        break;


    case WM_DESTROY: // order ok
        if (bNetworkGame_7081F0)
        {
            gGoofy_thompson_7071E8.sub_520D10();
        }

        ReleaseMutex(gMutex_707078);
        CloseHandle(gMutex_707078);
        gMutex_707078 = 0;

        sub_4DA740();
        GBH_Graphis_DMA_Video_Free_5D9830();
        PostQuitMessage(0);
        break;

    case WM_WINDOWPOSCHANGING:
    {
        WINDOWPOS* pPos = reinterpret_cast<WINDOWPOS*>(lParam);
        if (gLaughing_blackwell_0x1EB54_67DC84 && (pPos->flags & 2) == 0)
        {
            int newX = pPos->x;
            int newY = pPos->y;
            Bink::sub_5136D0(&newX, &newY);
            pPos->x = newX;
            pPos->y = newY;
        }
        break;
    }

    case WM_SYSKEYDOWN:
        switch (wParam)
        {
        case VK_RETURN:
            if (sub_5D92C0())
            {
                UpdateWinXY_5D8E70();
                // The previous key state. The value is 1 if the key is down before the message is sent, or it is 0 if the key is up.
                if ((lParam & 0x20000000) != 0)
                {
                    sub_5D9250();
                    sub_5D92D0();
                    sub_5D9680();
                }
            }
            break;

        case VK_MENU:
        case VK_F10:
        case VK_LMENU:
            return 0;

        default:
            break;
        }
        break;

    case WM_SYSCOMMAND:
        switch (wParam & 0xFFF0)
        {
        case SC_MONITORPOWER:
        case SC_SCREENSAVE:
            return 0;

        case SC_MAXIMIZE:
            UpdateWinXY_5D8E70();
            if (byte_70827C != 2)
            {
                sub_5D9230(1u);
                sub_5D92D0();
                sub_5D9680();
            }
            break;

        case SC_MINIMIZE:
            UpdateWinXY_5D8E70();
            break;

        default:
            break;
        }
        break;

    case WM_SIZING:
    {
        RECT* pDragRect = reinterpret_cast<RECT*>(lParam);
        RECT winRec;
        GetWindowRect(gHwnd_707F04, &winRec);
        pDragRect->left = winRec.left;
        pDragRect->top = winRec.top;
        pDragRect->bottom = winRec.bottom;
        pDragRect->right = winRec.right;
        return 0;
    }

    default:
        break;
    }

    if (gVidSys_7071D0)
    {
        Vid_WindowProc(gVidSys_7071D0, hWnd, Msg, wParam, lParam);
    }

    return DefWindowProcA(hWnd, Msg, wParam, lParam);
}

int __stdcall WinMain_5E53F0(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    //hInstance_ = hInstance;
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
    
   // DWORD v16;
    DWORD dxVer;
    GetDirectXVersion_4C4EC0(&dxVer, &dxVer); // stack hack

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

    WNDCLASSA WndClass;
    WndClass.style = 3; // CS_VREDRAW | CS_HREDRAW
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
    if (!Start_NetworkGame_5E5A30(hInstance))
    {
        ReleaseMutex(gMutex_707078);
        CloseHandle(gMutex_707078);
        return 0;
    }
    sprintf(gTmpBuffer_67C598, "GTA2");
    gHwnd_707F04 = CreateWindowExA(0, "WinMain", gTmpBuffer_67C598, 0xCF0000u, 0, 0, 100, 100, 0, 0, hInstance, 0);
    if (!gHwnd_707F04)
    {
        return 0;
    }

    ShowWindow(gHwnd_707F04, nShowCmd);
    UpdateWindow(gHwnd_707F04);
    RECT clientRec;
    GetClientRect(gHwnd_707F04, &clientRec);
    RECT windowRec;
    GetWindowRect(gHwnd_707F04, &windowRec);

    int v8 = window_width_706630 + windowRec.right + clientRec.left - clientRec.right - windowRec.left;
    int v9 = window_height_706B50 + windowRec.bottom + clientRec.top - clientRec.bottom - windowRec.top;

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

    ShowWindow(gHwnd_707F04, nShowCmd);
    UpdateWindow(gHwnd_707F04);
    j_gbh_init_5D7CA0();
    Init_keybrd_jolly_and_sound_4DA440();

    int state ;
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

    int bQuit = 0;

LABEL_23:
    while (1)
    {
        
        if (!bDoFrontEnd_626B68)
        {
            break;
        }

        laughing_blackwell_0x1EB54::create_4ACFA0();
        gLaughing_blackwell_0x1EB54_67DC84->sub_4B3170(state);

    LABEL_27:
        UpdateWinXY_5D8E70();
        sub_5D9690();

        while (1)
        {
            do
            {
                while (1)
                {
                    // Message processing
                    do
                    {
                        MSG msg;
                        while (PeekMessageA(&msg, 0, 0, 0, 1u))
                        {
                            // label here
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

                    // or switch ?
                    int t = gLaughing_blackwell_0x1EB54_67DC84->sub_4AEDB0();
                    if (t == 1)
                    {
                        bQuit = 1;
                        laughing_blackwell_0x1EB54::destroy_4AD070();
                        DestroyWindow(gHwnd_707F04);
                    }
                    else if (t == 3)
                    {
                        laughing_blackwell_0x1EB54::destroy_4AD070();
                        bDoFrontEnd_626B68 = 0;
                        goto LABEL_23;
                    }
                    else if (t == 4)
                    {
                        laughing_blackwell_0x1EB54::destroy_4AD070();
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
        } // loop end

        if (bNetworkGame_7081F0)
        {
            if (gGame_0x40_67E008->field_2C_main_state == 1)
            {
                DestroyWindow(gHwnd_707F04);
            }
            else
            {
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
                DestroyWindow(gHwnd_707F04);
                break;

            case 2:
                gLucid_hamilton_67E8E0.sub_4C5A10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0->sub_56BB10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0->sub_56C010();
                /* todo
                v15 = -(gLucid_hamilton_67E8E0.sub_4C59A0() != 0);
                v15 = v15 & 0xFB; //lobyte
                state = v15 + 11; //loword
                */
                state = gLucid_hamilton_67E8E0.sub_4C59A0() != 0 ? 6 : 1; // 11? prob 1
                CleanUpInputAndOthers_4DA700();
                bDoFrontEnd_626B68 = 1;
                break;

            case 3:
                gLucid_hamilton_67E8E0.sub_4C5A10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0->sub_56BB10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0->sub_56C010();
                state = gLucid_hamilton_67E8E0.sub_4C59A0() != 0 ? 6 : 2;
                CleanUpInputAndOthers_4DA700();
                bDoFrontEnd_626B68 = 1;
                break;

            case 4:
                gLucid_hamilton_67E8E0.sub_4C5A10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0->sub_56BB10(gGame_0x40_67E008->field_38_orf1);
                gJolly_poitras_0x2BC0_6FEAC0->sub_56C010();
                state = gLucid_hamilton_67E8E0.sub_4C59A0() != 0 ? 6 : 3;
                CleanUpInputAndOthers_4DA700();
                bDoFrontEnd_626B68 = 1;
                break;

            case 5:
                state = 7;
                CleanUpInputAndOthers_4DA700();
                bDoFrontEnd_626B68 = 1;
                break;

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

char __stdcall Start_NetworkGame_5E5A30(HINSTANCE hInstance)
{
    // todo
    return 1;
}

#pragma comment(lib ,"Version.lib")

// match
void __stdcall GetGTA2Version_5E5D60(int *pVerMinor, int *pVerMajor)
{
    DWORD dwHandle;
    DWORD dwSize = GetFileVersionInfoSizeA("GTA2.EXE", &dwHandle);
    BYTE* pAlloc = new BYTE[dwSize];

    VS_FIXEDFILEINFO* pFileInfo;
    unsigned int puLen;
    if (pAlloc
        && GetFileVersionInfoA("GTA2.EXE", 0, dwSize, pAlloc)
        && VerQueryValueA(pAlloc, "\\", reinterpret_cast<LPVOID*>(&pFileInfo), &puLen))
    {
        *pVerMinor = (pFileInfo->dwProductVersionMS >> 16);
        *pVerMajor = pFileInfo->dwProductVersionMS & 0xFFFF;
    }
    delete[] pAlloc;
}
