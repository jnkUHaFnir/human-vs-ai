#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256

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
        serverData[loop_index] = (char*)malloc(MAX_LENGTH * sizeof(char));
        if (serverData[loop_index] == NULL) {
            // Handle error, for example, exit the program
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        snprintf(serverData[loop_index], MAX_LENGTH, "%s%d", "data", loop_index);
    }

    // Print the data for verification
    for (loop_index = 0; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        printf("serverData[%d]: %s\n", loop_index, serverData[loop_index]);
    }

    // Free the allocated memory
    for (loop_index = 0; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        free(serverData[loop_index]);
    }

    return 0;
}
