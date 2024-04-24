#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

void* emalloc(size_t n) {
    void* ptr = malloc(n);
    if (ptr == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main(void) {
    char* words[MAX_WORDS];
    int i = 0;
    char tempWord[MAX_WORD_LENGTH];

    while (i < MAX_WORDS && scanf("%99s", tempWord) == 1) { // Read up to 99 chars + null terminator
        words[i] = emalloc(strlen(tempWord) + 1); // +1 for the null terminator
        strcpy(words[i], tempWord);
        i++;
    }

    // Printing all words read
    for (int p = 0; p < i; p++) {
        printf("%s\n", words[p]); // Added newline for readability
        free(words[p]); // Freeing each word's memory
    }

    return 0;
}
