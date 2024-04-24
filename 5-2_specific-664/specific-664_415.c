#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_last_three_chars(const char* mystr) {
    char* tmp = (char*)malloc(strlen(mystr) - 2); // Allocate memory for the new string
    if (tmp == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    strncpy(tmp, mystr, strlen(mystr) - 3); // Copy characters except the last 3
    tmp[strlen(mystr) - 3] = '\0'; // Add null terminator

    return tmp;
}

int main() {
    const char* original = "filename123";
    char* result = remove_last_three_chars(original);

    if (result != NULL) {
        printf("Original: %s\nModified: %s\n", original, result);
        free(result); // Free the allocated memory when done
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
