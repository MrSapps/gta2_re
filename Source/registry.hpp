#pragma once

class Registry
{
public:
	bool Open_Sound_Root_586A00(PHKEY phkResult);

	bool Get_Sound_Settting_586A70(const char *lpValueName);

	int Set_Sound_Setting_586AE0(const char *lpValueName, int value);

};

extern Registry gRegistry_6FF968;
