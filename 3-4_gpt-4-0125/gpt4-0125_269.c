int execv(const char *path, char *const argv[]);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Allocate memory for list, with an extra slot for the NULL terminator.
    char **list = malloc((argc + 1) * sizeof(char*));
    int i;
    for(i = 0; i < argc; ++i){ // Copy argv.
        list[i] = malloc(strlen(argv[i]) + 1);
        strcpy(list[i], argv[i]);
    }
    // NULL terminate the list.
    list[argc] = NULL;

    // Assuming list[0] contains the path to the executable,
    // otherwise, you need to set it explicitly.
    // For execv, the first argument after the path to the binary 
    // can be the same as the path or another argument as required.
    if (execv(list[0], list) == -1) {
        perror("execv");
        // Free allocated memory if execv fails
        for(int j = 0; j < argc; ++j){
            free(list[j]); // free each string
        }
        free(list); // free the array
        exit(EXIT_FAILURE);
    }

    // Free memory (though if execv succeeds, this code won't be reached)
    for(i = 0; i < argc; ++i){
        free(list[i]);
    }
    free(list);

    return 0;
}
