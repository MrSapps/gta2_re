#include "error.hpp"
#include <windows.h>
#include <stdio.h>

char bDestroyed_6F5B70;
HWND gHwnd_707F04;

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

// Match
void FatalError_4A38C0(int Code, const char *pSourceFile, int lineNo, ...)
{
    if (Code == 16)
    {
        const char destroyed = bDestroyed_6F5B70;
        if (!destroyed)
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
        if (!destroyed)
        {
            sub_4DA740();
            GBH_Graphis_DMA_Video_Free_5D9830();

            va_list va;
            va_start(va, lineNo);

            if (Code < 1000)
            {
                FatalError_4A07C0(Code, pSourceFile, lineNo);
            }
            else if (Code < 2000)
            {
                int a33 = va_arg(va, int);
                FatalError_4A07C0(Code, pSourceFile, lineNo, a33);
            }
            else if (Code < 3000)
            {
                int a33 = va_arg(va, int);
                int a44 = va_arg(va, int);
                FatalError_4A07C0(Code, pSourceFile, lineNo, a44, a44);
            }
            else if (Code < 4000)
            {
                int a33 = va_arg(va, int);
                int a44 = va_arg(va, int);
                int a55 = va_arg(va, int);
                FatalError_4A07C0(Code, pSourceFile, lineNo, a55, a55, a55);
            }
            else if (Code < 5000)
            {
                int a33 = va_arg(va, int);
                int a44 = va_arg(va, int);
                int a55 = va_arg(va, int);
                int a66 = va_arg(va, int);
                FatalError_4A07C0(Code, pSourceFile, lineNo, a33, a44, a55, a66);
            }
            else if (Code < 6000)
            {
                int a33 = va_arg(va, int);
                FatalError_4A07C0(Code, pSourceFile, lineNo, a33);
            }
            else if (Code < 7000)
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
            else if (Code < 8000)
            {
                FatalError_4A07C0(Code, pSourceFile, lineNo);
            }
            else if (Code < 9000)
            {
                FatalError_4A07C0(Code, pSourceFile, lineNo);
            }
            else if (Code == 9011)
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
