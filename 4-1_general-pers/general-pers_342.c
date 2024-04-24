#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    int number_of_chunks = 12;
    size_t total_length = 0;
    char *final_string = NULL;

    // Calculate the total length needed for the final string
    for (i = 0; i < number_of_chunks; i++) {
        char *chunk = some_hash_table.pop(i);
        total_length += strlen(chunk);
    }

    // Allocate memory for the final string
    final_string = (char *)malloc(total_length + 1);
    if (final_string == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    final_string[0] = '\0'; // Initialize the string as empty

    // Concatenate string chunks
    for (i = 0; i < number_of_chunks; i++) {
        char *chunk = some_hash_table.pop(i);
        strcat(final_string, chunk);
    }

    // Use the final_string as needed

    free(final_string);

    return 0;
}
