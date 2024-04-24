#include <stdlib.h>
#include <stdio.h>

void get(char **string){
    int size = 1;
    *string = malloc(size); // allocate memory
    char c;
    int i = 0;    

    while(1){
        c = getchar();
        if(c == '\n') break; // Checks for newline
        (*string)[i] = c;
        i++;
        *string = realloc(*string, ++size); // reallocates memory
    }

    (*string)[i] = '\0'; // null terminator
}

int main(){
    char *buff = NULL;

    printf("String: ");
    fflush(stdout); // ensure "String:" is printed before input is taken
    get(&buff); // pass the address of buff
    printf("%s\n", buff);

    free(buff); // don't forget to free the memory

    return 0;
}
