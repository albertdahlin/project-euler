#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

#define CHECK_E_USER(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

uint64_t getRidOfFactor(uint64_t input, uint64_t factor)
{
    if (input % factor == 0) {
        printf("%" PRIu64 "\n", factor);
        while (input % factor == 0) {
            input /= factor;
        }
    }

    return input;
}

int main(int argc, char *argv[])
{
    uint64_t input, factor, limit;
    CHECK_E_USER(argc == 2, "ERROR: missing args.");

    input = strtoull(argv[1], NULL, 10);

    CHECK_E_USER(input > 1, "<number> needs to be above 1");

    printf("Prime factors of %" PRIu64 " are:\n", input);

    factor  = 2;
    input   = getRidOfFactor(input, factor);

    limit   = (uint64_t) sqrt(input);
    factor  = 3;

    while (factor <= limit) {
        if (input % factor == 0) {
            input = getRidOfFactor(input, factor);
        }
        factor += 2;
    }

    if (input > 1) {
        printf("%" PRIu64 "\n", input);
    }

    return 0;

    error:

    printf("Calculates all prime factors of a number.\n");
    printf("Usage: %s <number>\n", argv[0]);

    return 255;
}
