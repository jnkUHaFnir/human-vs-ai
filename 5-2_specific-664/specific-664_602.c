#include <stdio.h>
#include <stdlib.h>

void* emalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

int main(void) {
    #define SIZE 100
    char* username[100];
    int i;
    int p;

    /* Read words into array */
    for (i = 0; i < 100; i++) {
        username[i] = (char*)emalloc(SIZE * sizeof(char));
        if (scanf("%99s", username[i]) != 1) {
            fprintf(stderr, "Failed to read input\n");
            exit(1);
        }
    }

    /* Print out array */
    for (p = 0; p < 100; p++) {
        printf("%s\n", username[p]);
    }

    return 0;
}
