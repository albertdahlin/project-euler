#include <stdio.h>

#define CHECK_E_USER(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

int main(int argc, char *argv[])
{
    unsigned long first, second, third, sumOfAllEven;
    long limit;

    CHECK_E_USER(argc == 2, "ERROR: Missing args");

    limit = atol(argv[1]);

    CHECK_E_USER(limit > 1, "ERROR: <limit> has to be above 1");

    first           = 1;
    second          = 1;
    third           = 0;
    sumOfAllEven    = 0;

    while (third < limit) {
        sumOfAllEven   += third;
        first           = second + third;
        second          = third + first;
        third           = first + second;
    }

    printf("The sum of all even fibonacci terms below %ld is:\n", limit);
    printf("%lu\n", sumOfAllEven);

    return 0;

    error:

    printf("Calculates the sum of all even fibonacci terms below <limit>.\n");
    printf("Usage: %s <limit>\n", argv[0]);

    return 255;
}
