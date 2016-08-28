#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

uint8_t isPrime(uint64_t number)
{
    uint64_t limit = ceil(sqrt(number));
    uint64_t i;

    for (i = 3; i <= limit; i += 2) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

uint64_t findNextPrime(uint64_t prime)
{
    do {
        prime += 2;
    } while (!isPrime(prime));

    return prime;
}

int main(int argc, char *argv[])
{
    uint64_t i = 3;
    uint64_t prime = 3;
    printf("Prime number %d is %d\n", 1, 2);
    printf("Prime number %d is %d\n", 2, 3);

    for (i = 3; i <= 10001; i++) {
        prime = findNextPrime(prime);
        printf("Prime number %" PRIu64 " is %" PRIu64 "\n", i, prime);
    }

    return 0;
}
