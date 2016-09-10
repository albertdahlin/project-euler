#include <stdio.h>
#include <math.h>
#include <inttypes.h>

uint64_t getRidOfFactor(uint64_t number, uint64_t factor, uint64_t *factorCount)
{
    uint_fast32_t exponent = 1;

    number /= factor;

    while (number % factor == 0) {
        // Count the number of times this factor appears.
        exponent += 1;
        number /= factor;
    }
    *factorCount *= exponent + 1;

    return number;
}

uint64_t getFactorCount(uint64_t number)
{
    uint64_t limit, factor, factorCount;

    limit       = (uint64_t) sqrt(number);
    factor      = 2;
    factorCount = 1;

    if (number % factor == 0) {
        number = getRidOfFactor(number, factor, &factorCount);
    }

    factor = 3;

    if (number % factor == 0) {
        number = getRidOfFactor(number, factor, &factorCount);
    }

    factor = 5;

    while (factor <= limit) {
        if (number % factor == 0) {
            number = getRidOfFactor(number, factor, &factorCount);
        }
        factor += 2;
        if (number % factor == 0) {
            number = getRidOfFactor(number, factor, &factorCount);
        }
        factor += 4;
    }

    if (number > 1) {
        factorCount *= 2;
    }

    return factorCount;
}

int main(int argc, char *argv[])
{
    uint64_t triangleNumber, n, factorCount;

    triangleNumber  = 0;
    n               = 1;
    factorCount     = 0;

    while (factorCount < 500) {
        triangleNumber  += n;
        n               += 1;
        factorCount     = getFactorCount(triangleNumber);
    }

    printf("%" PRIu64 "\n", triangleNumber);

    return 0;
}
