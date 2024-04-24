#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *directions[3];
    int i;

    for(i = 0; i < 3; i++) {
        directions[i] = malloc(100 * sizeof(char)); // Allocate memory for each string
        if(directions[i] == NULL) {
            // Handle allocation failure
            perror("Memory allocation failed");
            exit(1);
        }
        scanf("%99s", directions[i]); // Limit input to 99 characters to avoid buffer overflow
    }

    for(i = 0; i < 3; i++) {
        printf("%s\n", directions[i]);
        free(directions[i]); // Free the allocated memory after use
    }

    return 0;
}
