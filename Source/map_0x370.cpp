#include "map_0x370.hpp"

// match
gmp_block_info* Map_0x370::get_block_452980(unsigned __int8 x_coord, unsigned __int8 y_coord, unsigned __int8 z_coord)
{
    gmp_col_info* pColData = reinterpret_cast<gmp_col_info*>(&field_0_pDmap->field_40008_pColumn[field_0_pDmap->field_0_base[y_coord][x_coord]]);
    if (z_coord >= pColData->field_0_height || z_coord < pColData->field_1_offset)
    {
        return 0;
    }
    else
    {
        return &field_0_pDmap->field_4000C_block[pColData->field_4_blockd[z_coord - pColData->field_1_offset]];
    }
}

// match
gmp_map_zone* Map_0x370::zone_by_name_4DEFD0(const char *pZoneName)
{
    unsigned int name_len = strlen(pZoneName);
    if (field_328_pZoneData)
    {
        for (field_364_cur_zone_idx = 0; field_364_cur_zone_idx < *(WORD *)field_32C_pZones; field_364_cur_zone_idx++)
        {
            gmp_map_zone *pZone = get_zone_4DFB30(field_364_cur_zone_idx);
            if (pZone->field_5_name_length == name_len  &&
                memcmp(pZone->field_6_name, pZoneName, name_len ) == 0)
            {
                return pZone;
            }
        }
    }
    return 0;
}

// match
int Map_0x370::zone_idx_by_name_4DF050(const char *pZoneName, BYTE zone_name_len)
{
    if (!field_328_pZoneData)
    {
        return 0;
    }

    for (field_364_cur_zone_idx = 0; field_364_cur_zone_idx < *(WORD *)field_32C_pZones; field_364_cur_zone_idx++)
    {
        gmp_map_zone * pZone = get_zone_4DFB30(field_364_cur_zone_idx);
        // note: esp/stack reorder due to int -> byte cast on zone_name_len wrong type
        if (pZone->field_5_name_length == zone_name_len &&
            _strnicmp(pZone->field_6_name, pZoneName, zone_name_len) == 0)
        {
            return field_364_cur_zone_idx;
        }
    }
    return -1;
}

// match
gmp_map_zone* Map_0x370::zone_by_type_bounded_4DF0F0(char zone_type)
{
    static short sLastIdx_6F626C;

    __int16 local_array[40];

    if (field_328_pZoneData)
    {
        unsigned __int16 idx = 0;
        field_36C_bUnknown = 0;
        field_368_zone_type = zone_type;
        field_364_cur_zone_idx = 0;

        for (field_364_cur_zone_idx = 0; field_364_cur_zone_idx < *(WORD *)field_32C_pZones; field_364_cur_zone_idx++)
        {
            if (get_zone_4DFB30(field_364_cur_zone_idx)->field_0_zone_type == field_368_zone_type)
            {
                local_array[idx++] = field_364_cur_zone_idx;
                if (idx >= 40u)
                {
                    break;
                }
            }
        }

        if (idx > 0)
        {
            sLastIdx_6F626C++;
            if (sLastIdx_6F626C >= idx)
            {
                sLastIdx_6F626C = 0;
            }
            return get_zone_4DFB30(local_array[sLastIdx_6F626C]);
        }
    }

    return 0;
}

// match
gmp_map_zone* Map_0x370::first_zone_by_type_4DF1D0(char zone_type)
{
    if (field_328_pZoneData)
    {
        field_36C_bUnknown = 0;
        field_368_zone_type = zone_type;
        field_364_cur_zone_idx = 0;

        for (field_364_cur_zone_idx = 0; field_364_cur_zone_idx < *(WORD *)field_32C_pZones; field_364_cur_zone_idx++)
        {
            gmp_map_zone *pZone = get_zone_4DFB30(field_364_cur_zone_idx);
            if (pZone->field_0_zone_type == field_368_zone_type)
            {
                return pZone;
            }
        }
    }
    return 0;
}

// nomatch
gmp_map_zone* Map_0x370::zone_by_pos_and_type_4DF4D0(char zone_x, char zone_y, char zone_type)
{
    if (field_328_pZoneData)
    {
        field_368_zone_type = zone_type;
        field_36A_zone_x = zone_x;
        field_36B_zone_y = zone_y;
        field_36C_bUnknown = 1;

        for (field_364_cur_zone_idx = 0; field_364_cur_zone_idx < *(WORD *)field_32C_pZones; field_364_cur_zone_idx++)
        {
            gmp_map_zone *pZone = get_zone_4DFB30(field_364_cur_zone_idx);
            if (field_368_zone_type == pZone->field_0_zone_type &&
                field_36A_zone_x >= pZone->field_1_x &&
                field_36B_zone_y >= pZone->field_2_y &&
                field_36A_zone_x < pZone->field_1_x + pZone->field_3_w &&
                field_36B_zone_y < pZone->field_2_y + pZone->field_4_h)
            {
                return pZone;
            }
        }
    }
    return 0;
}

// nomatch
gmp_map_zone* Map_0x370::nav_zone_by_pos_4DF5C0(char zone_x, char zone_y)
{
    gmp_map_zone **field_32C_pZones; // edx
    gmp_map_zone *pZone; // eax
    char field_0_zone_type; // cl

    if (!this->field_328_pZoneData)
    {
        return 0;
    }

    field_32C_pZones = this->field_32C_pZones;
    this->field_36A_zone_x = zone_x;
    this->field_36B_zone_y = zone_y;
    this->field_364_cur_zone_idx = 0;
    if (!*(WORD *)field_32C_pZones)
    {
        return 0;
    }
    while (1)
    {
        pZone = get_zone_4DFB30(this->field_364_cur_zone_idx);
        field_0_zone_type = pZone->field_0_zone_type;
        if ((pZone->field_0_zone_type == 10 || field_0_zone_type == 1 || field_0_zone_type == 15)
            && this->field_36A_zone_x >= pZone->field_1_x
            && this->field_36B_zone_y >= pZone->field_2_y
            && this->field_36A_zone_x < pZone->field_1_x + pZone->field_3_w
            && this->field_36B_zone_y < pZone->field_2_y + pZone->field_4_h)
        {
            break;
        }
        if (++this->field_364_cur_zone_idx >= *(WORD *)this->field_32C_pZones)
        {
            return 0;
        }
    }
    return pZone;
}

// match
gmp_map_zone* Map_0x370::get_zone_4DFB30(unsigned __int16 zone_idx)
{
    return field_32C_pZones[zone_idx + 1];
}
