#pragma once

#include <windows.h>
#include "types.hpp"

struct palette_base
{
    WORD field_0_tile;
    WORD field_2_sprite;
    WORD field_4_car_remap;
    WORD field_6_red_remap;
    WORD field_8_code_obj_remap;
    WORD field_A_map_obj_remap;
    WORD field_C_user_remap;
    WORD field_E_font_remap;
};

struct sprite_base
{
    WORD field_0_car;
    WORD field_2_ped;
    WORD field_4_code_obj;
    WORD field_6_map_obj;
    WORD field_8_user;
    unsigned __int16 field_A_font;
};

struct font_base
{
    __int16 field_0_font_count;
    WORD field_2_base[1]; // variable � see font_count
};

struct sprite_index
{
    BYTE* field_0_pData;
    unsigned __int8 field_4_width;
    unsigned __int8 field_5_height;
    __int16 field_6_pad;
};

struct object_info
{
    unsigned __int8 field_0_model;
    unsigned __int8 field_1_sprites;
};

struct palette_index
{
    unsigned __int16 field_0_phys_palette[16384];
};

struct tile_array
{
    __int16 field_0[1024];
};

struct delta_entry
{
    __int16 field_0_which_sprite;
    char field_2_delta_count;
    char field_3_pad;
    __int16 field_4_delta[2];
};

struct door_info
{
    char rx, ry;
};

struct car_info
{
    BYTE model;
    BYTE sprite;
    BYTE w;
    BYTE h;
    BYTE num_remaps;
    BYTE passengers;
    BYTE wreck;
    BYTE rating;
    char front_wheel_offset;
    char rear_wheel_offset;
    char front_window_offset;
    char rear_window_offset;
    BYTE info_flags;
    BYTE info_flags_2;
    BYTE remap[1]; // [variable � see num_remaps];
    BYTE num_doors;
    door_info doors[1]; // [variable � see num_doors];
};

struct car_info_container
{
    car_info_container()
    {
        field_400_count = 0;
        memset(field_0, 0, sizeof(field_0));
    }
    car_info *field_0[256];
    char field_400_count;
    //char field_401;// pad
    //char field_402;// pad
    //char field_403;// pad
};

struct delta_store_entry
{
    __int16 field_0_offset;
    char field_2_len;
    char field_3_data[1]; // variable � see field_2_len
};


class gtx_0x106C
{
public:
    EXPORT car_info* get_car_info_5AA3B0(unsigned __int8 idx);

    EXPORT BYTE* get_car_remap_5AA3D0(unsigned __int8 idx);

    EXPORT sprite_index* get_sprite_index_5AA440(unsigned __int16 idx);

    EXPORT unsigned __int16 convert_sprite_pal_5AA460(int type, __int16 sprite_pal);

    EXPORT __int16 sub_5AA4F0(int a2);

    EXPORT __int16 sub_5AA560(int a2);

    EXPORT __int16 convert_pal_type_5AA5F0(int type, __int16 pal);

    EXPORT BYTE* GetPalData_5AA6A0(__int16 a2);

    EXPORT unsigned __int16 get_phys_pal_5AA6F0(unsigned __int16 palId);

    EXPORT unsigned __int16 sub_5AA710(unsigned __int16 a2, __int16 a3);

    EXPORT unsigned __int16 sub_5AA760(WORD *a2, wchar_t *a3);

    EXPORT unsigned __int16 space_width_5AA7B0(WORD *a2);

    EXPORT __int16 sub_5AA800(WORD *a2);

    EXPORT bool sub_5AA850(unsigned __int16 tile_idx);

    EXPORT __int16 sub_5AA870(unsigned __int16 tile_idx);

    EXPORT __int16 sub_5AA890();

    EXPORT __int16 get_physical_palettes_len_5AA900();

    EXPORT object_info* get_map_object_info_5AA910(unsigned __int16 idx);

    EXPORT int sub_5AA930(unsigned __int16 tile_idx, __int16 tile_val);

    EXPORT void create_tile_num_array_5AA950();

    EXPORT void sub_5AA9A0(int a2);

    EXPORT void sub_5AAB30(unsigned int delx_chunk_size);

    EXPORT void sub_5AABF0();

    EXPORT void SetSpriteIndexDataPtrs_5AAC40();

    EXPORT void sub_5AAC70();

    EXPORT void load_car_info_5AAD50(unsigned int cari_chunk_size);

    EXPORT void load_delta_index_5AAD80(unsigned int delx_chunk_size);

    EXPORT void load_delta_store_5AADD0(unsigned int dels_chunk_size);

    EXPORT void load_tiles_5AADF0(unsigned int tile_chunk_len);

    EXPORT void skip_ovly_5AAE20(unsigned int a1);

    EXPORT void skip_psxt_5AAE30(unsigned int a1);

    EXPORT void load_sprite_graphics_5AAE40(unsigned int sprg_chunk_len);

    EXPORT void load_physical_palettes_5AAE70(unsigned int ppal_chunk_size);

    EXPORT void load_palette_index_5AAEA0(unsigned int palx_chunk_len);

    EXPORT void load_map_object_info_5AAF00(unsigned int obji_chunk_len);

    EXPORT void load_sprite_index_5AAF80(unsigned int sprx_chunk_size);

    EXPORT void sub_5AAFE0(unsigned __int16 a1);

    EXPORT void load_font_base_5AB0F0(unsigned int fonb_chunk_size);

    EXPORT static WORD __stdcall ConvertToVirtualOffsets_5AB1A0(WORD *pOffsets, unsigned int offsetsCount);

    EXPORT static void __stdcall ConvertToVirtualOffsets_5AB1C0(WORD *pBuffer, unsigned int len);

    EXPORT void load_sprite_base_5AB210(unsigned int sprite_base_chunk_size);

    EXPORT void load_palete_base_5AB2C0(unsigned int palette_base_chunk_len);

    EXPORT bool sub_5AB380(unsigned __int8 car_id);

    EXPORT void load_car_recycling_info_5AB3C0(unsigned int recy_chunk_size);

    EXPORT void read_spec_5AB3F0(unsigned int read_size2);

    EXPORT void load_spec_5AB450();

    EXPORT void LoadChunk_5AB4B0(const char *Str1, unsigned int chunk_len);

    EXPORT void sub_5AB720();

    EXPORT void LoadSty_5AB750(const char *pStyFileName);

    // 0x5AB820
    EXPORT gtx_0x106C();

    // 0x5AB8A0
    EXPORT ~gtx_0x106C();

    __int16 field_0_totalPalBase;
    __int16 field_2_font_base_total;
    __int16 field_4_sprite_index_count;
    __int16 field_6_map_object_info_len;
    __int16 field_8_physical_palettes_len;
    __int16 field_A;
    palette_base *field_C_palette_base2;
    palette_base *field_10_palette_base1;
    sprite_base *field_14_sprite_base2;
    sprite_base *field_18_sprite_base1;
    font_base *field_1C_font_base;
    sprite_index *field_20_sprite_index;
    object_info *field_24_map_object_info;
    palette_index *field_28_palette_index;
    void* field_2C_physical_palettes;
    void* field_30_physical_palettes_size;
    BYTE *field_34_sprite_graphics;
    void* field_38;
    void *field_3C_tiles;
    tile_array *field_40_tile;
    void* field_44_aligned_tiles_size;
    delta_store_entry* field_48_delta_store;
    delta_entry *field_4C_delta_index;
    void *field_50_delta_buffer;
    int field_54_del;
    car_info** field_58_car_info;
    car_info_container* field_5C_cari;
    int field_60_delta_len;
    unsigned __int8 *field_64_car_recycling_info;
    __int16 field_68_recy_chunk_size;
    char field_6A;
    char field_6B;
    int field_6C_spec[1024];
};

extern gtx_0x106C *gGtx_0x106C_703DD4;
