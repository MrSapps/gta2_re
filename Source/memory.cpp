#include "memory.hpp"
#include "error.hpp"
#include <stdlib.h>

// match
void* __stdcall Memory::Aligned_malloc_4FE510(int requestedSize, void** pUnAlignedPtr)
{
    // Allocate with extra space for alignment
    void* pAlloc = malloc(requestedSize + 0x10000);

    // Return the raw unaligned allocation (since we can't free the aligned one)
    *pUnAlignedPtr = pAlloc;

    // Fail if no alloc
    if (!pAlloc)
    {
        FatalError_4A38C0(1029, "C:\\Splitting\\Gta2\\Source\\Memory.cpp", 76, requestedSize + 0x10000);
    }

    // Return aligned pointer
    return (void *)(((unsigned int)*pUnAlignedPtr + 0xFFFF) & 0xFFFF0000);
}
