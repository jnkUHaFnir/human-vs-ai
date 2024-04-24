#include <stdio.h>

int main() {
    int size;
    int iteration = 1;

    do {
        if (iteration > 1) {
            printf("Invalid size\n");
        }
        
        printf("Size of tower (0 <= x <= 23): ");
        scanf("%i", &size);

        iteration++;
    } while (size > 23 || size < 0);

    return 0;
}
