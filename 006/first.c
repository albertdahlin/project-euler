#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

uint64_t sumOfSquares(uint64_t number)
{
    uint64_t i, sum;

    for (i = 1; i <= number; i++) {
        sum += i * i;
    }

    return sum;
}

uint64_t squareOfSums(uint64_t number)
{
    uint64_t sum = number * (number + 1) / 2;

    return sum * sum;
}

int main(int argc, char *argv[])
{
    uint64_t number = 100;

    uint64_t sums = sumOfSquares(number);
    uint64_t squares = squareOfSums(number);

    printf("Sum of squares: %" PRIu64 "\n", sums);
    printf("Squares of sums: %" PRIu64 "\n", squares);
    printf("Difference: %" PRIu64 "\n", squares - sums);

    return 0;
}
