#pragma once

#include <stdio.h>
#include <windows.h>

class File
{
public:
    // or static with explicit __stdcall
    static int __stdcall GetFileSize_4A6B10(FILE *Stream);

    static bool __stdcall IsCdRomDrive_4A6BB0(char a1);

    static void *__stdcall ReadFileToBuffer_4A6C80(const char *FileName, size_t *a2);

    static size_t __stdcall Read_4A6D90(void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream);

    static void __stdcall WriteBufferToFile_4A6E80(const char *FileName, void *Buffer, size_t *a3);

    static size_t __stdcall Write_4A6F30(void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream);

    static void __stdcall AppendBufferToFile_4A6F50(const char *FileName, void *Buffer, size_t *a3);

    static void __stdcall CreateFile_4A7000(const char *FileName);

    static void __stdcall Global_Open_4A7060(const char *FileName);

    static void __stdcall Global_Close_4A70C0();

    static void __stdcall Global_Close_UnChecked_4A7110();

    static void __stdcall Global_Seek_4A7140(unsigned int *pOffset);

    static void __stdcall File_Error_4A7190(int Code, int a2, int a3);

    static void __stdcall Global_Read_4A71C0(void *pBuffer, unsigned int *pBufferSize);

    static bool __stdcall Global_Read_4A7210(void *Buffer, unsigned int *pSize);

    static size_t __stdcall GetRemainderSize_4A7250(void *Buffer, DWORD *a2);

    static char __stdcall SkipWhitespace_4A7340(FILE *Stream);


};
