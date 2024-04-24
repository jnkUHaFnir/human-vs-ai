//import necessary headers
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
        serverData[loop_index] = (char*)malloc(10); // allocate memory for the string
        sprintf(serverData[loop_index], "%s%d", "data", loop_index);
    }

    //Now you can use the serverData array as intended
    for (loop_index = 0; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        printf("%s\n", serverData[loop_index]);
    }

    //remember to free the allocated memory after you are done using it
    for (loop_index = 0; loop_index < sizeof(serverData) / sizeof(serverData[0]); loop_index++) {
        free(serverData[loop_index]);
    }

    return 0;
}
