#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coder.h"
#include "decoder.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <mode> <g> <m>\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    long g = strtol(argv[2], NULL, 10);
    long m = strtol(argv[3], NULL, 10);
    long E;

    if (strcmp(mode, "-c") == 0) {
        long a = cyclic_coder_32(g, m);
        printf("%ld, %ld, %ld", g, m, a);
    } else if (strcmp(mode, "-d") == 0) {
        // Testing default decoder
        long d = cyclic_default_decoder_32(g, m, &E);
        printf("%ld, %ld", d, E);
    } else if (strcmp(mode, "-a") == 0) {
        // Testing alter decoder
        long d1 = cyclic_alter_decoder_32(g, m, &E);
        printf("%ld, %ld", d1, E);
    } else {
        printf("Invalid mode\n");
        return 1;
    }

    return 0;
}