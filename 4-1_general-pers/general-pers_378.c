#include <stdio.h>

int main() {
    int size;
    int firstLoop = 1;

    do {
        if (!firstLoop) {
            printf("Invalid size\n");
        } else {
            firstLoop = 0;
        }

        printf("Size of tower (0 <= x <= 23): ");
        scanf("%i", &size);

    } while (size > 23 || size < 0);

    return 0;
}
