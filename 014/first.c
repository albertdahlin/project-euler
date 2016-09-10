#include <stdio.h>
#include <inttypes.h>

#define IS_EVEN(n) n % 2 == 0

uint64_t getCollatzCount(uint64_t number)
{
    uint64_t count = 1;

    while (number > 1) {
        if (IS_EVEN(number)) {
            number /= 2;
        } else {
            number = number *  3 + 1;
        }

        count += 1;
    }

    return count;
}

int main(int argc, uint8_t *argv[])
{
    uint64_t startingNumber, maxCount, maxCountNumber, count;

    startingNumber  = 1;
    maxCount        = 0;
    maxCountNumber  = 0;

    while (startingNumber <= 1000000) {
        count = getCollatzCount(startingNumber);

        if (count > maxCount) {
            maxCount        = count;
            maxCountNumber  = startingNumber;
        }
        startingNumber += 1;
    }

    printf("Starting Nuber %" PRIu64 " has a count of %" PRIu64 "\n", maxCountNumber, maxCount);

    return 0;
}
