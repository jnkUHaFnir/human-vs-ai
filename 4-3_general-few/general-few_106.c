#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *result = NULL;
    size_t result_len = 0;

    // Iterate over your data
    for (int i = 0; i < 5; i++) {
        char str[20]; // Assuming fixed size for demonstration
        sprintf(str, "Data-%d", i);

        // Check your condition
        if (i % 2 == 0) {
            strcat(str, "[");
        } else {
            strcat(str, "]");
        }

        // Resize the result buffer
        size_t new_len = result_len + strlen(str);
        result = (char *)realloc(result, new_len + 1); // +1 for null terminator
        if (result == NULL) {
            // Handle allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        // Concatenate the new string to result
        strcat(result, str);
        result_len = new_len;
    }

    // Use the final result
    printf("Result: %s\n", result);

    // Free the dynamically allocated memory
    free(result);

    return 0;
}
