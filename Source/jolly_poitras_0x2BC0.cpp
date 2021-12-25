#include "jolly_poitras_0x2BC0.hpp"
#include "error.hpp"
#include "file.hpp"
#include <io.h>

jolly_poitras_0x2BC0* gJolly_poitras_0x2BC0_6FEAC0;

wchar_t word_67DC8C[50];

jolly_poitras_0x2BC0::jolly_poitras_0x2BC0()
{
    // todo
    int* pIter1 = &this->field_1884;
    struc_221* pIter2 = this->field_1800;

    int i;
    for (i = 0; i < 3; i++)
    {
        ++pIter1;
        memset(pIter2, 0, sizeof(struc_221));
        *(pIter1 - 4) = 0;
        *(pIter1 - 1) = 0;
        ++pIter2;
    }

    for (i = 0; i < 8; i++)
    {
        if (PlySlotDatExists_56B940(i))
        {
            sub_56B990(i);
        }
        else
        {
            sub_56BA60(i);
        }
    }

    if (HiScoreHscExists_56BCA0())
    {
        sub_56BE50();
    }
    else
    {
        sub_56C1D0();
        sub_56BF20();
    }

    sub_56BD20();
}

// match
void jolly_poitras_0x2BC0::create_56C2C0()
{
    if (!gJolly_poitras_0x2BC0_6FEAC0)
    {
        gJolly_poitras_0x2BC0_6FEAC0 = new jolly_poitras_0x2BC0();
        if (!gJolly_poitras_0x2BC0_6FEAC0)
        {
            FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\plydat.cpp", 1269);
        }
    }
}

// match
void jolly_poitras_0x2BC0::destroy_56C340()
{
    if (gJolly_poitras_0x2BC0_6FEAC0)
    {
        delete gJolly_poitras_0x2BC0_6FEAC0;
        gJolly_poitras_0x2BC0_6FEAC0 = 0;
    }
}

void jolly_poitras_0x2BC0::sub_56BB10(angry_lewin_0x85C *a2)
{
    // todo
}

void jolly_poitras_0x2BC0::sub_56C010()
{
    // todo
}

// match
void jolly_poitras_0x2BC0::GetPlySlotDatName_56B8A0(unsigned __int16 a1, char *a2)
{
    char Buffer[8];
    _itoa(a1, Buffer, 10);
    strcpy(a2, "player\\plyslot");
    strcat(a2, Buffer);
    strcat(a2, ".dat");
}

// match
char jolly_poitras_0x2BC0::PlySlotDatExists_56B940(int a1)
{
    char FileName[356];
    GetPlySlotDatName_56B8A0(a1, FileName);

    _finddata_t findData;
    long hFind = _findfirst(FileName, &findData);
    if (hFind == -1)
    {
        return 0;
    }
    _findclose(hFind);
    return 1;
}

// match
void jolly_poitras_0x2BC0::GetHiScoreHscFileName_56BCF0(char *pName)
{
    strcpy(pName, "player\\hiscores.hsc");
}

// match
char jolly_poitras_0x2BC0::HiScoreHscExists_56BCA0()
{
    char FileName[356];
    GetHiScoreHscFileName_56BCF0(FileName);

    _finddata_t findData;
    long hFind = _findfirst(FileName, &findData);
    if (hFind == -1)
    {
        return 0;
    }
    _findclose(hFind);
    return 1;
}

void jolly_poitras_0x2BC0::sub_56B990(int a2)
{
    char *v2; // ebx
    char *v3; // esi
    int v4; // edi
    char *v5; // esi
    int v6; // edi
    int v7; // [esp+10h] [ebp-16Ch] BYREF
    int v8; // [esp+14h] [ebp-168h] BYREF
    char FileName[356]; // [esp+18h] [ebp-164h] BYREF

    v2 = (char *)this + 0xA4 * (unsigned __int16)a2;

    GetPlySlotDatName_56B8A0(a2, FileName);
    File::Global_Open_4A7060(FileName);

    v3 = v2 + 0x2730;

    v4 = 9;
    do
    {
        v8 = 2;
        File::Global_Read_4A71C0(v3, &v8);
        v3 += 2;
        --v4;
    } while (v4);

    v5 = v2 + 0x26A8;

    v8 = 3;
    do
    {
        v6 = 4;
        do
        {
            v7 = 1;
            File::Global_Read_4A71C0(v5 - 8, &v7);
            v7 = 4;
            File::Global_Read_4A71C0(v5 - 4, &v7);
            v7 = 4;
            File::Global_Read_4A71C0(v5, &v7);
            v5 += 12;
            --v6;
        } while (v6);
        --v8;
    } while (v8);

    File::Global_Close_4A70C0();
}

void jolly_poitras_0x2BC0::sub_56BA60(int a2)
{
    // todo
}

void jolly_poitras_0x2BC0::sub_56BE50()
{
    // todo
}

void jolly_poitras_0x2BC0::sub_56C1D0()
{
    // todo
}

void jolly_poitras_0x2BC0::sub_56BF20()
{
    // todo
}

void jolly_poitras_0x2BC0::sub_56BD20()
{
    // todo
}

agitated_keldysh_0xF0::agitated_keldysh_0xF0()
{
    Init_56B520();
}

agitated_keldysh_0xF0::~agitated_keldysh_0xF0()
{

}

// match
void agitated_keldysh_0xF0::Init_56B520()
{
    for (int i=0; i<10; i++)
    {
        wcscpy(field_0[i].field_0_str, word_67DC8C);
        field_0[i].field_14_score = 0;
    }
}

char agitated_keldysh_0xF0::sub_56B550(const wchar_t *pFindStr, int findScore)
{
    unsigned __int16 startIdx = 10;
    for (__int16 i = 9; i != -1; --i)
    {
        if (findScore > field_0[i].field_14_score)
        {
            startIdx = i;
        }

        if (findScore == field_0[i].field_14_score &&
            wcscmp(pFindStr, field_0[i].field_0_str) == 0)
        {
            return 0;
        }
    }

    if (startIdx != 10)
    {

        if (startIdx < 9u)
        {
            // ??????
            small_string* pIter = &field_0[8];// .field_14_score;
          //  int* pIter = &field_0[9 - 1].field_14_score;

            int remainderCount = 9 - startIdx;
            do
            {
                wcsncpy((pIter+1)->field_0_str, (pIter)->field_0_str, 9u);
                (pIter+1)->field_14_score = (pIter)->field_14_score;

                pIter--;

                --remainderCount;
            } while (remainderCount);
            //newScore = findScore;
        }

        wcsncpy(field_0[startIdx].field_0_str, pFindStr, 9u);
        field_0[startIdx].field_14_score = findScore;

        return 1;
    }
    return 0;
}
