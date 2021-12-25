#pragma once

#include "types.hpp"
#include <windows.h>

class Registry
{
public:

    // todo: fix ordering

    EXPORT bool Open_Sound_Root_586A00(PHKEY phkResult);

    EXPORT bool Get_Sound_Settting_586A70(const char *lpValueName);

    EXPORT int Set_Sound_Setting_586AE0(const char *lpValueName, int value);

    EXPORT void Set_Sound_Setting_586B80(const char* lpValueName, int Data);

    EXPORT void Clear_Or_Delete_Sound_Setting_586BF0(const char* lpValueName, char bClear);

    EXPORT char Open_Debug_Root_586C60(PHKEY phkResult);

    EXPORT char Open_Options_Root_586CD0(PHKEY phkResult);

    EXPORT char Open_Control_Root_586D40(PHKEY phkResult);

    EXPORT char Open_Screen_Root_586DB0(PHKEY phkResult);

    EXPORT bool Get_Debug_Setting_586E20(const char *lpValueName);

    EXPORT void Get_Debug_Setting_586E90(const char* lpValueName, LPBYTE lpData, int a3);

    EXPORT void Get_Option_586F00(const char* lpValueName, BYTE *pBuffer, int bufferSize);

    EXPORT int Set_Option_586F70(const char *lpValueName, int a3);

    EXPORT int Set_Control_Setting_587010(int a1, int a2);

    EXPORT int Get_Screen_Setting_5870D0(const char *lpValueName, int a2);

    EXPORT Registry();

    EXPORT char sub_5872A0(HKEY hKey, const char *a2, BYTE *lpData, DWORD Data);

    EXPORT bool sub_587340(HKEY hKey, const char *keyPath, int value, LPBYTE lpData);

    EXPORT int Get_Int_5873E0(HKEY hKey, const char *subKey);

    EXPORT char CreateNetworkRoot_587420(PHKEY phkResult);

    EXPORT DWORD Get_Int_Setting_5874E0(HKEY hKey, const char* lpValueName);

    EXPORT int Set_Network_Setting_587690(const char *lpValueName, int a2);

    EXPORT void Set_Network_Setting_587730(const char* lpValueName, BYTE Data);

    EXPORT char Open_Player_Root_5877A0(PHKEY phkResult);

    EXPORT int Create_Player_Setting_587810(const char* lpValueName);

    EXPORT void Set_Player_Setting_5878C0(const char* lpValueName, BYTE Data);

    EXPORT void Set_Screen_Setting_587170(const char* lpValueName, int Data);

    EXPORT void Set_Screen_Setting_5871E0(const char *lpValueName, BYTE *lpData, unsigned __int16 maxLen);
};

extern Registry gRegistry_6FF968;
