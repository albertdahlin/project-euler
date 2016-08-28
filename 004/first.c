#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

uint8_t isPalindrome(uint64_t product)
{
    uint8_t  asString[7];
    uint8_t  asStringReversed[7];
    uint64_t reversedProduct;
    uint8_t end, c, i;

    sprintf(asString, "%" PRIu64, product);
    end = strlen(asString) - 1;

    for (i = 0; i <= end; i++) {
        asStringReversed[end - i] = asString[i];
    }

    reversedProduct = strtoull(asStringReversed, NULL, 10);

    return product == reversedProduct;
}

int main(int argc, char *argv[])
{
    uint64_t firstFactor  = 999;
    uint64_t secondFactor = 999;
    uint64_t product;
    uint64_t largestProduct = 0;
    uint64_t largestFactors[2] = {0};

    product = firstFactor * secondFactor;

    while (1) {
        if (secondFactor == 100) {
            if (firstFactor == 100) {
                break;
            }
            firstFactor -= 1;
            secondFactor = firstFactor;
        } else {
            secondFactor -= 1;
        }
        product = firstFactor * secondFactor;

        if (isPalindrome(product)) {
            if (product > largestProduct) {
                largestProduct = product;
                largestFactors[0] = firstFactor;
                largestFactors[1] = secondFactor;
            }
        }
    }

    printf("Largest palindrome product: %" PRIu64 "\n", largestProduct);
    printf("Factor 1: %" PRIu64 "\n", largestFactors[0]);
    printf("Factor 2: %" PRIu64 "\n", largestFactors[1]);

    return 0;
}
