#pragma once

#include <windows.h>

struct gmp_col_info
{
    unsigned __int8 field_0_height;
    unsigned __int8 field_1_offset;
    __int16 field_2_pad;
    int field_4_blockd[2];
};

struct gmp_block_info
{
    __int16 field_0_left;
    __int16 field_2_right;
    __int16 field_4_top;
    __int16 field_6_bottom;
    __int16 field_8_lid;
    char field_A_arrows;
    unsigned __int8 field_B_slope_type;
};

struct gmp_compressed_map_32
{
    unsigned int field_0_base[256][256];
    int field_40000_column_words;
    int field_40004_num_blocks;
    unsigned short **field_40008_pColumn;
    gmp_block_info *field_4000C_block;
};

struct Map_sub
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
    int field_220;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    int field_288;
    int field_28C;
    int field_290;
    int field_294;
    int field_298;
    int field_29C;
    int field_2A0;
    int field_2A4;
    int field_2A8;
    int field_2AC;
    int field_2B0;
    int field_2B4;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    int field_2C8;
    int field_2CC;
    int field_2D0;
    int field_2D4;
    int field_2D8;
    int field_2DC;
    int field_2E0;
    int field_2E4;
    int field_2E8;
    int field_2EC;
    int field_2F0;
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int field_310;
    int field_314;
    int field_318;
    int field_31C;
    int field_320_max_idx;
};

struct gmp_map_zone
{
    char field_0_zone_type;
    unsigned __int8 field_1_x;
    unsigned __int8 field_2_y;
    unsigned __int8 field_3_w;
    unsigned __int8 field_4_h;
    unsigned __int8 field_5_name_length;
    char field_6_name[2];
};

struct gmp_zone_unknown
{
    __int16 field_0;
    __int16 field_2;
    __int16 field_4;
    __int16 field_6;
    __int16 field_8;
    __int16 field_A;
    __int16 field_C;
    __int16 field_E;
    __int16 field_10;
    __int16 field_12;
    __int16 field_14;
};

struct gmp_map_object
{
    __int16 field_0_x;
    __int16 field_2_y;
    char field_4_rotation;
    char field_5_object_type;
};

struct gmp_map_light
{
    int field_0_argb;
    __int16 field_4_x;
    __int16 field_6_y;
    __int16 field_8_z;
    __int16 field_A_radius;
    char field_C_intensity;
    char field_D_shape;
    char field_E_on_time;
    char field_F_off_time;
};

class Map_0x370
{
public:
    gmp_block_info* get_block_452980(unsigned __int8 x_coord, unsigned __int8 y_coord, unsigned __int8 z_coord);

    gmp_map_zone* zone_by_name_4DEFD0(const char *pZoneName);

    int zone_idx_by_name_4DF050(const char *pZoneName, BYTE zone_name_len);

    gmp_map_zone* zone_by_type_bounded_4DF0F0(char zone_type);

    gmp_map_zone* first_zone_by_type_4DF1D0(char zone_type);

    // todo: missing func

    gmp_map_zone* zone_by_pos_and_type_4DF4D0(char zone_x, char zone_y, char zone_type);

    // todo: other funcs

    gmp_zone_unknown* cur_zone_4DF840();

    gmp_zone_unknown* get_nav_zone_unknown_4DF890(int zone_x, int zone_y);

    void set_nav_unknown_data_4DF8C0(
        int zone_idx,
        __int16 a3,
        __int16 a4,
        __int16 a5,
        __int16 a6,
        __int16 a7,
        __int16 a8,
        __int16 a9,
        __int16 a10,
        __int16 a11,
        __int16 a12,
        __int16 a13);

    gmp_zone_unknown* get_zone_unknown_4DF9A0(unsigned __int16 zone_idx);

    void set_nav_unknown_f0_4DF9D0(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_f2_4DF9F0(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_f4_4DFA10(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_f6_4DFA30(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_f8_4DFA50(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_fA_4DFA70(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_fC_4DFA90(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_fE_4DFAB0(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_f10_4DFAD0(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_f12_4DFAF0(unsigned __int16 a2, __int16 a3);

    void set_nav_unknown_f14_4DFB10(unsigned __int16 a2, __int16 a3);

    gmp_map_zone* get_zone_4DFB30(unsigned __int16 zone_idx);


    // todo: other funcs between

    gmp_map_zone* nav_zone_by_pos_4DF5C0(char zone_x, char zone_y);


public:
    gmp_compressed_map_32 *field_0_pDmap;
    Map_sub field_4_obj;
    gmp_map_zone *field_328_pZoneData;
    gmp_map_zone **field_32C_pZones;
    BYTE *field_330_pZoneArray;
    gmp_zone_unknown *field_334_pUnknownZoneData;
    gmp_map_object *field_338_pMapObjects;
    gmp_map_light *field_33C_pLightData;
    int field_340_pTileAnimData;
    int field_344_map_object_count;
    int field_348_num_lights;
    int field_34C_num_blocks;
    int field_350_num_blocks_extra;
    int field_354_num_blocks;
    int field_358_column_words;
    int field_35C_column_word_extra;
    int field_360_column_words;
    unsigned __int16 field_364_cur_zone_idx;
    __int16 field_366;
    char field_368_zone_type;
    char field_369;
    unsigned __int8 field_36A_zone_x;
    unsigned __int8 field_36B_zone_y;
    char field_36C_bUnknown;
    char field_36D;
    char field_36E;
    char field_36F;
};
