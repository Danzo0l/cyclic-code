#include <stdio.h>
#include "coder.h"
#include "decoder.h"

long G = 0b1101;
long M = 0b1010;

int main()
{
    long E;
    long a = cyclic_coder_32(G, M);
    printf("a = %ld\n", a);

    printf("m^ = %ld\n", cyclic_default_decoder_32(G, a, &E));
    printf("E = %ld\n", E);

    return 0;
}