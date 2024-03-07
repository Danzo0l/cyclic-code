#include "poly_math.h"

long cyclic_default_decoder_32(long g, long b, long* E)
{
    int r = get_poly_deg_32(g);
    *E = divide_mod_poly_32(b , g) != 0;

    return b >> r-1;
}