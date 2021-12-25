#pragma once

class Memory
{
public:
    static void* __stdcall malloc_4FE4D0(size_t Size);

    static void* __stdcall Aligned_malloc_4FE510(int requestedSize, void** pAlignedSize);
};
