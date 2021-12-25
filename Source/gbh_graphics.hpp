#pragma once

#include <windows.h>

struct SDisplayMode
{
    DWORD field_0_display_mode_idx;
    DWORD field_4_deviceId;
    DWORD field_8_width;
    DWORD field_C_height;
    DWORD field_10_pitch;
    DWORD field_14_rgb_bit_count;
    DWORD field_18;
    DWORD field_1C;
    DWORD field_20;
    DWORD field_24;
    DWORD field_28;
    DWORD field_2C;
    DWORD field_30;
    DWORD field_34;
    struct SDisplayMode* field_38_pnext;
    DWORD field_3C;
};

struct SDevice
{
    DWORD field_0_id;
    DWORD field_4_flags;
    char* field_8_driver_name;
    char* field_C_driver_desc;
    SDevice* field_10_next_ptr;
    GUID* field_14_pDeviceGuid;
    GUID field_18_guid;
    DWORD field_28_dwVidMemTotal;
    DWORD field_2C_end_buffer; // TODO: Actually a word and SDevice is 0x2E ?
};

struct SVideo
{
    DWORD field_0;
    DWORD field_4_flags;
    DWORD field_8_found_width;
    DWORD field_C_found_height;
    DWORD field_10_found_rgb_bit_count;
    DWORD field_14_display_mode_count_2_q;
    DWORD field_18_num_guids;
    DWORD field_1C_num_display_modes;
    DWORD field_20_num_enums;
    struct SDisplayMode* field_24_head_ptr;
    struct SDisplayMode* field_28_display_mode_array;
    struct SDevice* field_2C_device_info_head_ptr;
    struct SDevice* field_30_device_info_last;
    DWORD field_34_active_device_id;
    DWORD field_38;
    struct SDisplayMode* field_3C_current_enum_ptr;
    DWORD field_40_full_screen;
    DWORD field_44;
    DWORD field_48_rect_right;
    DWORD field_4C_rect_bottom;
    LPVOID field_50_surface_pixels_ptr;
    DWORD field_54_surface_pixels_pitch;
    DWORD field_58;
    DWORD field_5C;
    DWORD field_60_g;
    DWORD field_64_r;
    DWORD field_68_b;
    DWORD field_6C;
    DWORD field_70;
    DWORD field_74;
    DWORD field_78;
    HINSTANCE field_7C_self_dll_handle;
    DWORD field_80_active_mode_q;
    /*
    SPtrVideoFunctions* field_84_from_initDLL;
    DWORD field_88_last_error;
    IDirectDraw7* field_8C_DirectDraw7;
    char buffer[144];
    IDirectDraw4* field_120_IDDraw4;
    GUID field_124; // TODO: Check
    IDirectDrawSurface4* field_134_SurfacePrimary;
    IDirectDrawSurface4* field_138_Surface;
    DDSURFACEDESC2 field_13C_DDSurfaceDesc7;
    LPDIRECTDRAWCLIPPER field_1B8_clipper;
    DWORD field_1BC;
    DWORD field_1C0;
    DWORD field_1C4;
    DDCAPS field_1C8_device_caps;
    DDCAPS field_344_hel_caps;
    HWND field_4C0_hwnd;
    */
};

int __stdcall GBH_GraphicsLoadDll_5EA680(const char* lpLibFileName);

struct STexture;
struct Vert;
struct SLight;
struct SImage;

typedef int(__cdecl *T_gbh_InitDLL)(SVideo*);
typedef int(__cdecl *T_gbh_Init)(int);
typedef int(__cdecl *T_gbh_CloseDLL)();
typedef float(__cdecl *T_gbh_SetWindow)(float left, float top, float right, float bottom);
typedef int*(__cdecl *T_gbh_GetGlobals)(void);
typedef int(__cdecl *T_gbh_DrawTile)(unsigned int flags, STexture* pTexture, Vert* pData, int diffuseColour);
typedef int(__cdecl *T_gbh_DrawTilePart)(unsigned int flags, STexture* pTexture, Vert* pData, int diffuseColour);
typedef int(__cdecl *T_gbh_DrawQuad)(int flags, STexture* pTexture, Vert* pVerts, int baseColour);
typedef int(__cdecl *T_gbh_DrawQuadClipped)(int a1, int a2, int a3, int a4, int a5);
typedef int(__cdecl *T_gbh_DrawFlatRect)(int a1, int a2);
typedef int(__cdecl *T_gbh_DrawTriangle)(int triFlags, STexture* pTexture, Vert* pVerts, int diffuseColour);
typedef int(__cdecl *T_gbh_PrintBitmap)(int a1, int a2);
typedef int(__cdecl *T_gbh_SetColourDepth)(void);
typedef int(__cdecl *T_gbh_Plot)(int a1, int a2, int a3, int a4);
typedef int(__cdecl *T_gbh_ConvertColour)(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3);
typedef int(__stdcall *T_gbh_RegisterTexture)(__int16 width, __int16 height, BYTE* pData, int a4, char a5);
typedef int(__cdecl *T_gbh_SetCamera)(float a1, float a2, float a3, float a4);
typedef int(__cdecl *T_gbh_ResetLights)();
typedef int(__cdecl *T_gbh_AddLight)(SLight* pLight);
typedef int(__cdecl *T_gbh_SetAmbient)(float a1);
typedef int(__cdecl *T_gbh_GetUsedCache)(int a1);
typedef int(__stdcall *T_gbh_FreeTexture)(STexture* pTexture);
typedef int(__cdecl *T_gbh_RegisterPalette)(int palId, BYTE *pData);
typedef int(__cdecl *T_gbh_FreePalette)(int a1);
typedef int(__cdecl *T_gbh_AssignPalette)(STexture* pTexture, int palId);
typedef int(__cdecl *T_gbh_LockTexture)(STexture *);
typedef int(__cdecl *T_gbh_UnlockTexture)(STexture *);
typedef int(__cdecl *T_gbh_BeginScene)();
typedef double(__cdecl *T_gbh_EndScene)();
typedef int(__cdecl *T_gbh_BeginLevel)();
typedef int(__cdecl *T_gbh_EndLevel)();
typedef int(__cdecl *T_MakeScreenTable)(int result, int a2, unsigned int a3);
typedef int(__cdecl *T_ConvertColourBank)(int a1);
typedef int(__cdecl *T_SetShadeTableA)(int a1, int a2, int a3, int a4, int a5);
typedef int(__stdcall *T_gbh_InitImageTable)(int tableSize);
typedef int(__cdecl *T_gbh_FreeImageTable)();
typedef int(__stdcall *T_gbh_LoadImage)(SImage* pImage);
typedef int(__stdcall *T_gbh_BlitImage)(int imageIndex, int srcLeft, int srcTop, int srcRight, int srcBottom, int dstX, int dstY);
typedef int(__cdecl *T_gbh_BlitBuffer)(int a1, int a2, int a3, int a4, int a5, int a6);

extern T_gbh_InitDLL gbh_InitDLL;
extern T_gbh_Init gbh_Init;
extern T_gbh_CloseDLL gbh_CloseDLL;
extern T_gbh_SetWindow gbh_SetWindow;
extern T_gbh_GetGlobals gbh_GetGlobals;
extern T_gbh_DrawTile gbh_DrawTile;
extern T_gbh_DrawTilePart gbh_DrawTilePart;
extern T_gbh_DrawQuad gbh_DrawQuad;
extern T_gbh_DrawQuadClipped gbh_DrawQuadClipped;
extern T_gbh_DrawFlatRect gbh_DrawFlatRect;
extern T_gbh_DrawTriangle gbh_DrawTriangle;
extern T_gbh_PrintBitmap gbh_PrintBitmap;
extern T_gbh_SetColourDepth gbh_SetColourDepth;
extern T_gbh_Plot gbh_Plot;
extern T_gbh_ConvertColour gbh_ConvertColour;
extern T_gbh_RegisterTexture gbh_RegisterTexture;
extern T_gbh_SetCamera gbh_SetCamera;
extern T_gbh_ResetLights gbh_ResetLights;
extern T_gbh_AddLight gbh_AddLight;
extern T_gbh_SetAmbient gbh_SetAmbient;
extern T_gbh_GetUsedCache gbh_GetUsedCache;
extern T_gbh_FreeTexture gbh_FreeTexture;
extern T_gbh_RegisterPalette gbh_RegisterPalette;
extern T_gbh_FreePalette gbh_FreePalette;
extern T_gbh_AssignPalette gbh_AssignPalette;
extern T_gbh_LockTexture gbh_LockTexture;
extern T_gbh_UnlockTexture gbh_UnlockTexture;
extern T_gbh_BeginScene gbh_BeginScene;
extern T_gbh_EndScene gbh_EndScene;
extern T_gbh_BeginLevel gbh_BeginLevel;
extern T_gbh_EndLevel gbh_EndLevel;
extern T_MakeScreenTable MakeScreenTable;
extern T_ConvertColourBank ConvertColourBank;
extern T_SetShadeTableA SetShadeTableA;
extern T_gbh_InitImageTable gbh_InitImageTable;
extern T_gbh_FreeImageTable gbh_FreeImageTable;
extern T_gbh_LoadImage gbh_LoadImage;
extern T_gbh_BlitImage gbh_BlitImage;
extern T_gbh_BlitBuffer gbh_BlitBuffer;
