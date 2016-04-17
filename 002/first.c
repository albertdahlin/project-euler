#include <stdio.h>
#include <inttypes.h>

#define CHECK_E_USER(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

int main(int argc, char *argv[])
{
    uint64_t previous, last, fibonacci, sumOfAllEven;
    uint_fast32_t limit;

    CHECK_E_USER(argc == 2, "ERROR: Missing args");

    limit = strtoul(argv[1], NULL, 10);

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

    printf("The sum of all even fibonacci terms below %" PRIuFAST32 " is:\n", limit);
    printf("%" PRIu64 "\n", sumOfAllEven);

    return 0;

    error:

    printf("Calculates the sum of all even fibonacci terms below <limit>.\n");
    printf("Usage: %s <limit>\n", argv[0]);

    return 255;
}
