#include "poly_math.h"

long cyclic_coder_32(long g, long m)
{
    char r = get_poly_deg_32(g);
    long c = divide_mod_poly_32(m << r, g);
    long a = (m << r) ^ c;
    return a;
}