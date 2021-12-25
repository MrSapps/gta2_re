#include "gtx_0x106C.hpp"
#include "error.hpp"
#include "file.hpp"
#include <string.h>
#include <stdio.h>
#include <windows.h>

struct sty_header
{
    char field_0_type[4];
    short field_4_version;
};

struct chunk_header
{
    char field_0_type[4];
    int field_4_size;
};

// match
car_info* gtx_0x106C::sub_5AA3B0(unsigned __int8 idx)
{
    return field_5C_cari[idx];
}

// match
BYTE* gtx_0x106C::sub_5AA3D0(unsigned __int8 idx)
{
    car_info* pCarInfo = field_5C_cari[idx];
    return &pCarInfo->remap[pCarInfo->num_remaps];
}

unsigned __int16 gtx_0x106C::convert_sprite_pal_5AA460(int type, __int16 sprite_pal)
{
    unsigned __int16 result; // ax

    switch (type)
    {
    case 2:
        result = sprite_pal + this->field_14_sprite_base2->field_0_car;
        break;
    case 3:
        result = sprite_pal + this->field_14_sprite_base2->field_2_ped;
        break;
    case 4:
    case 8:
        result = sprite_pal + this->field_14_sprite_base2->field_4_code_obj;
        break;
    case 5:
        result = sprite_pal + this->field_14_sprite_base2->field_6_map_obj;
        break;
    case 6:
        result = sprite_pal + this->field_14_sprite_base2->field_8_user;
        break;
    case 7:
        result = sprite_pal + this->field_14_sprite_base2->field_A_font;
        break;
    default:
        result = sprite_pal;
        break;
    }
    return result;
}

__int16 gtx_0x106C::sub_5AA4F0(int a2)
{
    __int16 result; // ax

    switch (a2)
    {
    case 2:
        result = this->field_18_sprite_base1->field_0_car;
        break;
    case 3:
        result = this->field_18_sprite_base1->field_2_ped;
        break;
    case 4:
    case 8:
        result = this->field_18_sprite_base1->field_4_code_obj;
        break;
    case 5:
        result = this->field_18_sprite_base1->field_6_map_obj;
        break;
    case 6:
        result = this->field_18_sprite_base1->field_8_user;
        break;
    case 7:
        result = this->field_18_sprite_base1->field_A_font;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

__int16 gtx_0x106C::sub_5AA560(int a2)
{
    __int16 result; // ax

    switch (a2)
    {
    case 1:
        result = this->field_10_palette_base1->field_0_tile;
        break;
    case 2:
        result = this->field_10_palette_base1->field_2_sprite;
        break;
    case 3:
        result = this->field_10_palette_base1->field_4_car_remap;
        break;
    case 4:
        result = this->field_10_palette_base1->field_6_red_remap;
        break;
    case 5:
        result = this->field_10_palette_base1->field_8_code_obj_remap;
        break;
    case 6:
        result = this->field_10_palette_base1->field_A_map_obj_remap;
        break;
    case 7:
        result = this->field_10_palette_base1->field_C_user_remap;
        break;
    case 8:
        result = this->field_10_palette_base1->field_E_font_remap;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

__int16 gtx_0x106C::convert_pal_type_5AA5F0(int type, __int16 pal)
{
    __int16 result; // ax

    switch (type)
    {
    case 1:
        result = pal + this->field_C_palette_base2->field_0_tile;
        break;
    case 2:
        result = pal + this->field_C_palette_base2->field_2_sprite;
        break;
    case 3:
        result = pal + this->field_C_palette_base2->field_4_car_remap;
        break;
    case 4:
        result = pal + this->field_C_palette_base2->field_6_red_remap;
        break;
    case 5:
        result = pal + this->field_C_palette_base2->field_8_code_obj_remap;
        break;
    case 6:
        result = pal + this->field_C_palette_base2->field_A_map_obj_remap;
        break;
    case 7:
        result = pal + this->field_C_palette_base2->field_C_user_remap;
        break;
    case 8:
        result = pal + this->field_C_palette_base2->field_E_font_remap;
        break;
    default:
        result = pal;
        break;
    }
    return result;
}

int gtx_0x106C::GetPalData_5AA6A0(__int16 a2)
{
    return this->field_2C_physical_palettes + 4 * ((a2 & 63) + ((a2 & 0xFFC0) << 8));
}

__int16 gtx_0x106C::get_phys_pal_5AA6F0(unsigned __int16 palId)
{
    return this->field_28_palette_index->field_0_phys_palette[palId];
}

unsigned __int16 gtx_0x106C::sub_5AA710(unsigned __int16 a2, __int16 a3)
{
    // TODO
    return 0;
}

__int16 gtx_0x106C::sub_5AA760(WORD *a2, WORD *a3)
{
    // TODO
    return 0;
}

__int16 gtx_0x106C::sub_5AA7B0(WORD *a2)
{
    // TODO
    return 0;
}

__int16 gtx_0x106C::sub_5AA800(WORD *a2)
{
    // TODO
    return 0;
}

bool gtx_0x106C::sub_5AA850(unsigned __int16 tile_idx)
{
    return this->field_40_tile->field_0[tile_idx] != tile_idx;
}

__int16 gtx_0x106C::sub_5AA870(unsigned __int16 tile_idx)
{
    return this->field_40_tile->field_0[tile_idx];
}

__int16 gtx_0x106C::sub_5AA890()
{
    __int16 internal_idx; // ax
    __int16 *i; // ecx

    internal_idx = 1023;
    for (i = &this->field_40_tile->field_0[1023]; *i; --i)
    {
        if ((unsigned __int16)--internal_idx < 992u)
            return 0;
    }
    return internal_idx;
}

__int16 gtx_0x106C::get_physical_palettes_len_5AA900()
{
    return this->field_8_physical_palettes_len;
}

object_info* gtx_0x106C::get_map_object_info_5AA910(unsigned __int16 idx)
{
    if (idx < (unsigned int)this->field_6_map_object_info_len)
        return &this->field_24_map_object_info[idx];
    else
        return 0;
}

int gtx_0x106C::sub_5AA930(unsigned __int16 tile_idx, __int16 tile_val)
{
    int result; // eax

    result = tile_idx;
    this->field_40_tile->field_0[tile_idx] = tile_val;
    return result;
}

void gtx_0x106C::create_tile_num_array_5AA950()
{
    // TODO
}

void gtx_0x106C::sub_5AA9A0(int a2)
{
    // TODO
}

void gtx_0x106C::sub_5AAB30(unsigned int delx_chunk_size)
{
    // TODO
}

sprite_index* gtx_0x106C::get_sprite_index_5AA440(unsigned __int16 idx)
{
    return &this->field_20_sprite_index[idx];
}

void gtx_0x106C::sub_5AABF0()
{
    // TODO
}

void gtx_0x106C::SetSpriteIndexDataPtrs_5AAC40()
{
    // TODO
}

void gtx_0x106C::sub_5AAC70()
{
    // TODO
}

void gtx_0x106C::load_car_info_5AAD50(int cari_chunk_size)
{
    void *v3; // eax

    v3 = malloc(cari_chunk_size);
    this->field_58_car_info = v3;
    File::Global_Read_4A71C0(v3, &cari_chunk_size);
    gtx_0x106C::sub_5AA9A0(cari_chunk_size);
}

void gtx_0x106C::load_delta_index_5AAD80(int delx_chunk_size)
{
    // TODO
}

void gtx_0x106C::load_delta_store_5AADD0(int dels_chunk_size)
{
    // TODO
}

void gtx_0x106C::load_tiles_5AADF0(int tile_chunk_len)
{
    // TODO
}

void gtx_0x106C::skip_ovly_5AAE20(int a1)
{
    File::Global_Seek_4A7140(&a1);
}

void gtx_0x106C::skip_psxt_5AAE30(int a1)
{
    File::Global_Seek_4A7140(&a1);
}

void gtx_0x106C::load_sprite_graphics_5AAE40(int sprg_chunk_len)
{
    // TODO
}

void gtx_0x106C::load_physical_palettes_5AAE70(int ppal_chunk_size)
{
    // TODO
}

void gtx_0x106C::load_palette_index_5AAEA0(int palx_chunk_len)
{
    // TODO
}

void gtx_0x106C::load_map_object_info_5AAF00(int obji_chunk_len)
{
    // TODO
}

void gtx_0x106C::load_sprite_index_5AAF80(int sprx_chunk_size)
{
    // TODO
}

void gtx_0x106C::sub_5AAFE0(unsigned __int16 a1)
{
    // TODO
}

void gtx_0x106C::load_font_base_5AB0F0(int fonb_chunk_size)
{
    // TODO
}

int gtx_0x106C::ConvertToVirtualOffsets_5AB1A0(int len, WORD *pOffsets, int offsetsCount)
{
    // TODO
    return 0;
}

void gtx_0x106C::ConvertToVirtualOffsets_5AB1C0(WORD *pBuffer, int len)
{
    // TODO
}

void gtx_0x106C::load_sprite_base_5AB210(int sprite_base_chunk_size)
{
    // TODO
}

void gtx_0x106C::load_palete_base_5AB2C0(int palette_base_chunk_len)
{
    // TODO
}

bool gtx_0x106C::sub_5AB380(unsigned __int8 car_id)
{
    // TODO
    return false;
}

void gtx_0x106C::load_car_recycling_info_5AB3C0(int recy_chunk_size)
{
    // TODO
}

void gtx_0x106C::read_spec_5AB3F0(int read_size2)
{
    // TODO
}

void gtx_0x106C::load_spec_5AB450()
{
    // TODO
}

void gtx_0x106C::LoadChunk_5AB4B0(const char *Str1, int chunk_len)
{
    if (!strncmp(Str1, "PALB", 4u))
    {
        load_palete_base_5AB2C0(chunk_len);
    }
    else if (!strncmp(Str1, "SPRB", 4u))
    {
        load_sprite_base_5AB210(chunk_len);
    }
    else if (!strncmp(Str1, "FONB", 4u))
    {
        load_font_base_5AB0F0(chunk_len);
    }
    else if (!strncmp(Str1, "SPRX", 4u))
    {
        load_sprite_index_5AAF80(chunk_len);
    }
    else if (!strncmp(Str1, "OBJI", 4u))
    {
        load_map_object_info_5AAF00(chunk_len);
    }
    else if (!strncmp(Str1, "PALX", 4u))
    {
        load_palette_index_5AAEA0(chunk_len);
    }
    else if (!strncmp(Str1, "PPAL", 4u))
    {
        load_physical_palettes_5AAE70(chunk_len);
    }
    else if (!strncmp(Str1, "SPRG", 4u))
    {
        load_sprite_graphics_5AAE40(chunk_len);
    }
    else if (!strncmp(Str1, "TILE", 4u))
    {
        load_tiles_5AADF0(chunk_len);
    }
    else if (!strncmp(Str1, "DELS", 4u))
    {
        load_delta_store_5AADD0(chunk_len);
    }
    else if (!strncmp(Str1, "DELX", 4u))
    {
        load_delta_index_5AAD80(chunk_len);
    }
    else if (!strncmp(Str1, "CARI", 4u))
    {
        load_car_info_5AAD50( chunk_len);
    }
    else if (!strncmp(Str1, "PSXT", 4u))
    {
        skip_psxt_5AAE30(chunk_len);
    }
    else if (!strncmp(Str1, "OVLY", 4u))
    {
        skip_ovly_5AAE20(chunk_len);
    }
    else if (!strncmp(Str1, "SPEC", 4u))
    {
        load_spec_5AB450();
    }
    else if (!strncmp(Str1, "RECY", 4u))
    {
        load_car_recycling_info_5AB3C0(chunk_len);
    }
    else
    {
        File::Global_Seek_4A7140(&chunk_len);
    }
}

// match
void gtx_0x106C::sub_5AB720()
{
    if (field_50_delta_buffer && field_48_delta_store)
    {
        sub_5AABF0();
    }

    if (field_20_sprite_index)
    {
        if (field_34_sprite_graphics)
        {
            SetSpriteIndexDataPtrs_5AAC40();
        }
    }
}

// match
void gtx_0x106C::LoadSty_5AB750(const char *pStyFileName)
{
    File::Global_Open_4A7060(pStyFileName);

    sty_header styHeader;
    int len = sizeof(sty_header);
    File::Global_Read_4A71C0(styHeader.field_0_type, &len);

    if (strncmp("GBST", styHeader.field_0_type, sizeof(styHeader.field_0_type)))
    {
        FatalError_4A38C0(93, "C:\\Splitting\\Gta2\\Source\\chunk.h", 37);
    }

    if (styHeader.field_4_version != 700)
    {
        FatalError_4A38C0(94, "C:\\Splitting\\Gta2\\Source\\chunk.h", 33);
    }

    chunk_header chunkHeader;
    for (len = sizeof(chunk_header); File::Global_Read_4A7210(&chunkHeader, &len); len = sizeof(chunk_header))
    {
        if (chunkHeader.field_4_size != 0)
        {
            LoadChunk_5AB4B0(chunkHeader.field_0_type, chunkHeader.field_4_size);
        }
    }

    File::Global_Close_4A70C0();

    sub_5AB720();
}

gtx_0x106C::gtx_0x106C()
{
    memset(this->field_6C_spec, 1, sizeof(field_6C_spec));
    this->field_64_car_recycling_info = 0;
    this->field_68_recy_chunk_size = 0;
    this->field_14_sprite_base2 = 0;
    this->field_C_palette_base2 = 0;
    this->field_1C_font_base = 0;
    this->field_20_sprite_index = 0;
    this->field_24_map_object_info = 0;
    this->field_6_map_object_info_len = 0;
    this->field_28_palette_index = 0;
    this->field_2C_physical_palettes = 0;
    this->field_30_physical_palettes_size = 0;
    this->field_3C_tiles = 0;
    this->field_44_aligned_tiles_size = 0;
    this->field_34_sprite_graphics = 0;
    this->field_38 = 0;
    this->field_48_delta_store = 0;
    this->field_50_delta_buffer = 0;
    this->field_58_car_info = 0;
    this->field_5C_cari = 0;
    this->field_4C_delta_index = 0;
    this->field_60_delta_len = 0;
    this->field_54_del = 0;
    this->field_4_sprite_index_count = 0;
    this->field_0_totalPalBase = 0;
    this->field_2_font_base_total = 0;
    this->field_40_tile = 0;
    this->field_8_physical_palettes_len = 0;
    this->field_6A = 0;
    this->field_10_palette_base1 = 0;
    this->field_18_sprite_base1 = 0;
}

gtx_0x106C::~gtx_0x106C()
{
    sprite_base *field_14_sprite_base2; // eax
    sprite_base *field_18_sprite_base1; // ecx
    palette_base *field_C_palette_base2; // edx
    palette_base *field_10_palette_base1; // eax
    font_base *field_1C_font_base; // eax
    sprite_index *field_20_sprite_index; // eax
    object_info *field_24_map_object_info; // eax
    palette_index *field_28_palette_index; // ecx
    void *field_30_physical_palettes_size; // eax
    void *field_44_aligned_tiles_size; // eax
    void *v12; // eax
    delta_store_entry *field_48_delta_store; // eax
    void *field_50_delta_buffer; // eax
    void *field_58_car_info; // eax
    car_info **field_5C_cari; // edx
    delta_entry *field_4C_delta_index; // eax
    void *field_54_del; // eax
    tile_array *field_40_tile; // eax

    if (this->field_64_car_recycling_info)
    {
        free(this->field_64_car_recycling_info);
    }

    field_14_sprite_base2 = this->field_14_sprite_base2;
    this->field_64_car_recycling_info = 0;
    delete field_14_sprite_base2;

    field_18_sprite_base1 = this->field_18_sprite_base1;
    this->field_14_sprite_base2 = 0;
    delete (field_18_sprite_base1);

    field_C_palette_base2 = this->field_C_palette_base2;
    this->field_18_sprite_base1 = 0;
    delete (field_C_palette_base2);
    field_10_palette_base1 = this->field_10_palette_base1;
    this->field_C_palette_base2 = 0;
    delete (field_10_palette_base1);
    field_1C_font_base = this->field_1C_font_base;
    this->field_10_palette_base1 = 0;
    if (field_1C_font_base)
    {
        free(field_1C_font_base);
    }

    field_20_sprite_index = this->field_20_sprite_index;
    this->field_1C_font_base = 0;
    if (field_20_sprite_index)
    {
        free(field_20_sprite_index);
    }
    field_24_map_object_info = this->field_24_map_object_info;
    this->field_20_sprite_index = 0;
    if (field_24_map_object_info)
    {
        free(field_24_map_object_info);
    }
    field_28_palette_index = this->field_28_palette_index;
    this->field_24_map_object_info = 0;
    delete(field_28_palette_index);
    field_30_physical_palettes_size = (void *)this->field_30_physical_palettes_size;
    this->field_28_palette_index = 0;
    if (field_30_physical_palettes_size)
    {
        free(field_30_physical_palettes_size);
    }
    field_44_aligned_tiles_size = (void *)this->field_44_aligned_tiles_size;
    this->field_2C_physical_palettes = 0;
    this->field_30_physical_palettes_size = 0;
    if (field_44_aligned_tiles_size)
    {
        free(field_44_aligned_tiles_size);
    }
    v12 = (void *)this->field_38;
    this->field_3C_tiles = 0;
    this->field_44_aligned_tiles_size = 0;
    if (v12)
    {
        free(v12);
    }
    field_48_delta_store = this->field_48_delta_store;
    this->field_34_sprite_graphics = 0;
    this->field_38 = 0;
    if (field_48_delta_store)
    {
        free(field_48_delta_store);
    }
    field_50_delta_buffer = this->field_50_delta_buffer;
    this->field_48_delta_store = 0;
    if (field_50_delta_buffer)
    {
        free(field_50_delta_buffer);
    }
    field_58_car_info = this->field_58_car_info;
    this->field_50_delta_buffer = 0;
    if (field_58_car_info)
    {
        free(field_58_car_info);
    }
    field_5C_cari = this->field_5C_cari;
    this->field_58_car_info = 0;
    delete(field_5C_cari);
    field_4C_delta_index = this->field_4C_delta_index;
    this->field_5C_cari = 0;
    if (field_4C_delta_index)
    {
        free(field_4C_delta_index);
    }
    field_54_del = (void *)this->field_54_del;
    this->field_4C_delta_index = 0;
    if (field_54_del)
    {
        free(field_54_del);
    }
    field_40_tile = this->field_40_tile;
    this->field_54_del = 0;
    delete(field_40_tile);
    this->field_40_tile = 0;
}
