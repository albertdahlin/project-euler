#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct MPnumber {
    uint64_t digitsCount;
    uint64_t bytesCount;
    uint8_t *digits;
} mp_number_t;

void multiply(mp_number_t *bignumber, uint8_t multiplier)
{
    uint16_t product;
    uint16_t carry;
    uint64_t i;

    carry = 0;

    for (i = 0; i < bignumber->digitsCount; i++) {
        product = bignumber->digits[i] * multiplier + carry;
        carry = product / 10;
        bignumber->digits[i] = product % 10;
    }

    while (carry > 0) {
        bignumber->digitsCount += 1;
        bignumber->digits[i] = carry % 10;
        carry /= 10;
        i += 1;
    }
}

void printBignumber(mp_number_t bignumber)
{
    uint64_t i;
    uint8_t digit;

    i = bignumber.digitsCount - 1;

    while (1) {
        digit = bignumber.digits[i];
        printf("%" PRIu8, digit);

        if (i == 0) {
            break;
        }
        i -= 1;
    }
}

int main(int argc, uint8_t *argv[])
{
    uint64_t sumOfDigits;
    uint64_t i;
    mp_number_t bignumber;
    bignumber.bytesCount = 256; // number of digits of 100! is less than 200
    bignumber.digits = calloc(1, bignumber.bytesCount);

    bignumber.digitsCount = 1;
    bignumber.digits[0] = 1;

    for (i = 100; i > 0; i--) {
        multiply(&bignumber, (uint8_t)i);
    }

    printf("100! = ");
    printBignumber(bignumber);
    printf("\n");

    sumOfDigits = 0;

    for (i = 0; i < bignumber.digitsCount; i++) {
        sumOfDigits += bignumber.digits[i];
    }

    printf("Sum of digits: %" PRIu64 "\n", sumOfDigits);

    free(bignumber.digits);

    return 0;
}
