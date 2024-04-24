#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *serverData[255];

int main() {
    int loop_index = 0;

    for (; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        // Allocate memory for the string "dataX" where X is the loop index
        serverData[loop_index] = (char*)malloc(10); // Allocate enough memory for "dataX\0"
        
        if (serverData[loop_index] == NULL) {
            fprintf(stderr, "Memory allocation failed");
            exit(1);
        }

        // Use snprintf instead of sprintf for safer string formatting
        snprintf(serverData[loop_index], 10, "%s%d", "data", loop_index);
    }

    // Test printing the elements
    for (int i = 0; i < sizeof(serverData) / sizeof(serverData[0]); i++) {
        printf("Element %d: %s\n", i, serverData[i]);
    }

    // Free allocated memory
    for (int i = 0; i < sizeof(serverData) / sizeof(serverData[0]); i++) {
        free(serverData[i]);
    }

    return 0;
}
