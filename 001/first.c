#include <stdio.h>

#define check_usage(A, M, ...) if(!(A)) { printf(M "\n", ##__VA_ARGS__); goto error; }

int main(int argc, char *argv[])
{
    unsigned int end, i;
    long unsigned int result;

    check_usage(argc >= 2, "Usage: %s <end>", argv[0]);

    end = atoi(argv[1]);

    check_usage(end > 0, "End has to be bigger than zero");

    result = 0;

    for (i = 0; i < end; i++) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            result += i;
        }
    }

    printf("The sum of all the multiples of 3 or 5 below %d is:\n", end);
    printf("Sum: %ld\n", result);

    return 0;
    error:

    return 255;
}
