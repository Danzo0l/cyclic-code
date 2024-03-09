#include <stdio.h>
#include "coder.h"
#include "decoder.h"

long G = 0b1101;
long M = 0b1101;

int main()
{

//    printf("c = %ld\n", divide_mod_poly_32(M, G));

    long E;
    long e;
    printf("[\n");

    for (int i = 0; i < 32; i++)
    {
        printf("\t");

        long a = cyclic_coder_32(G, M);
        printf("{\"m\": %ld, \"a\": %ld, ", M, a);
        e = i;
        printf("\"e\": %ld, ", e);

        long b = a^e;
        printf("\"b\" : %ld, ", b);

        // Testing default decoder
        long d = cyclic_default_decoder_32(G, a^e, &E);
        printf("{\"m^\": %ld, \"E\": %ld}, ", d, E);

        // Testing alter decoder
        long d1 = cyclic_alter_decoder_32(G, a^e, &E);
        printf("{\"m^\": %ld, \"E\": %ld}", d1, E);

        printf("},\n");
    }
    printf("]\n");
    return 0;
}