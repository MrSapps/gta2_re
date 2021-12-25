#pragma once

#include <windows.h>

class Registry
{
public:

    // todo: fix ordering

    bool Open_Sound_Root_586A00(PHKEY phkResult);

    bool Get_Sound_Settting_586A70(const char *lpValueName);

    int Set_Sound_Setting_586AE0(const char *lpValueName, int value);

    void Set_Sound_Setting_586B80(const char* lpValueName, int Data);

    void Clear_Or_Delete_Sound_Setting_586BF0(const char* lpValueName, char bClear);

    char Open_Debug_Root_586C60(PHKEY phkResult);

    char Open_Options_Root_586CD0(PHKEY phkResult);

    char Open_Control_Root_586D40(PHKEY phkResult);

    char Open_Screen_Root_586DB0(PHKEY phkResult);

    bool Get_Debug_Setting_586E20(const char *lpValueName);

    void Get_Debug_Setting_586E90(const char* lpValueName, LPBYTE lpData, int a3);

    void Get_Option_586F00(const char* lpValueName, BYTE *pBuffer, int bufferSize);

    int Set_Option_586F70(const char *lpValueName, int a3);

    int Set_Control_Setting_587010(int a1, int a2);

    int Get_Screen_Setting_5870D0(const char *lpValueName, int a2);

    Registry();

    char sub_5872A0(HKEY hKey, const char *a2, BYTE *lpData, DWORD Data);

    bool sub_587340(HKEY hKey, const char *keyPath, int value, LPBYTE lpData);

    int Get_Int_5873E0(HKEY hKey, const char *subKey);

    char CreateNetworkRoot_587420(PHKEY phkResult);

    DWORD Get_Int_Setting_5874E0(HKEY hKey, const char* lpValueName);

    int Set_Network_Setting_587690(const char *lpValueName, int a2);

    void Set_Network_Setting_587730(const char* lpValueName, BYTE Data);

    char Open_Player_Root_5877A0(PHKEY phkResult);

    int Create_Player_Setting_587810(const char* lpValueName);

    void Set_Player_Setting_5878C0(const char* lpValueName, BYTE Data);

    void Set_Screen_Setting_587170(const char* lpValueName, int Data);

    void Set_Screen_Setting_5871E0(const char *lpValueName, BYTE *lpData, unsigned __int16 maxLen);
};

extern Registry gRegistry_6FF968;
