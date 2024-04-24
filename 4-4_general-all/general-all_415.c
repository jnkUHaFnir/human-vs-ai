#include <stdlib.h>
#include <string.h>

char* remove_last_three_characters(const char* mystr) {
    size_t len = strlen(mystr);
    
    if (len <= 3) { // handle case where input string is too short
        return NULL;
    }

    char* result = (char*)malloc(len - 2); // allocate memory for the modified string

    if (result == NULL) {
        return NULL; // allocation failed
    }

    strncpy(result, mystr, len - 3); // copy characters except the last three
    result[len - 3] = '\0'; // null-terminate the result string

    return result;
}

int main() {
    const char* filename = "example.txt";
    char* modifiedFilename = remove_last_three_characters(filename);

    if (modifiedFilename != NULL) {
        // Use the modified filename
        printf("Modified filename: %s\n", modifiedFilename);

        // Don't forget to free the allocated memory when done
        free(modifiedFilename);
    }

    return 0;
}
