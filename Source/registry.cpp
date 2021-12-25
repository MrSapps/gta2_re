#include "stdafx.h"
#include "registry.hpp"
#include <windows.h>
#include <stdio.h>

char bDestroyed_6F5B70;
Registry gRegistry_6FF968;

HWND gHwnd_707F04;

Registry::Registry() // 0x587290
{

}

void sub_4DA740()
{

}

void __stdcall GBH_Graphis_DMA_Video_Free_5D9830()
{

}

void FatalError_4A07C0(int code, const char *pFileName, int lineNo, ...)
{
	if (code = 2)
	{
		code = 99;
	}
	printf("code = %d\n", code);
}

void FatalError_4A38C0(int Code, const char *pSourceFile, int lineNo, ...)
{
	if ( Code == 16 )
	{
		const char destroyed = bDestroyed_6F5B70;
		if ( !destroyed )
		{
			sub_4DA740();
			GBH_Graphis_DMA_Video_Free_5D9830();
			// 16 was using esi instead of push 10h without the 0x6F5B70 bool
			// being cached in both branches of the if/else
			FatalError_4A07C0(16, pSourceFile, lineNo);
		}
		DestroyWindow(gHwnd_707F04);
		exit(16);
	}
	else
	{
		const char destroyed = bDestroyed_6F5B70;
		if ( !destroyed )
		{
			sub_4DA740();
			GBH_Graphis_DMA_Video_Free_5D9830();
		
			va_list va;
			va_start(va, lineNo);

			if ( Code < 1000 )
			{
				FatalError_4A07C0(Code, pSourceFile, lineNo);
			}
			else if ( Code < 2000 )
			{
				int a33 = va_arg(va, int);
				FatalError_4A07C0(Code, pSourceFile, lineNo, a33);
			}
			else if ( Code < 3000 )
			{
				int a33 = va_arg(va, int);
				int a44 = va_arg(va, int);
				FatalError_4A07C0(Code, pSourceFile, lineNo, a44, a44);
			}
			else if ( Code < 4000 )
			{
				int a33 = va_arg(va, int);
				int a44 = va_arg(va, int);
				int a55 = va_arg(va, int);
				FatalError_4A07C0(Code, pSourceFile, lineNo, a55, a55, a55);
			}
			else if ( Code < 5000 )
			{
				int a33 = va_arg(va, int);
				int a44 = va_arg(va, int);
				int a55 = va_arg(va, int);
				int a66 = va_arg(va, int);
				FatalError_4A07C0(Code, pSourceFile, lineNo, a33, a44, a55, a66);
			}
			else if ( Code < 6000 )
			{
				int a33 = va_arg(va, int);
				FatalError_4A07C0(Code, pSourceFile, lineNo, a33);
			}
			else if ( Code < 7000 )
			{
				int a33 = va_arg(va, int);
				int a44 = va_arg(va, int);
				int a55 = va_arg(va, int);
				int a66 = va_arg(va, int);
				int a77 = va_arg(va, int);
				int a88 = va_arg(va, int);
				int a99 = va_arg(va, int);
				int a10 = va_arg(va, int);
				FatalError_4A07C0(Code, pSourceFile, lineNo, a33, a44, a55, a66, a77, a88, a99, a10);
			}
			else if ( Code < 8000 )
			{
				FatalError_4A07C0(Code, pSourceFile, lineNo);
			}
			else if ( Code < 9000 )
			{
				FatalError_4A07C0(Code, pSourceFile, lineNo);
			}
			else if (Code == 9011 )
			{
				int a33 = va_arg(va, int);
				FatalError_4A07C0(Code, pSourceFile, lineNo, a33);
			}
			else
			{
				FatalError_4A07C0(Code, pSourceFile, lineNo);
			}
		}
		DestroyWindow(gHwnd_707F04);
		exit(Code);
	}
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
	
	DWORD cbData = sizeof(DWORD);
	DWORD data;
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