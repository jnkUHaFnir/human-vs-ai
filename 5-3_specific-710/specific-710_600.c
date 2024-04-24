#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 255

int main() {
    char *serverData[MAX_DATA_SIZE];

    for (int i = 0; i < MAX_DATA_SIZE; i++) {
        // Allocate memory for the string "data" + number + null terminator
        serverData[i] = (char*)malloc(snprintf(NULL, 0, "data%d", i) + 1);
        if (serverData[i] == NULL) {
            // Handle allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        sprintf(serverData[i], "%s%d", "data", i);
    }

    // Test printing the serverData
    for (int i = 0; i < MAX_DATA_SIZE; i++) {
        printf("%s\n", serverData[i]);
    }

    // Free allocated memory
    for (int i = 0; i < MAX_DATA_SIZE; i++) {
        free(serverData[i]);
    }

    return 0;
}
