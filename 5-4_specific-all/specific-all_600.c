#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 255

int main() {
    char *serverData[MAX_SIZE];

    // Initialize each element of the serverData array
    for (int i = 0; i < MAX_SIZE; i++) {
        // Allocate memory for the string "data" + number + '\0'
        serverData[i] = (char *)malloc(50); // Allocate enough memory (e.g., 50 bytes) for your strings
        
        if (serverData[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        // Use snprintf to avoid buffer overflows
        snprintf(serverData[i], 50, "%s%d", "data", i);
    }

    // Printing the values to verify
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%s\n", serverData[i]);
    }

    // Don't forget to free the memory allocated
    for (int i = 0; i < MAX_SIZE; i++) {
        free(serverData[i]);
    }

    return 0;
}
