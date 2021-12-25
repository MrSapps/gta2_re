#pragma once

class nostalgic_ellis_0x28
{
public:
    nostalgic_ellis_0x28();

    ~nostalgic_ellis_0x28();

    void sub_4D6D70();

    nostalgic_ellis_0x28* sub_4D6DC0();

    nostalgic_ellis_0x28 *field_0;
    int field_4_light_x;
    int field_8_light_y;
    int field_C_light_z;
    int field_10_argb;
    char field_14_on_time;
    char field_15_off_time;
    char field_16_shape;
    char field_17_off_time;
    char field_18_intensity;
    char field_19;
    __int16 field_1A;
    nostalgic_ellis_0x28 *field_1C;
    nostalgic_ellis_0x28 *field_20;
    nostalgic_ellis_0x28 *field_24;
};

class Light
{
public:
    static void __stdcall sub_4D6E00();

    static void sub_4D6E30();

    static int __stdcall sub_4D6E50(int a1, int a2, int a3, int a4);
};