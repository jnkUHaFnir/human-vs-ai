#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* emalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

#define MAX_WORDS 100
#define MAX_WORD_SIZE 100

int main(void) {
    char* username[MAX_WORDS];
    int i = 0;

    for(i = 0; i < MAX_WORDS; i++) {
        username[i] = emalloc(MAX_WORD_SIZE * sizeof(char));

        if (scanf("%99s", username[i]) == EOF) {
            free(username[i]); // If nothing was read, free the last allocation
            break;
        }
    }

    int word_count = i; // store the number of words read

    // Print out array
    for (i = 0; i < word_count; i++) {
        printf("%s\n", username[i]);
        free(username[i]); // Don't forget to free the memory after use!
    }

    return 0;
}
