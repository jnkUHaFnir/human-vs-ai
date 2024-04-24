#include <stdio.h>
#include <stdlib.h>

//variable to hold server data 
char *serverData[255];

//loop variable
int loop_index = 0;

//program entry
int main() {
    //initialize the serverData array elements with string "data" and
    //append number x to each element. i.e. x <= 255
    //use a for loop for the initialization
    for (; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        serverData[loop_index] = (char *)malloc(10); // Allocate memory for "dataX\0"
        if (serverData[loop_index] == NULL) {
            // Handle memory allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        snprintf(serverData[loop_index], 10, "%s%d", "data", loop_index); // Using snprintf to prevent buffer overflow
    }
    
    // Print the contents of the serverData array
    for (int i = 0; i < sizeof(serverData) / sizeof(serverData[0]); i++) {
        printf("%s\n", serverData[i]);
    }
    
    // Free allocated memory
    for (int i = 0; i < sizeof(serverData) / sizeof(serverData[0]); i++) {
        free(serverData[i]);
    }
    
    return 0;
}
