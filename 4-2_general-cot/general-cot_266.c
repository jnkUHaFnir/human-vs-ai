#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    char** t;
    t = (char**)malloc(100 * sizeof(char*)); // Allocate memory for 100 pointers to chars

    for(i=0; i<100; i++) {
        t[i] = (char*)malloc(16 * sizeof(char)); // Allocate memory for 16 chars in each pointer
    }

    // Don't forget to free the memory allocated
    for(i=0; i<100; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}
