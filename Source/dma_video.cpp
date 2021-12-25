#include "dma_video.hpp"

SVideo *gVidSys_7071D0;

T_Vid_GetVersion Vid_GetVersion;
T_Vid_Init_SYS Vid_Init_SYS;
T_Vid_CheckMode Vid_CheckMode;
T_Vid_FindMode Vid_FindMode;
T_Vid_FindFirstMode Vid_FindFirstMode;
T_Vid_FindNextMode Vid_FindNextMode;
T_Vid_FindDevice Vid_FindDevice;
T_Vid_SetDevice Vid_SetDevice;
T_Vid_CloseScreen Vid_CloseScreen;
T_Vid_SetMode Vid_SetMode;
T_Vid_FlipBuffers Vid_FlipBuffers;
T_Vid_ReleaseSurface Vid_ReleaseSurface;
T_Vid_GrabSurface Vid_GrabSurface;
T_Vid_ShutDown_SYS Vid_ShutDown_SYS;
T_Vid_EnableWrites Vid_EnableWrites;
T_Vid_DisableWrites Vid_DisableWrites;
T_Vid_GetSurface Vid_GetSurface;
T_Vid_FreeSurface Vid_FreeSurface;
T_Vid_ClearScreen Vid_ClearScreen;
T_Vid_WindowProc Vid_WindowProc;
T_Vid_InitDLL Vid_InitDLL;
T_Vid_SetGamma Vid_SetGamma;

HMODULE hDmaVideoDll_7085E8;

// match
void __stdcall DMA_Video_Stub_5EB810()
{
    MessageBoxA(0, "Error: A DMA Video Function was called without the DLL being loaded", "DMA Video Error", MB_OK);
}

// match
void __stdcall DMA_Video_Unload_5EB8C0(SVideo *pVidSys)
{
    if (Vid_ShutDown_SYS != (T_Vid_ShutDown_SYS)DMA_Video_Stub_5EB810)
    {
        Vid_ShutDown_SYS(pVidSys);
    }

    FreeLibrary(hDmaVideoDll_7085E8);

    Vid_GetVersion = (T_Vid_GetVersion)DMA_Video_Stub_5EB810;
    Vid_Init_SYS = (T_Vid_Init_SYS)DMA_Video_Stub_5EB810;
    Vid_CheckMode = (T_Vid_CheckMode)DMA_Video_Stub_5EB810;
    Vid_FindDevice = (T_Vid_FindDevice)DMA_Video_Stub_5EB810;
    Vid_SetDevice = (T_Vid_SetDevice)DMA_Video_Stub_5EB810;
    Vid_FindMode = (T_Vid_FindMode)DMA_Video_Stub_5EB810;
    Vid_FindFirstMode = (T_Vid_FindFirstMode)DMA_Video_Stub_5EB810;
    Vid_FindNextMode = (T_Vid_FindNextMode)DMA_Video_Stub_5EB810;
    Vid_CloseScreen = (T_Vid_CloseScreen)DMA_Video_Stub_5EB810;
    Vid_SetMode = (T_Vid_SetMode)DMA_Video_Stub_5EB810;
    Vid_FlipBuffers = (T_Vid_FlipBuffers)DMA_Video_Stub_5EB810;
    Vid_ReleaseSurface = (T_Vid_ReleaseSurface)DMA_Video_Stub_5EB810;
    Vid_GrabSurface = (T_Vid_GrabSurface)DMA_Video_Stub_5EB810;
    Vid_ShutDown_SYS = (T_Vid_ShutDown_SYS)DMA_Video_Stub_5EB810;
    Vid_EnableWrites = (T_Vid_EnableWrites)DMA_Video_Stub_5EB810;
    Vid_DisableWrites = (T_Vid_DisableWrites)DMA_Video_Stub_5EB810;
    Vid_GetSurface = (T_Vid_GetSurface)DMA_Video_Stub_5EB810;
    Vid_FreeSurface = (T_Vid_FreeSurface)DMA_Video_Stub_5EB810;
    Vid_ClearScreen = (T_Vid_ClearScreen)DMA_Video_Stub_5EB810;
    Vid_SetGamma = (T_Vid_SetGamma)DMA_Video_Stub_5EB810;
    Vid_WindowProc = (T_Vid_WindowProc)DMA_Video_Stub_5EB810;
    Vid_InitDLL = (T_Vid_InitDLL)DMA_Video_Stub_5EB810;
}
