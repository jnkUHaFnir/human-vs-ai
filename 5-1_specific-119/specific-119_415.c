#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* remove_last_three_chars(const char* mystr) {
    size_t len = strlen(mystr);
    if (len <= 3) {
        // Handle error: input string is too short
        return NULL;
    }

    // Allocate memory for the new string
    char* new_str = (char*)malloc(len - 2); // 2 extra characters for null terminator

    if (new_str == NULL) {
        // Handle error: memory allocation failed
        return NULL;
    }

    // Copy characters except the last three and add null terminator
    strncpy(new_str, mystr, len - 3);
    new_str[len - 3] = '\0';

    return new_str;
}

int main() {
    const char* filename = "example.txt";
    char* modified_filename = remove_last_three_chars(filename);

    if (modified_filename != NULL) {
        printf("Modified filename: %s\n", modified_filename);
        free(modified_filename); // Don't forget to free the allocated memory
    } else {
        printf("Error modifying filename\n");
    }

    return 0;
}
