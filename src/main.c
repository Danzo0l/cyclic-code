#include <stdio.h>
#include "coder.h"
#include "decoder.h"

long G = 0b1101;
long M = 2;

int main()
{

    long E;
    long e = 0;

    for (int i = 0; i < 64; i++)
    {
        long a = cyclic_coder_32(G, M);
        printf("{\"m\" : %ld, \"a\" : %ld, ", M, a);
        e = i;
        printf("\"e\" : %ld, ", e);

        // Testing default decoder
        long b = cyclic_default_decoder_32(G, a^e, &E);
        printf("{\"m^\" : %ld, \"E\" = %ld}, ", b, E);

        // Testing alter decoder
        long b1 = cyclic_alter_decoder_32(G, a^e, &E);
        printf("{\"m^\" : %ld, \"E\" = %ld}", b1, E);

        printf("}\n");
    }

    return 0;
}