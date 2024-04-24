#include <stdio.h>

int main() {
    int size;
    do {
        // Only ask for the size on the first iteration or if the previous input was invalid.
        printf("Size of tower (0 <= x <= 23): ");
        scanf("%i", &size);
        
        if (size < 0 || size > 23) {
            // Print error message immediately after invalid input,
            // and before the next iteration of the loop.
            printf("Invalid size\n");
        }
    } while (size < 0 || size > 23);

    return 0;
}
