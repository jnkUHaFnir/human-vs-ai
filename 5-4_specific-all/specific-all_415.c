#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_last_three_chars(const char* mystr) {
    size_t len = strlen(mystr);
    if (len <= 3) { // Input is too short to remove 3 characters
        return NULL;
    }

    char *tmp = (char*)malloc(len - 2); // Allocate memory for the modified string
    if (tmp == NULL) {
        return NULL; // Memory allocation failed
    }

    strncpy(tmp, mystr, len - 3); // Copy characters except the last 3
    tmp[len - 3] = '\0'; // Add null terminator at the end

    return tmp;
}

int main() {
    const char* input = "filename.txt";
    char* result = remove_last_three_chars(input);
    if (result != NULL) {
        printf("Modified string: %s\n", result);
        free(result); // Free the allocated memory after use
    } else {
        printf("Input string is too short to remove 3 characters\n");
    }

    return 0;
}
