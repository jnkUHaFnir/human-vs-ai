#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char *directions[3];
    int i;

    for(i = 0; i < 3; i++) {
        directions[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
        if (directions[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }
        scanf("%99s", directions[i]); // Read max of 99 characters to avoid buffer overflow
    }

    for(i = 0; i < 3; i++) {
        printf("%s\n", directions[i]);
    }

    for(i = 0; i < 3; i++) {
        free(directions[i]); // Free the allocated memory
    }

    return 0;
}
