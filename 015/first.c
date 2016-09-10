#include <stdio.h>
#include <inttypes.h>

int main(int argc, uint8_t *argv[])
{
    uint64_t i, j, paths, x, y;

    paths   = 1;
    j       = 2;

    /**
     *  (x + y)!        40!
     * ---------- = -----------
     *  x! * y!      20! * 20!
     */
    for (i = 21; i <= 40; i++) {
        paths *= i;

        if (j <= 20 && paths % j == 0) {
            paths /= j;
            j++;
        }
    }

    printf("%" PRIu64 "\n", paths);

    return 0;
}
