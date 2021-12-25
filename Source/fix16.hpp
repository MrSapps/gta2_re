#pragma once


struct Fix16
{
    Fix16() : mValue(0) { }

    Fix16& operator = (int value)
    {
        mValue = value;
        return *this;
    }

    float AsFloat() const
    {
        return mValue / 16384.0f;
    }

    Fix16& FromInt_4369F0(int a2);

public:
    int mValue;
};
