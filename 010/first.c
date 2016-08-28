#include <stdio.h>
#include <inttypes.h>
#include <math.h>

uint8_t isPrime(uint64_t number)
{
    uint64_t limit = ceil(sqrt(number));
    uint64_t i;

    if (number % 3 == 0) {
        return 0;
    }

    for (i = 5; i <= limit; i += 6) {
        if (
            number % i == 0
            || number % (i + 2) == 0
        ) {
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
    uint_fast32_t stop = 2000000;
    uint64_t sum = 2;
    uint64_t prime = 3;

    do {
        sum += prime;
        prime = findNextPrime(prime);
    } while (prime < stop);

    printf("Sum of all primes below %" PRIu64 " is %" PRIu64 "\n", stop, sum);

    return 0;
}
