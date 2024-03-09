#include "stdio.h"

long getHighBit_32(long x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x - (x >> 1);
}

long divide_mod_poly_32(const long a, const long b)
{
// a mod b

    long c = a;

    while (getHighBit_32(c) >= getHighBit_32(b))
    {
        long d = b;
        while(getHighBit_32(c) > getHighBit_32(d))
        {
            d <<= 1;
        }
        c ^= d;
    }

    return c;
}

char get_poly_deg_32(long g)
{
    int deg = 0;
    long highA = 0;
    long highG = getHighBit_32(g);
    while (highG > 1)
    {
        deg ++;
        highG >>= 1;
    }
    return deg;
}