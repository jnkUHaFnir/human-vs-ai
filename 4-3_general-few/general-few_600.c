//import necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        serverData[loop_index] = (char*)malloc(sizeof(char) * 10); // Allocate memory for the string
        sprintf(serverData[loop_index], "%s%d", "data", loop_index); // No need for (char*) cast
    }

    // Print out the results for verification
    for (loop_index = 0; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        printf("%s\n", serverData[loop_index]);
    }

    // Free dynamically allocated memory
    for (loop_index = 0; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        free(serverData[loop_index]);
    }

    return 0;
}
