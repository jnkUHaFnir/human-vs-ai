#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

char* emalloc(size_t size) {
    char* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main(void) {
    char* username[SIZE]; 
    int i;

    /* Read words into array */
    for (i = 0; i < SIZE; i++) {
        username[i] = emalloc(SIZE * sizeof(char)); 
        if (fgets(username[i], SIZE, stdin) == NULL) {
            break;  // Exit loop when input ends
        }
    }

    /* Print out array */
    for (int p = 0; p < i; p++) {  // Use i instead of SIZE to print only valid entries
        printf("%s", username[p]);
    }

    /* Free memory */
    for (int p = 0; p < i; p++) {
        free(username[p]);
    }

    return 0;
}
