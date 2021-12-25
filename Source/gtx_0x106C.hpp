#pragma once

#include <windows.h>

struct palette_base
{
    __int16 field_0_tile;
    __int16 field_2_sprite;
    __int16 field_4_car_remap;
    __int16 field_6_red_remap;
    __int16 field_8_code_obj_remap;
    __int16 field_A_map_obj_remap;
    __int16 field_C_user_remap;
    __int16 field_E_font_remap;
};

struct sprite_base
{
    __int16 field_0_car;
    __int16 field_2_ped;
    __int16 field_4_code_obj;
    __int16 field_6_map_obj;
    __int16 field_8_user;
    unsigned __int16 field_A_font;
};

struct font_base
{
    __int16 field_0_font_count;
    __int16 field_2_base[2];
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
    __int16 field_0_phys_palette[16384];
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
    BYTE remap[1]; // [variable – see num_remaps];
    BYTE num_doors;
    door_info doors[1]; // [variable – see num_doors];
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
    char field_3_data[1]; // variable – see field_2_len
};


class gtx_0x106C
{
public:
    car_info* sub_5AA3B0(unsigned __int8 idx);

    BYTE* sub_5AA3D0(unsigned __int8 idx);

    sprite_index* get_sprite_index_5AA440(unsigned __int16 idx);

    unsigned __int16 convert_sprite_pal_5AA460(int type, __int16 sprite_pal);

    __int16 sub_5AA4F0(int a2);

    __int16 sub_5AA560(int a2);

    __int16 convert_pal_type_5AA5F0(int type, __int16 pal);

    int GetPalData_5AA6A0(__int16 a2);

    __int16 get_phys_pal_5AA6F0(unsigned __int16 palId);

    unsigned __int16 sub_5AA710(unsigned __int16 a2, __int16 a3);

    __int16 sub_5AA760(WORD *a2, WORD *a3);

    __int16 sub_5AA7B0(WORD *a2);

    __int16 sub_5AA800(WORD *a2);

    bool sub_5AA850(unsigned __int16 tile_idx);

    __int16 sub_5AA870(unsigned __int16 tile_idx);

    __int16 sub_5AA890();

    __int16 get_physical_palettes_len_5AA900();

    object_info* get_map_object_info_5AA910(unsigned __int16 idx);

    int sub_5AA930(unsigned __int16 tile_idx, __int16 tile_val);

    void create_tile_num_array_5AA950();

    void sub_5AA9A0(int a2);

    void sub_5AAB30(unsigned int delx_chunk_size);

    void sub_5AABF0();

    void SetSpriteIndexDataPtrs_5AAC40();

    void sub_5AAC70();

    void load_car_info_5AAD50(int cari_chunk_size);

    void load_delta_index_5AAD80(int delx_chunk_size);

    void load_delta_store_5AADD0(int dels_chunk_size);

    void load_tiles_5AADF0(int tile_chunk_len);

    void skip_ovly_5AAE20(int a1);

    void skip_psxt_5AAE30(int a1);

    void load_sprite_graphics_5AAE40(int sprg_chunk_len);

    void load_physical_palettes_5AAE70(int ppal_chunk_size);

    void load_palette_index_5AAEA0(int palx_chunk_len);

    void load_map_object_info_5AAF00(int obji_chunk_len);

    void load_sprite_index_5AAF80(int sprx_chunk_size);

    void sub_5AAFE0(unsigned __int16 a1);

    void load_font_base_5AB0F0(int fonb_chunk_size);

    int ConvertToVirtualOffsets_5AB1A0(int len, WORD *pOffsets, int offsetsCount);

    void ConvertToVirtualOffsets_5AB1C0(WORD *pBuffer, int len);

    void load_sprite_base_5AB210(int sprite_base_chunk_size);

    void load_palete_base_5AB2C0(int palette_base_chunk_len);

    bool sub_5AB380(unsigned __int8 car_id);

    void load_car_recycling_info_5AB3C0(int recy_chunk_size);

    void read_spec_5AB3F0(int read_size2);

    void load_spec_5AB450();

    void LoadChunk_5AB4B0(const char *Str1, int chunk_len);

    void sub_5AB720();

    void LoadSty_5AB750(const char *pStyFileName);

    // 0x5AB820
    gtx_0x106C();

    // 0x5AB8A0
    ~gtx_0x106C();

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
    int field_2C_physical_palettes;
    int field_30_physical_palettes_size;
    BYTE *field_34_sprite_graphics;
    int field_38;
    void *field_3C_tiles;
    tile_array *field_40_tile;
    int field_44_aligned_tiles_size;
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
