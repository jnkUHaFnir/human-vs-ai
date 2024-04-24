#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the total length of all chunks combined
size_t calculate_total_length(char **chunks, int num_chunks) {
    size_t total_length = 0;
    for (int i = 0; i < num_chunks; i++) {
        total_length += strlen(chunks[i]);
    }
    return total_length;
}

int main() {
    int i;
    int number_of_chunks = 12;
    char **chunks = malloc(number_of_chunks * sizeof(char*));
    char *final_string = NULL;

    // Assuming you have an array of chunks to concatenate
    for (i = 0; i < number_of_chunks; i++) {
        chunks[i] = some_hash_table.pop(i);
    }

    // Calculate the total length needed for the final string
    size_t total_length = calculate_total_length(chunks, number_of_chunks);

    // Allocate memory for the final string
    final_string = malloc(total_length + 1); // Add 1 for the null terminator

    if (final_string == NULL) {
        // Handle memory allocation error
        perror("Error allocating memory");
        for (i = 0; i < number_of_chunks; i++) {
            free(chunks[i]);
        }
        free(chunks);
        return 1;
    }

    // Concatenate all chunks into the final string
    final_string[0] = '\0'; // Ensure final string is an empty string to start with
    for (i = 0; i < number_of_chunks; i++) {
        strcat(final_string, chunks[i]);
    }

    // Free memory for individual chunks
    for (i = 0; i < number_of_chunks; i++) {
        free(chunks[i]);
    }
    free(chunks);

    // Use the final_string as needed

    // Free memory for final_string when done using it
    free(final_string);

    return 0;
}
