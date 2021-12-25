#include "fix16.hpp"

// match
Fix16& Fix16::FromInt_4369F0(int a2)
{
    mValue = a2 << 14;
    return *this;
}
