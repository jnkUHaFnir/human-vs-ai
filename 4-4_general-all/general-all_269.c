#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char **list = malloc(argc * sizeof(char*));
    int i;

    for(i = 0; i < argc; ++i) {
        list[i] = malloc(strlen(argv[i]) + 1);
        strcpy(list[i], argv[i]);
    }

    // Create an array of pointers (list_pointers) to hold the pointers from 'list'
    char **list_pointers = malloc((argc + 1) * sizeof(char*)); // +1 for NULL terminator

    for(i = 0; i < argc; ++i) {
        list_pointers[i] = list[i];
    }
    list_pointers[argc] = NULL; // NULL terminate the pointer array

    execv(list_pointers[0], list_pointers);

    // Free memory
    for(i = 0; i < argc; ++i) {
        free(list[i]);
    }
    free(list);
    free(list_pointers);

    return 0;
}
