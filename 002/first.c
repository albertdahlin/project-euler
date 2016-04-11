#include <stdio.h>

#define CHECK_E_USER(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

int main(int argc, char *argv[])
{
    unsigned long previous, last, fibonacci, sumOfAllEven;
    long limit;

    CHECK_E_USER(argc == 2, "ERROR: Missing args");

    limit = atol(argv[1]);

    CHECK_E_USER(limit > 1, "ERROR: <limit> has to be above 1");

    last            = 1;
    previous        = 1;
    fibonacci       = 0;
    sumOfAllEven    = 0;

    while (fibonacci < limit) {
        if (fibonacci % 2 == 0) {
            sumOfAllEven += fibonacci;
        }

        fibonacci   = previous + last;
        last        = previous;
        previous    = fibonacci;
    }

    printf("The sum of all even fibonacci terms below %ld is:\n", limit);
    printf("%lu\n", sumOfAllEven);

    return 0;

    error:

    printf("Calculates the sum of all even fibonacci terms below <limit>.\n");
    printf("Usage: %s <limit>\n", argv[0]);

    return 255;
}
