#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

uint8_t isEvenlyDevisible(uint64_t number)
{
    if (
        number % 20 != 0     // 5*2*2
        || number % 19 != 0
        || number % 18 != 0  // 3*3*2
        || number % 17 != 0
        || number % 16 != 0  // 2*2*2*2
        || number % 13 != 0
        || number % 11 != 0
        || number % 7 != 0
        || number % 3 != 0
    ) {
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    int i = 0;
    uint64_t number = 2;

    while (1) {
        if (isEvenlyDevisible(number)) {
            break;
        }
        number += 2;
    }

    printf("Largest number: %" PRIu64 "\n", number);

    return 0;
}
