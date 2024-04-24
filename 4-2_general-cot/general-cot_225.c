#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* process_data(const char* data) {
    char* processed_data = (char*)malloc(strlen(data) + 1); // Allocate memory for processed data
    if (processed_data == NULL) {
        // Handle memory allocation error
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < strlen(data); i++) {
        if (isalnum(data[i]) || data[i] == ' ') {
            processed_data[j++] = data[i];
        }
    }
    processed_data[j] = '\0'; // Null terminate the string

    return processed_data;
}

int main() {
    const char* data = "Hello\n123 World!$#%"; // Example data with line breaks and special characters

    char* processed_data = process_data(data);

    if (processed_data != NULL) {
        printf("Processed data: %s\n", processed_data);
        free(processed_data); // Remember to free the allocated memory
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
