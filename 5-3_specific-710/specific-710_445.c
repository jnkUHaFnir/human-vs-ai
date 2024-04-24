#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Function to remove unwanted characters from a string
char* removeUnwantedChars(const char* input) {
    char* result = (char*)malloc(strlen(input) + 1); // Allocate memory for the result
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    regex_t regex;
    regcomp(&regex, "[^a-zA-Z0-9 ]", REG_EXTENDED); // Regular expression to only allow letters, numbers, and spaces

    size_t result_index = 0;
    regmatch_t match;
    while (*input) {
        if (regexec(&regex, input, 1, &match, 0) == 0) {
            size_t len = match.rm_so;
            if (len > 0) {
                strncpy(result + result_index, input, len); // Copy allowed characters
                result_index += len;
            }
            input += match.rm_eo; // Move to the next character after the match
        } else {
            result[result_index++] = *input++; // Copy allowed characters
        }
    }
    result[result_index] = '\0'; // Null-terminate the result

    regfree(&regex);

    return result;
}

int main() {
    const char* data = "Hello! This is 1234 some text\nwith extra characters";
    char* filtered_data = removeUnwantedChars(data);
    
    printf("Filtered data: %s\n", filtered_data);

    free(filtered_data); // Free allocated memory

    return 0;
}
