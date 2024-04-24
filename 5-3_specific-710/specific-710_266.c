#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    char** t;
    t = (char**)malloc(100*sizeof(char*));

    for(i=0; i<100; i++) {
        t[i] = (char*)malloc(17*sizeof(char));
    }

    // Your code to use the dynamically allocated c-string table can go here

    // Don't forget to free the allocated memory
    for(i=0; i<100; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}
