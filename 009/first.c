#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int_fast32_t a, b, c, aa, bb, cc, sum;

    sum = 1000;
    a = 2;
    b = 3;
    c = (sum - a - b);

    while (c > 0) {
        c = (sum - a - b);

        if (c < 1) {
            a += 1;
            b = a + 1;
            c = (sum - a - b);
        }

        aa = a * a;
        bb = b * b;
        cc = c * c;

        if ((aa+bb) == cc) {
            break;
        }

        b += 1;
    }

    if (c < 1) {
        printf("No triplet exists\n");
        return 0;
    }

    printf("Product: %" PRIiFAST32 "\n", a*b*c);

    printf("a,b,c: %" PRIiFAST32, a);
    printf(",%" PRIiFAST32, b);
    printf(",%" PRIiFAST32 "\n", c);


    return 0;
}


