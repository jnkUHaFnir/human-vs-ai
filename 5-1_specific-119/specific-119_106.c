#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *result = malloc(1); // Allocate space for null terminator

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    result[0] = '\0'; // Ensure the initial string is null-terminated

    int freezeCount = 1; // Example condition

    // Loop to concatenate strings conditionally
    for (int i = 0; i < 5; i++) {
        char *str = NULL;

        // Example conditional string assignment
        if (freezeCount < 0) {
            str = strdup("]");
        } else {
            str = strdup(")");
        }

        // Perform concatenation
        char *temp = realloc(result, strlen(result) + strlen(str) + 1);

        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(result);
            free(str);
            return 1;
        }

        result = temp;
        strcat(result, str);

        free(str);
    }

    // Print the final concatenated string
    printf("%s\n", result);

    // Free the dynamically allocated memory
    free(result);

    return 0;
}
