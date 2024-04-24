#include <stdio.h>
#include <stdlib.h>

int main() {
    char *directions[3];

    for (int i = 0; i < 3; i++) {
        directions[i] = (char *)malloc(100 * sizeof(char)); // Allocating memory for each string
        if (directions[i] == NULL) {
            // Handle memory allocation failure
            printf("Memory allocation failed. Exiting...");
            return 1;
        }
        scanf("%99s", directions[i]); // Reading input into the allocated memory
    }

    for (int i = 0; i < 3; i++) {
        printf("%s\n", directions[i]); // Printing each string
        free(directions[i]); // Freeing the allocated memory
    }

    return 0;
}
