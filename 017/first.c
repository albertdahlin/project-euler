#include <stdio.h>
#include <string.h>
#include <inttypes.h>

uint8_t *digits[20] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};
uint8_t *decades[10] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

uint64_t getLetterCount(uint64_t number)
{
    uint64_t thousands, hundreds, tenths, ones, letterCount;

    letterCount = 0;

    printf("%" PRIu64, number);

    thousands = number / 1000;
    number = number % 1000;

    hundreds = number / 100;
    number = number % 100;

    tenths = number / 10;
    number = number % 10;

    ones = number;

    if (thousands) {
        printf(" %s thousand", digits[thousands]);
        letterCount += 8 + strlen(digits[thousands]);
    }

    if (hundreds) {
        printf(" %s hundred", digits[hundreds]);
        letterCount += 7 + strlen(digits[hundreds]);
    }

    if ((thousands || hundreds) && (tenths || ones)) {
        printf(" and");
        letterCount += 3;
    }

    if (tenths >= 2) {
        printf(" %s", decades[tenths]);
        letterCount += strlen(decades[tenths]);
        if (ones) {
            printf("-%s", digits[ones]);
            letterCount += strlen(digits[ones]);
        }
    } else {
        if (tenths == 1) {
            ones = ones + 10;
        }
        if (ones) {
            printf(" %s", digits[ones]);
            letterCount += strlen(digits[ones]);
        }
    }

    printf(": %" PRIu64 "\n", letterCount);

    return letterCount;
}

int main(int argc, uint8_t *argv[])
{
    uint64_t i, totalCount;

    totalCount = 0;

    for (i = 1; i <= 1000; i++) {
        totalCount += getLetterCount(i);
    }

    printf("Total letter Count: %" PRIu64 "\n", totalCount);
    return 0;
}
