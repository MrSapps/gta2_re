#include "sharp_pare_0x15D8.hpp"
#include "gbh_graphics.hpp"
#include "gtx_0x106C.hpp"

sharp_pare_0x15D8 *gSharp_pare_0x15D8_705064;

sharp_pare_0x15D8::sharp_pare_0x15D8()
{
    int v2; // ecx
    optimistic_moser *v3; // eax

    v2 = 96;
    v3 = this->field_10C4;
    do
    {
        v3->field_0_pPixelData = 0;
        v3->field_4_pTexture = 0;
        v3->field_8 = 0;
        v3->field_A = 0;
        ++v3;
        --v2;
    } while (v2);

    this->field_1548_unk.field_0_pAlloc = 0;
    this->field_1548_unk.field_4_item_alloc_count = 0;
    this->field_1548_unk.field_6_count = 0;
    this->field_1548_unk.field_8_pal_type = 0;
    this->field_1548_unk.field_C_pal_type = 0;
    this->field_1548_unk.field_10_bDoFree = 0;
    this->field_155C_unk.field_0_pAlloc = 0;
    this->field_155C_unk.field_4_item_alloc_count = 0;
    this->field_155C_unk.field_6_count = 0;
    this->field_155C_unk.field_8_pal_type = 0;
    this->field_155C_unk.field_C_pal_type = 0;
    this->field_155C_unk.field_10_bDoFree = 0;
    this->field_1570_unk.field_0_pAlloc = 0;
    this->field_1570_unk.field_4_item_alloc_count = 0;
    this->field_1570_unk.field_6_count = 0;
    this->field_1570_unk.field_8_pal_type = 0;
    this->field_1570_unk.field_C_pal_type = 0;
    this->field_1570_unk.field_10_bDoFree = 0;
    this->field_1584_unk.field_0_pAlloc = 0;
    this->field_1584_unk.field_4_item_alloc_count = 0;
    this->field_1584_unk.field_6_count = 0;
    this->field_1584_unk.field_8_pal_type = 0;
    this->field_1584_unk.field_C_pal_type = 0;
    this->field_1584_unk.field_10_bDoFree = 0;
    this->field_1598_unk.field_0_pAlloc = 0;
    this->field_1598_unk.field_4_item_alloc_count = 0;
    this->field_1598_unk.field_6_count = 0;
    this->field_1598_unk.field_8_pal_type = 0;
    this->field_1598_unk.field_C_pal_type = 0;
    this->field_1598_unk.field_10_bDoFree = 0;
    this->field_15AC_unk.field_0_pAlloc = 0;
    this->field_15AC_unk.field_4_item_alloc_count = 0;
    this->field_15AC_unk.field_6_count = 0;
    this->field_15AC_unk.field_8_pal_type = 0;
    this->field_15AC_unk.field_C_pal_type = 0;
    this->field_15AC_unk.field_10_bDoFree = 0;
    this->field_15C0_unk.field_0_pAlloc = 0;
    this->field_15C0_unk.field_4_item_alloc_count = 0;
    this->field_15C0_unk.field_6_count = 0;
    this->field_15C0_unk.field_8_pal_type = 0;
    this->field_15C0_unk.field_C_pal_type = 0;
    this->field_15C0_unk.field_10_bDoFree = 0;
    this->field_1000_bFreeTextures2 = 0;
    this->field_1001_bFreeTextures1 = 0;
    this->field_15D4_idx = 0;
    this->field_15D6_pal_count = 0;
    memset(this, 0, 4096u);
    memset(this->field_1004_textures2, 0, sizeof(this->field_1004_textures2));
    this->field_1544_pTexture = 0;
}

sharp_pare_0x15D8::~sharp_pare_0x15D8()
{
    STexture * *pIter1; // esi
    int k1024Counter; // ebp
    STexture **pIter2; // esi
    int k48Counter; // ebp
    STexture **pIter3; // esi
    int k96Counter; // ebp

    if (this->field_1001_bFreeTextures1)
    {
        pIter1 = this->field_0_textures1;
        k1024Counter = 1024;
        do
        {
            if (*pIter1)
            {
                gbh_FreeTexture(*pIter1);
                *pIter1 = 0;
            }
            ++pIter1;
            --k1024Counter;
        } while (k1024Counter);
    }

    if (this->field_1000_bFreeTextures2)
    {
        pIter2 = this->field_1004_textures2;
        k48Counter = 48;
        do
        {
            if (*pIter2)
            {
                gbh_FreeTexture(*pIter2);
                *pIter2 = 0;
            }
            ++pIter2;
            --k48Counter;
        } while (k48Counter);
    }

    pIter3 = &this->field_10C4[0].field_4_pTexture;
    k96Counter = 96;
    do
    {
        if (*pIter3)
        {
            gbh_FreeTexture(*pIter3);
            *pIter3 = 0;
        }
        pIter3 += 3;
        --k96Counter;
    } while (k96Counter);

    if (this->field_1544_pTexture)
    {
        gbh_FreeTexture(this->field_1544_pTexture);
        this->field_1544_pTexture = 0;
    }

    FreePals_5B9140();

    field_15C0_unk.Free_5B9050();
    field_15AC_unk.Free_5B9050();
    field_1598_unk.Free_5B9050();
    field_1584_unk.Free_5B9050();
    field_1570_unk.Free_5B9050();
    field_155C_unk.Free_5B9050();
    field_1548_unk.Free_5B9050();
}

void sharp_pare_0x15D8::sub_5B9350()
{
    LoadPals_5B90F0();
    ReadTextures_5B92E0();

    field_1548_unk.Alloc_5B8E90(gGtx_0x106C_703DD4->sub_5AA560(2), 1, 0, 2);
    field_1548_unk.LoadTextures_5B8F00();

    field_155C_unk.Alloc_5B8E90(gGtx_0x106C_703DD4->sub_5AA4F0(2), gGtx_0x106C_703DD4->sub_5AA560(3), 2, 3);

    field_155C_unk.sub_5B8F70();
    field_1570_unk.Alloc_5B8E90(gGtx_0x106C_703DD4->sub_5AA4F0(3), gGtx_0x106C_703DD4->sub_5AA560(4), 3, 4);
    field_1570_unk.sub_5B8F70();

    field_1584_unk.Alloc_5B8E90(gGtx_0x106C_703DD4->sub_5AA4F0(4), gGtx_0x106C_703DD4->sub_5AA560(5), 4, 5);
    field_1584_unk.sub_5B8F70();

    field_1598_unk.Alloc_5B8E90(gGtx_0x106C_703DD4->sub_5AA4F0(5), gGtx_0x106C_703DD4->sub_5AA560(6), 5, 6);
    field_1598_unk.sub_5B8F70();

    field_15AC_unk.Alloc_5B8E90(gGtx_0x106C_703DD4->sub_5AA4F0(7), gGtx_0x106C_703DD4->sub_5AA560(8), 7, 8);
    field_15AC_unk.sub_5B8F70();

    field_15C0_unk.Alloc_5B8E90(gGtx_0x106C_703DD4->sub_5AA4F0(6), gGtx_0x106C_703DD4->sub_5AA560(7), 6, 7);
    field_15C0_unk.sub_5B8F70();

    LoadTextures2_5B9180();

    field_1544_pTexture = (STexture*)gbh_RegisterTexture(128, 128, 0, 0, 0);
}

void sharp_pare_0x15D8::FreePals_5B9140()
{
    // todo
}

void sharp_pare_0x15D8::LoadPals_5B90F0()
{
    // todo
}

void sharp_pare_0x15D8::ReadTextures_5B92E0()
{
    // todo
}

void sharp_pare_0x15D8::LoadTextures2_5B9180()
{
    // todo
}

// match
void festive_hopper::Free_5B9050()
{
    if (field_10_bDoFree && field_0_pAlloc)
    {
        for (unsigned short i = 0; i < field_4_item_alloc_count; ++i)
        {
            gbh_FreeTexture(field_0_pAlloc[i]);
        }

        free(field_0_pAlloc);
        field_0_pAlloc = 0;
    }
}

void festive_hopper::Alloc_5B8E90(__int16 a2, __int16 a3, int a4, int a5)
{
    if (!this->field_0_pAlloc)
    {
        if (a2)
        {
            this->field_4_item_alloc_count = a3 * a2;
            this->field_6_count = a3;
            this->field_10_bDoFree = 1;
            this->field_8_pal_type = a4;
            this->field_C_pal_type = a5;
            this->field_0_pAlloc = (STexture**)malloc(4 * (unsigned __int16)(a3 * a2));
            
            unsigned int i = 0;
            while  (i < this->field_4_item_alloc_count)
            {
                this->field_0_pAlloc[i++] = 0;
            }
        }
    }
}

void festive_hopper::sub_5B8F70()
{
    // todo
}

void festive_hopper::LoadTextures_5B8F00()
{
    // todo
}
