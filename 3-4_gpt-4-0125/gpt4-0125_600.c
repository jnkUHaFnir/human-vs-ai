#include <stdio.h>
#include <stdlib.h>

//variable to hold server data 
char *serverData[255];

int main() {
    const char *base_string = "data";
    int loop_index;
    
    // Adjusted size calculation considering the number and null-terminator
    int numSize = 3; // Maximum three digits for the numbers; adjust if more are expected
    
    for (loop_index = 0; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        // Calculate the space needed: length of base string + space for number + null terminator
        int length = snprintf(NULL, 0, "%s%d", base_string, loop_index) + 1; // +1 for null terminator
        serverData[loop_index] = (char *)malloc(length); // Allocate memory for the string
        
        if(serverData[loop_index] != NULL) { // Check if the memory allocation was successful
            sprintf(serverData[loop_index], "%s%d", base_string, loop_index);
        } else {
            printf("Failed to allocate memory.\n");
            return 1; // Memory allocation failed, exit the program with error code
        }
    }

    // Optional: Print to verify
    for (loop_index = 0; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        printf("%s\n", serverData[loop_index]);
    }

    // Free the allocated memory
    for (loop_index = 0; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        free(serverData[loop_index]);
    }
    
    return 0;
}
