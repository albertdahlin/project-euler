#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define CHECK_MEM(P) if (P == NULL) {fprintf(stderr, "Memory error. %s:%d\n", __FILE__, __LINE__); goto error;}

typedef struct bigBcdNum {
    uint_fast32_t digitsCount;
    uint8_t *digits;
} bigBCDnum;

bigBCDnum *bigBCDpow(uint_fast16_t base, uint_fast16_t exp)
{
    uint_fast16_t carry, digit, product, n;
    bigBCDnum *number;

    number = malloc(sizeof(bigBCDnum));
    CHECK_MEM(number);

    number->digitsCount = 1;
    number->digits = calloc(1, exp);
    CHECK_MEM(number->digits);

    number->digits[0] = 1;
    carry = 0;

    while (exp > 0) {
        n = 0;
        while (n < number->digitsCount) {
            product     = number->digits[n] * base;
            digit       = product % 10 + carry;
            carry       = product / 10;

            number->digits[n] = (uint8_t)digit;

            if (n == (number->digitsCount - 1) && carry > 0) {
                number->digitsCount += 1;
            }
            n += 1;
        }

        exp -= 1;
    }

    return number;

    error:

    if (number && number->digits) {
        free(number->digits);
    }

    return NULL;
}

int main(int argc, uint8_t *argv[])
{
    uint_fast16_t sum, digitIdx;

    bigBCDnum *number = bigBCDpow(2, 1000);

    CHECK_MEM(number);

    sum         = 0;
    digitIdx    = number->digitsCount;

    printf("Number: ");

    do {
        digitIdx -= 1;
        sum += number->digits[digitIdx];
        printf("%" PRIu8, number->digits[digitIdx]);
    } while (digitIdx > 0);

    printf("\n");

    printf("Number of Digits: %" PRIuFAST32 "\n", number->digitsCount);
    printf("Sum of all Digits: %" PRIuFAST16 "\n", sum);

    free(number->digits);
    free(number);

    return 0;

    error:

    return 255;
}
