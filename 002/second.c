#include <stdio.h>

#define check_usage(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

int main(int argc, char *argv[])
{
    unsigned long first, second, third, sumOfAllEven;
    unsigned int max;

    check_usage(argc == 2, "Usage: %s <max>", argv[0]);

    max = atoi(argv[1]);

    check_usage(max > 1, "Max has to be above 1");

    first           = 1;
    second          = 1;
    third           = 0;
    sumOfAllEven    = 0;

    while (third < max) {
        sumOfAllEven   += third;
        first           = second + third;
        second          = third + first;
        third           = first + second;
    }

    printf("The sum of all even fibonacci terms below %d is:\n", max);
    printf("%ld\n", sumOfAllEven);

    return 0;

    error:
    return 255;
}
