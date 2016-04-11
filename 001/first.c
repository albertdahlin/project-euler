#include <stdio.h>

#define CHECK_E_USER(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

int main(int argc, char *argv[])
{
    long limit;
    unsigned long result, i;

    CHECK_E_USER(argc >= 2, "ERROR: missing args.");

    limit = atol(argv[1]);

    CHECK_E_USER(limit > 0, "ERROR: <limit> has to be above than zero");

    result = 0;

    for (i = 0; i < limit; i++) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            result += i;
        }
    }

    printf("The sum of all the multiples of 3 or 5 below %ld is:\n", limit);
    printf("Sum: %lu\n", result);

    return 0;
    error:

    printf("Calculates the sum of all numbers below a limit that are multiples of 3 or 5.\n");
    printf("Usage: %s <limit>\n", argv[0]);

    return 255;
}
