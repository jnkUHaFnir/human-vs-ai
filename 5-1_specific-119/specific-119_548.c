#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char *directions[3];
    char buffer[MAX_LENGTH];

    for (int i = 0; i < 3; i++) {
        directions[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
        if (directions[i] == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            return 1;
        }
        
        printf("Enter direction %d: ", i+1);
        fgets(buffer, MAX_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character if present
        
        strncpy(directions[i], buffer, MAX_LENGTH);
    }

    printf("Directions:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", directions[i]);
        free(directions[i]); // Free allocated memory
    }

    return 0;
}
