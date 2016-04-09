#include <stdio.h>

#define check_usage(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

int main(int argc, char *argv[])
{
    unsigned long previous, last, fibonacci, sumOfAllEven;
    unsigned int max;

    check_usage(argc == 2, "Usage: %s <max>", argv[0]);

    max = atoi(argv[1]);

    check_usage(max > 1, "Max has to be above 1");

    last            = 1;
    previous        = 1;
    fibonacci       = 0;
    sumOfAllEven    = 0;

    while (fibonacci < max) {
        if (fibonacci % 2 == 0) {
            sumOfAllEven += fibonacci;
        }

        fibonacci   = previous + last;
        last        = previous;
        previous    = fibonacci;
    }

    printf("The sum of all even fibonacci terms below %d is:\n", max);
    printf("%ld\n", sumOfAllEven);

    return 0;

    error:
    return 255;
}
