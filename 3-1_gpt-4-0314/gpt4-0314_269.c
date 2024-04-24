#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char **list = malloc((argc+1)*sizeof(char*));
    int i=0;
    for(i=0;i<argc;++i){ // using argv for example...
        list[i] = malloc(strlen(argv[i])+1);
        strcpy(list[i], argv[i]);
    }
    list[argc] = NULL; // NULL-terminate the list

    // create from list an array of pointers
    execv(list[0], list);

    // If execv returns, an error occurred
    perror("execv");
    return 1;
}
