#pragma once

class Registry
{
public:
	Registry(); // TODO: Needs moving to later

    // todo: fix ordering

	bool Open_Sound_Root_586A00(PHKEY phkResult);

	bool Get_Sound_Settting_586A70(const char *lpValueName);

	int Set_Sound_Setting_586AE0(const char *lpValueName, int value);

    int Get_Screen_Setting_5870D0(const char *lpValueName, int a2);

    void Clear_Or_Delete_Sound_Setting_586BF0(LPCSTR lpValueName, char bClear);
};

extern Registry gRegistry_6FF968;
