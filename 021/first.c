#include <stdio.h>
#include <inttypes.h>

uint64_t getSumOfDivisors(uint64_t number)
{
    uint64_t sum, n, limit;

    sum = 0;

    for (n = 1; n < number; n++) {
        if (number % n == 0) {
            sum += n;
        }
    }

    return sum;
}

int main(int argc, uint8_t *argv[])
{
    uint64_t i, divisorSum, sumOfAll;

    sumOfAll = 0;

    for (i = 1; i < 10000; i++) {
        divisorSum = getSumOfDivisors(i);

        if (divisorSum == i) {
            continue;
        }

        if (i == getSumOfDivisors(divisorSum)) {
            printf("%" PRIu64 ":%" PRIu64 "\n", i, divisorSum);
            sumOfAll += i;
        }
    }

    printf("Sum of all: %" PRIu64 "\n", sumOfAll);

    return 0;
}
