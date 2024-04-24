#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char **str, char input, size_t *n) {
    // Calculate new size for string
    size_t newSize = (*n) + 1;
    
    // Reallocate memory for the string
    *str = realloc(*str, newSize + 1); // +1 for null terminator
    if (*str == NULL) {
        printf("Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Shift elements to the right
    for (size_t i = *n; i > 0; i--) {
        (*str)[i] = (*str)[i - 1];
    }

    // Insert new character at the beginning
    (*str)[0] = input;
    (*n)++;

    // Null terminate the string
    (*str)[*n] = '\0';
}

int main() {
    // Assume str is initialized and n is set before calling insert
    char *str;
    size_t n = 5;
    
    // Initialize str with some values
    str = malloc(n + 1); // +1 for null terminator
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(str, "datas");

    char input = 'a';
    insert(&str, input, &n);

    printf("Resulting string: %s\n", str);

    // Free memory
    free(str);

    return 0;
}
