#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100 // Assuming a maximum length for each input string

int main() {
    char *directions[3];
    int i;

    for (i = 0; i < 3; i++) {
        directions[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
        if (directions[i] == NULL) {
            // Handle allocation failure here
            exit(1);
        }
        scanf("%99s", directions[i]); // Read at most 99 characters to avoid buffer overflow
    }

    for (i = 0; i < 3; i++) {
        printf("%s\n", directions[i]);
        free(directions[i]); // Free allocated memory
    }

    return 0;
}
