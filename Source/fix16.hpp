#pragma once

#include "types.hpp"

struct Fix16
{
    Fix16() : mValue(0) { }

    Fix16& operator = (int value)
    {
        mValue = value;
        return *this;
    }

    Fix16 operator-(const Fix16& in)
    {
        Fix16 t;
        t.mValue = mValue - in.mValue;
        return t;
    }

    float AsFloat() const
    {
        return mValue / 16384.0f;
    }

    inline int ToInt()
    {
        return mValue >> 14;
    }

    EXPORT Fix16& FromInt_4369F0(int a2);

public:
    int mValue;
};
