#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *directions[3];
    int i;

    for(i = 0; i < 3; i++) {
        directions[i] = (char *)malloc(100 * sizeof(char)); // Allocate memory for each string
        if (directions[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        scanf("%s", directions[i]); // Read input into allocated memory
    }

    for(i = 0; i < 3; i++) {
        printf("%s\n", directions[i]); // Print each string
        free(directions[i]); // Free the allocated memory for each string
    }

    return 0;
}
