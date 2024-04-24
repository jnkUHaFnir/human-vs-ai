#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_last_three(char* mystr) {
    size_t len = strlen(mystr);
    if (len <= 3) {
        // If the original string is 3 characters or fewer, return an empty string
        char* empty_str = malloc(1);
        if (empty_str == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        empty_str[0] = '\0';
        return empty_str;
    }

    size_t new_len = len - 3;

    char* modified_str = malloc(new_len + 1);
    if (modified_str == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(modified_str, mystr, new_len);
    modified_str[new_len] = '\0'; // Null-terminate the new string

    return modified_str;
}

int main() {
    char *original_filename = "examplefile.txt";
    char *new_filename = remove_last_three(original_filename);

    printf("Original filename: %s\n", original_filename);
    printf("Modified filename: %s\n", new_filename);

    // Don't forget to free the memory allocated in remove_last_three
    free(new_filename);

    return 0;
}
