#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define check_usage(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

unsigned long findOnePrimeFactor(unsigned long number)
{
    unsigned long factor = (unsigned long) sqrt(number);

    if (factor % 2 == 0) {
        factor -= 1;
    }

    while (factor > 2 && number % factor != 0) {
        factor -= 2;
    }

    if (factor <= 2) {
        return number;
    } else {
        return findOnePrimeFactor(factor);
    }
}

unsigned long getRidOfFactor(unsigned long input, unsigned long factor)
{
    if (input % factor == 0) {
        printf("%ld\n", factor);

        while (input % factor == 0) {
            input /= factor;
        }
    }

    return input;
}

int main(int argc, char *argv[])
{
    unsigned long input, factor;
    check_usage(argc == 2, "Usage: %s <number>", argv[0]);
    input   = strtoul(argv[1], NULL, 10);
    factor  = 2;
    input   = getRidOfFactor(input, factor);

    while (input > 1) {
        factor  = findOnePrimeFactor(input);
        input   = getRidOfFactor(input, factor);

        if (factor == input) {
            break;
        }
    }

    return 0;

    error:
    return 255;
}
