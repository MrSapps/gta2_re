#include "stdafx.h"
#include "registry.hpp"
#include <windows.h>

Registry gRegistry_6FF968;

void FatalError_4A38C0(int Code, const char *pSourceFile, int lineNo, ...)
{

}

bool Registry::Open_Sound_Root_586A00(PHKEY phkResult)
{
	if ( ::RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\DMA Design Ltd\\GTA2\\Sound", 0, KEY_ALL_ACCESS, phkResult) != ERROR_SUCCESS )
	{
		DWORD dwDisposition;
		
		if ( ::RegCreateKeyExA(
			HKEY_LOCAL_MACHINE,
			"SOFTWARE\\DMA Design Ltd\\GTA2\\Sound",
			0,
			"", //byte_67DC88,
			0,
			KEY_ALL_ACCESS,
			NULL,
			phkResult,
			&dwDisposition) != ERROR_SUCCESS )
		{
			FatalError_4A38C0(43, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 58);
		}
		return false;
	}
	return true;
}

bool Registry::Get_Sound_Settting_586A70(const char *lpValueName)
{
	HKEY hKey;
	DWORD cbData;
	unsigned char data[4];
	
	bool settingReadOK = false;
	if ( Open_Sound_Root_586A00(&hKey) )
	{
		cbData = 4;
		if ( ::RegQueryValueExA(hKey, lpValueName, 0, 0, data, &cbData) == ERROR_SUCCESS )
		{
			settingReadOK = true;
		}
	}
	
	if ( ::RegCloseKey(hKey) != ERROR_SUCCESS )
	{
		FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 109);
	}
	return settingReadOK;
}

int Registry::Set_Sound_Setting_586AE0(const char *lpValueName, int value)
{
	HKEY hKey;
	Open_Sound_Root_586A00(&hKey);
	

	DWORD data;
	DWORD cbData = sizeof(data);
	
	if ( ::RegQueryValueExA(hKey, lpValueName, 0, 0, reinterpret_cast<BYTE*>(&data), &cbData) != ERROR_SUCCESS )
	{
		if ( ::RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, reinterpret_cast<const BYTE *>(&value), sizeof(DWORD)) != ERROR_SUCCESS )
		{
			FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 138);
		}
		data = value;
	}

	if ( ::RegCloseKey(hKey) != ERROR_SUCCESS )
	{
		FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 146);
	}

	return data;
}