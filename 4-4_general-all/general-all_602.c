#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* emalloc(size_t size) {
    char* p = malloc(size);
    if (!p) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

int main(void) {
    char* input = NULL;
    size_t input_size = 0;
    int word_count = 0;

    while (1) {
        char* word = emalloc(1); // Allocate memory for word, initial size 1
        int c;

        // Read characters until whitespace or EOF is encountered
        while ((c = getchar()) != ' ' && c != '\n' && c != EOF) {
            word[word_count++] = c;
            word = realloc(word, word_count + 1); // Resize word
        }

        if (word_count == 0) {
            free(word); // No word read, free memory and break
            break;
        }

        word[word_count] = '\0'; // Null-terminate the word
        word_count = 0; // Reset word_count for the next word

        // Allocate memory for input buffer and append the word
        input = realloc(input, input_size + strlen(word) + 1);
        strcpy(input + input_size, word);
        input_size += strlen(word);

        free(word); // Free memory for the individual word

        if (c == '\n' || c == EOF) {
            break; // Exit the loop if newline or EOF is encountered
        }

        input = realloc(input, input_size + 2); // Make space for the whitespace or newline
        input[input_size++] = ' '; // Add whitespace
        input[input_size] = '\0'; // Null-terminate the input
    }

    printf("%s\n", input); // Print out the concatenated input
    free(input); // Free memory for the concatenated input

    return 0;
}
