#include <stdio.h>
#include <stdlib.h>

char* emalloc(int size) {
    char* ptr = calloc(size, sizeof(char));
    if(ptr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main(void) {
    #define SIZE 100
    char* username[SIZE];
    int i;
    
    /* Read words into array */
    for (i = 0; i < SIZE; i++) {
        username[i] = emalloc(SIZE);
        if (scanf("%99s", username[i]) != 1) {
            break;
        }
    }
    
    /* Print out array */
    for (int p = 0; p < i; p++) {
        printf("%s ", username[p]);
        free(username[p]); // Free allocated memory
    }

    return 0;
}
