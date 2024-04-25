#include "poly_math.h"
#include "coder.h"

long cyclic_default_decoder_32(long g, long b, long* E)
{
    char r = get_poly_deg_32(g);
    *E = divide_mod_poly_32(b , g) != 0;

    return b >> r;
}

long cyclic_alter_decoder_32(long g, long b, long* E)
{
    char r = get_poly_deg_32(g);
    long res = cyclic_coder_32(g, b >> r);
    *E = res % (1 << r) != b % (1 << r);
    return res >> r;
}