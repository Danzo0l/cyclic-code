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
    long c = b;
    long d = a;

    while(getHighBit_32(d) > getHighBit_32(c))
    {
        c <<= 1;
        d ^= c;

        if (getHighBit_32(d) < getHighBit_32(b))
        {
            break;
        }
    }
    return d;
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