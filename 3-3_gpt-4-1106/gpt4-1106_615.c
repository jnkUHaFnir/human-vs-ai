#include <stdio.h>
#include <stdlib.h>

void ensureCapacity(char **string, int *capacity, int pos) {
    if (pos + 1 >= *capacity) {
        // Double the buffer size
        *capacity *= 2;
        char *temp = realloc(*string, *capacity * sizeof(char));

        if (temp == NULL) {
            free(*string);
            fprintf(stderr, "Error (re)allocating memory\n");
            exit(EXIT_FAILURE);
        }

        *string = temp;
    }
}

void readLine(char **string, int *capacity) {
    int c;
    int pos = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        ensureCapacity(string, capacity, pos);
        (*string)[pos++] = (char)c;
    }
    ensureCapacity(string, capacity, pos);
    (*string)[pos] = '\0'; // Null-terminate the string
}

int main() {
    int capacity = 1; // Start with a small capacity
    char *word = malloc(capacity * sizeof(char));
    if (word == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return EXIT_FAILURE;
    }

    readLine(&word, &capacity);
    printf("word=%s\n", word);

    free(word); // Don't forget to free the allocated memory!
    return EXIT_SUCCESS;
}
