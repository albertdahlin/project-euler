#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

typedef struct triangle {
    uint64_t count;
    uint64_t *numbers;
} triangle_t;
/**
 * n2 + n - 2a = 0
 * x = -.5 +- sqrt(.25 + 2 * a)
 *
 */
uint64_t getLevelsCount(uint64_t length)
{
    return -0.5 + sqrt(0.25 + length * 2);
}

triangle_t readNumbersFromFile()
{
    int number;
    uint64_t count = 0;
    FILE *data = fopen("p067_triangle.txt", "r");

    if (!data) {
        fprintf(stderr, "File not found\n");
        exit(-1);
    }

    while (!feof(data)) {
        fscanf(data, "%d", &number);
        if (feof(data)) {
            break;
        }
        count += 1;
    }

    triangle_t triangle;
    triangle.numbers = malloc(sizeof(uint64_t) * count);
    rewind(data);
    triangle.count = count;
    count = 0;

    while (!feof(data)) {
        fscanf(data, "%d", &number);
        if (feof(data)) {
            break;
        }
        triangle.numbers[count] = number;
        count += 1;
    }
    fclose(data);

    return triangle;
}

/**
 * Start from the bottom and summarize max path.
 *     3
 *    7 4
 *   2 4 6
 *  8 5 9 3
 */
int main(int argc, uint8_t *argv[])
{
    uint64_t length, levels, level, i, right, left, idx;

    triangle_t triangle = readNumbersFromFile();

    i = 0;
    length = triangle.count;
    levels = getLevelsCount(length);
    level  = levels;

    length -= level;
    level  -= 1;

    while (level > 0) {
        length -= level;
        for (i = 0; i < level; i++) {
            idx   = length + level + i;
            left  = triangle.numbers[idx];
            right = triangle.numbers[idx + 1];

            if (right > left) {
                triangle.numbers[length + i] += right;
            } else {
                triangle.numbers[length + i] += left;
            }
        }
        level -= 1;
    }

    free(triangle.numbers);
    printf("%" PRIu64 "\n", triangle.numbers[0]);

    return 0;
}
