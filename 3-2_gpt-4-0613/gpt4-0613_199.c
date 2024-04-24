#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int i;
    // Dynamically allocate enough space to hold all
    // command line options and arguments (plus spaces). 
    // Note: A more robust implementation would check 
    // each argument's length and dynamically resize 
    // the array as needed.
    char *args = malloc(argc * sizeof(char *));
    args[0] = '\0';  // Initialize string to empty

    for (i = 0; i < argc; i++) {
        strcat(args, argv[i]);  // Concatenate argument to string
        if (i < argc - 1){
            strcat(args, " ");  // Add a space between arguments 
        }
    }

    // Now args contains all the command line options and arguments as a single string.
    printf("Command line was: %s\n", args);

    free(args);  // Don't forget to free the space when you're done with it

    return 0;
}
