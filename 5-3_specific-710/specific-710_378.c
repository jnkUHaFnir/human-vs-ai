#include <stdio.h>

int main() {
    int size;
    int iteration = 0;

    do {
        if (iteration > 0) {
            printf("Invalid size\n");
        }

        printf("Size of tower (0 <= x <= 23): ");
        scanf("%i", &size);

        iteration++;
    } while (size > 23 || size < 0);

    return 0;
}
