#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CHECK_E_USER(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

unsigned long getRidOfFactor(unsigned long input, unsigned long factor)
{
    if (input % factor == 0) {
        printf("%lu\n", factor);
        while (input % factor == 0) {
            input /= factor;
        }
    }

    return input;
}

int main(int argc, char *argv[])
{
    unsigned long input, factor, limit;
    CHECK_E_USER(argc == 2, "ERROR: missing args.");

    input = strtoul(argv[1], NULL, 10);

    CHECK_E_USER(input > 1, "<number> needs to be above 1");

    printf("Prime factors of %lu are:\n", input);

    factor  = 2;
    input   = getRidOfFactor(input, factor);

    limit   = (unsigned long) sqrt(input);
    factor  = 3;

    while (factor <= limit) {
        if (input % factor == 0) {
            input = getRidOfFactor(input, factor);
        }
        factor += 2;
    }

    if (input > 1) {
        printf("%lu\n", input);
    }

    return 0;

    error:

    printf("Calculates all prime factors of a number.\n");
    printf("Usage: %s <number>\n", argv[0]);

    return 255;
}
