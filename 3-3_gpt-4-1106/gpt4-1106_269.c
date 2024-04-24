#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Allocate an array of pointers with an extra element for the NULL terminator
    char **list = malloc((argc + 1) * sizeof(char*));
    if (!list) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Copy argv into list
    for (int i = 0; i < argc; ++i) {
        list[i] = malloc(strlen(argv[i]) + 1);
        if (!list[i]) {
            perror("malloc");
            // In case of failure, free any previously allocated memory
            for (int j = 0; j < i; ++j) {
                free(list[j]);
            }
            free(list);
            exit(EXIT_FAILURE);
        }
        strcpy(list[i], argv[i]);
    }

    // NULL-terminate the array of pointers
    list[argc] = NULL;

    // Now you can pass 'list' to execv
    // The first argument of execv is the path to the executable
    // In this case, you are using argv[1] as the program to execute
    // so make sure that the actual program name is at argv[1]
    if (argc > 1) {
        execv(list[0], list);
        // If execv returns, there was an error
        perror("execv");
        exit(EXIT_FAILURE);
    }

    // If nothing was provided to execute, just free memory and exit
    for (int i = 0; i < argc; ++i) {
        free(list[i]);
    }
    free(list);
    
    return 0;
}
