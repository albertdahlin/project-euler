#include <stdio.h>

#define CHECK_E_USER(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

unsigned long getSumUpTo(unsigned int max)
{
    unsigned long sum, multiplier, remider;

    multiplier  = max / 2;
    remider     = max % 2;

    sum = max * multiplier;
    sum += remider ? max : multiplier;

    return sum;
}

int main(int argc, char *argv[])
{
    long limit;
    unsigned long result;

    CHECK_E_USER(argc >= 2, "ERROR: missing args.");

    limit = atol(argv[1]);

    CHECK_E_USER(limit > 0, "ERROR: <limit> has to be above zero");

    limit -= 1;

    result  = 0;
    result += 3 * getSumUpTo(limit / 3);
    result += 5 * getSumUpTo(limit / 5);
    result -= 15 * getSumUpTo(limit / 15);

    printf("The sum of all the multiples of 3 or 5 below %ld is:\n", limit + 1);
    printf("Sum: %lu\n", result);

    return 0;

    error:
    printf("Calculates the sum of all numbers below a limit that are multiples of 3 or 5.\n");
    printf("Usage: %s <limit>\n", argv[0]);

    return 255;
}
