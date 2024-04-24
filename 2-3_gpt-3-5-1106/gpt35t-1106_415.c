#include <string.h>
#include <stdlib.h>

char* remove_last_three(char* mystr) {
    size_t length = strlen(mystr);
    if (length <= 3) {
        return NULL;  // String is too short to remove 3 characters
    }

    char* new_str = (char*)malloc(length - 2);  // Allocate memory for the new string
    if (new_str == NULL) {
        return NULL;  // Memory allocation failed
    }

    strncpy(new_str, mystr, length - 3);  // Copy all but the last 3 characters
    new_str[length - 3] = '\0';  // Add null terminator at the end

    return new_str;
}

int main() {
    char* original = "filename123";
    char* result = remove_last_three(original);
    if (result != NULL) {
        // Use the modified string
        printf("Modified string: %s\n", result);
        free(result);  // Free the memory allocated by remove_last_three
    } else {
        printf("Error: Unable to modify the string\n");
    }

    return 0;
}
