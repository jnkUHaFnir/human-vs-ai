#include <stdio.h>
#include <stdlib.h> 

int main() {
    int i;
    char** t;
    
    // Allocate memory for array of char pointers
    t = (char**)malloc(100 * sizeof(char*));
    if (t == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    // Allocate memory for each string
    for (i = 0; i < 100; i++) {
        t[i] = (char*)malloc(16 * sizeof(char));
        if (t[i] == NULL) {
            printf("Memory allocation failed");
            return 1;
        }
    }

    // Don't forget to free the memory when you are done using it
    for (i = 0; i < 100; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}
