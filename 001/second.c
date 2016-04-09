#include <stdio.h>
#define check_usage(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

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
    unsigned int end;
    unsigned long result;

    check_usage(argc >= 2, "Usage: %s <end>", argv[0]);

    end = atoi(argv[1]) - 1;

    check_usage(end > 0, "End has to be bigger than zero");

    result  = 0;
    result += 3 * getSumUpTo(end / 3);
    result += 5 * getSumUpTo(end / 5);
    result -= 15 * getSumUpTo(end / 15);

    printf("The sum of all the multiples of 3 or 5 below %d is:\n", end + 1);
    printf("Sum: %ld\n", result);

    return 0;
    error:

    return 255;
}
