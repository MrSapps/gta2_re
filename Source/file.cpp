#include "file.hpp"
#include "error.hpp"
#include <stdlib.h>
#include <stdio.h>

int gbGlobalFileOpen_67D160;
FILE* ghFile_67CFEC;
extern char gTmpBuffer_67C598[256];

// TODO: Move
void __stdcall Error_SetName_4A0770(const char *a1)
{
    // TODO
    return ;
}

// match
int __stdcall File::sub_4A6B10(FILE *Stream)
{
    int v1; // ebx
    int v2; // edi

    v1 = ftell(Stream);
    if (v1 == -1)
    {
        FatalError_4A38C0(13, "C:\\Splitting\\Gta2\\Source\\File.cpp", 56);
    }

    if (fseek(Stream, 0, 2))
    {
        FatalError_4A38C0(14, "C:\\Splitting\\Gta2\\Source\\File.cpp", 58);
    }

    v2 = ftell(Stream);
    if (v2 == -1)
    {
        FatalError_4A38C0(13, "C:\\Splitting\\Gta2\\Source\\File.cpp", 60);
    }

    if (fseek(Stream, v1, 0))
    {
        FatalError_4A38C0(14, "C:\\Splitting\\Gta2\\Source\\File.cpp", 62);
    }

    return v2;
}

// match
bool __stdcall File::sub_4A6BB0(char a1)
{
    sprintf(gTmpBuffer_67C598, "%c:", a1);
    // Silly return structure but needed to match (and somehow produces less code)
    if (GetDriveTypeA(gTmpBuffer_67C598) == DRIVE_CDROM)
    {
        return true;
    }
    return false;
}

// stack wrong
void *__stdcall File::sub_4A6C80(const char *FileName, size_t *a2)
{
    FILE *v2; // eax
    FILE *v3; // esi
    void *v4; // esi
    FILE *v5; // eax
    FILE *v6; // edi

    Error_SetName_4A0770(FileName);
    v2 = fopen(FileName, "rb");
    v3 = v2;
    if (!v2)
        FatalError_4A38C0(16, "C:\\Splitting\\Gta2\\Source\\File.cpp", 141);
    *a2 = File::sub_4A6B10(v2);
    if (fclose(v3))
        FatalError_4A38C0(17, "C:\\Splitting\\Gta2\\Source\\File.cpp", 145);
    v4 = malloc(*a2);

    v5 = fopen(FileName, "rb");
    // stack is wrong here
    v6 = v5;
    

    if (!v5)
    {
        free(v4);
        FatalError_4A38C0(16, "C:\\Splitting\\Gta2\\Source\\File.cpp", 151);
    }
    if (File_Read_4A6D90(v4, *a2, 1u, v5) != 1)
    {
        free(v4);
        fclose(v6);
        FatalError_4A38C0(15, "C:\\Splitting\\Gta2\\Source\\File.cpp", 158);
    }
    if (fclose(v6))
    {
        free(v4);
        FatalError_4A38C0(17, "C:\\Splitting\\Gta2\\Source\\File.cpp", 164);
    }
    return v4;
}

// match
size_t __stdcall File::File_Read_4A6D90(void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
    size_t ret = fread(Buffer, ElementSize, ElementCount, Stream);
    return ret;
}

// match
void __stdcall File::sub_4A6E80(const char *FileName, void *Buffer, size_t *a3)
{
    Error_SetName_4A0770(FileName);
    if (!*a3)
    {
        FatalError_4A38C0(19, "C:\\Splitting\\Gta2\\Source\\File.cpp", 228);
    }

    FILE *hFile = fopen(FileName, "wb");
    if (!hFile)
    {
        FatalError_4A38C0(16, "C:\\Splitting\\Gta2\\Source\\File.cpp", 231);
    }

    if (sub_4A6F30(Buffer, *a3, 1u, hFile) != 1)
    {
        fclose(hFile);
        FatalError_4A38C0(20, "C:\\Splitting\\Gta2\\Source\\File.cpp", 237);
    }

    if (fclose(hFile))
    {
        FatalError_4A38C0(17, "C:\\Splitting\\Gta2\\Source\\File.cpp", 241);
    }
}

// match
size_t __stdcall File::sub_4A6F30(void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
    return fwrite(Buffer, ElementSize, ElementCount, Stream);
}

// match
void __stdcall File::sub_4A6F50(const char *FileName, void *Buffer, size_t *a3)
{
    Error_SetName_4A0770(FileName);
    if (!*a3)
    {
        FatalError_4A38C0(19, "C:\\Splitting\\Gta2\\Source\\File.cpp", 261);
    }

    FILE* v3 = fopen(FileName, "ab"); // TODO: check
    if (!v3)
    {
        FatalError_4A38C0(16, "C:\\Splitting\\Gta2\\Source\\File.cpp", 264);
    }

    if (sub_4A6F30(Buffer, *a3, 1u, v3) != 1)
    {
        fclose(v3);
        FatalError_4A38C0(20, "C:\\Splitting\\Gta2\\Source\\File.cpp", 270);
    }

    if (fclose(v3))
    {
        FatalError_4A38C0(17, "C:\\Splitting\\Gta2\\Source\\File.cpp", 274);
    }
}

// match
void __stdcall File::CreateBinaryFile_4A7000(const char *FileName)
{
    Error_SetName_4A0770(FileName);

    FILE* hFile = fopen(FileName, "wb");
    if (!hFile)
    {
        FatalError_4A38C0(16, "C:\\Splitting\\Gta2\\Source\\File.cpp", 296);
    }

    if (fclose(hFile))
    {
        FatalError_4A38C0(17, "C:\\Splitting\\Gta2\\Source\\File.cpp", 300);
    }

}

// match
void __stdcall File::File_Global_Open_4A7060(const char *FileName)
{
    if (gbGlobalFileOpen_67D160)
    {
        File_Global_Close_4A70C0();
    }

    Error_SetName_4A0770(FileName);

    ghFile_67CFEC = fopen(FileName, "rb");
    if (!ghFile_67CFEC)
    {
        FatalError_4A38C0(16, "C:\\Splitting\\Gta2\\Source\\File.cpp", 323);
    }

    gbGlobalFileOpen_67D160 = 1;
}

// match
void __stdcall File::File_Global_Close_4A70C0()
{
    if (gbGlobalFileOpen_67D160)
    {
        int v0 = fclose(ghFile_67CFEC);
        gbGlobalFileOpen_67D160 = 0;
        if (v0)
        {
            FatalError_4A38C0(17, "C:\\Splitting\\Gta2\\Source\\File.cpp", 345);
        }
    }
}

// match
void __stdcall File::File_Global_Close_UnChecked_4A7110()
{
    if (gbGlobalFileOpen_67D160)
    {
        fclose(ghFile_67CFEC);
        gbGlobalFileOpen_67D160 = 0;
    }
}

// match
void __stdcall File::File_Global_Seek_4A7140(int *pOffset)
{
    if (!gbGlobalFileOpen_67D160)
    {
        FatalError_4A38C0(21, "C:\\Splitting\\Gta2\\Source\\File.cpp", 416);
    }

    if (fseek(ghFile_67CFEC, *pOffset, 1))
    {
        File_Error_4A7190(14, 0, 0);
    }
}

// match
void __stdcall File::File_Error_4A7190(int Code, int a2, int a3)
{
    File_Global_Close_UnChecked_4A7110();
    FatalError_4A38C0(Code, "C:\\Splitting\\Gta2\\Source\\File.cpp", 398, a2, a3);
}

// match
void __stdcall File::File_Global_Read_4A71C0(void *pBuffer, DWORD *pBufferSize)
{
    if (!gbGlobalFileOpen_67D160)
    {
        FatalError_4A38C0(21, "C:\\Splitting\\Gta2\\Source\\File.cpp", 438);
    }

    if (File_Read_4A6D90(pBuffer, *pBufferSize, 1u, ghFile_67CFEC) != 1)
    {
        File_Error_4A7190(15, 0, 0);
    }
}

// match
bool __stdcall File::Global_Read_4A7210(void *Buffer, DWORD *pSize)
{
    if (!gbGlobalFileOpen_67D160)
    {
        FatalError_4A38C0(21, "C:\\Splitting\\Gta2\\Source\\File.cpp", 460);
    }
    return (File_Read_4A6D90(Buffer, *pSize, 1u, ghFile_67CFEC) == 1) ? true : false;

}

// match
size_t __stdcall File::File_4A7250(void *Buffer, DWORD *a2)
{
    int v2; // edi
    int v3; // esi
    size_t v4; // esi

    if (!gbGlobalFileOpen_67D160)
    {
        FatalError_4A38C0(21, "C:\\Splitting\\Gta2\\Source\\File.cpp", 487);
    }

    v2 = ftell(ghFile_67CFEC);
    if (v2 == -1)
    {
        File_Error_4A7190(13, 0, 0);
    }

    if (fseek(ghFile_67CFEC, 0, 2))
    {
        File_Error_4A7190(14, 0, 0);
    }

    v3 = ftell(ghFile_67CFEC);
    if (v3 == -1)
    {
        File_Error_4A7190(13, 0, 0);
    }

    if (fseek(ghFile_67CFEC, v2, 0))
    {
        File_Error_4A7190(14, 0, 0);
    }

    v4 = v3 - v2;
    if (v4 > *a2)
    {
        File_Error_4A7190(1022, v4 - *a2, 0);
    }

    if (File_Read_4A6D90(Buffer, v4, 1u, ghFile_67CFEC) != 1)
    {
        File_Error_4A7190(15, 0, 0);
    }

    return v4;
}

// match
char __stdcall File::sub_4A7340(FILE *Stream)
{
    char next_char = 0;

    while (1)
    {
        next_char = fgetc(Stream);
        // note: feof = Stream->_flag & 0x10
        if (feof(Stream) || next_char == 10)
        {
            next_char = 0;
            break;
        }

        if (next_char == 32 || next_char == 13 || next_char == 9)
        {
            next_char = 0;
        }
        else
        {
            break;
        }
    }
    return next_char;
}
