#pragma once

struct angry_lewin_0x85C;

struct Game_0x40
{
    int field_0;
    angry_lewin_0x85C *field_4[6];
    angry_lewin_0x85C *field_1C_unk;
    unsigned __int8 field_20;
    unsigned __int8 field_21;
    char field_22;
    unsigned __int8 field_23_max_idx;
    unsigned __int8 field_24_cur_idx;
    char field_25;
    char field_26;
    char field_27;
    int field_28;
    int field_2C_main_state;
    char field_30;
    char field_31;
    char field_32;
    char field_33;
    int field_34;
    angry_lewin_0x85C *field_38_orf1;
    char field_3C_bSkipPolice;
    char field_3D;
    char field_3E;
    char field_3F;

    // todo: ordering

    void sub_4B9720();
};

extern Game_0x40* gGame_0x40_67E008;
