#include "poly_math.h"
#include "coder.h"

long cyclic_default_decoder_32(long g, long b, long* E)
{
    char r = get_poly_deg_32(g);
    *E = divide_mod_poly_32(b , g) != 0;

    return (b^g) >> r;
}

long cyclic_alter_decoder_32(long g, long b, long* E)
{
    char r = get_poly_deg_32(g);
    long res = cyclic_coder_32(g, b);
    *E = res % (1 << (r-1)) != b % (1 << (r-1));

    return (b^g) >> r;
}