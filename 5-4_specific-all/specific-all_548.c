#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *directions[3];
    int i;

    for (i = 0; i < 3; i++) {
        directions[i] = (char *)malloc(100 * sizeof(char)); // Allocating memory for each string
        if (directions[i] == NULL) {
            // Handle memory allocation error
            return 1;
        }

        scanf("%99s", directions[i]); // Reading input with a limit to avoid buffer overflow
    }

    for (i = 0; i < 3; i++) {
        printf("%s\n", directions[i]);
        free(directions[i]); // Freeing allocated memory
    }

    return 0;
}
