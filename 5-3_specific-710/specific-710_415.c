#include <string.h>
#include <stdlib.h>

char* remove_last_three_chars(const char* mystr) {
    size_t len = strlen(mystr);

    if (len <= 3) {
        // Handle case where the input string is too short
        return NULL;
    }

    char *tmp = malloc(len - 2);  // Allocate memory for the new string
    if (tmp == NULL) {
        // Handle case where malloc fails
        return NULL;
    }

    strncpy(tmp, mystr, len - 3);  // Copy all characters except the last three
    tmp[len - 3] = '\0';  // Add null terminator

    return tmp;
}

int main() {
    const char* filename = "example.txt";
    char* new_filename = remove_last_three_chars(filename);

    if (new_filename != NULL) {
        // Use new_filename
        printf("Original filename: %s\n", filename);
        printf("Modified filename: %s\n", new_filename);

        free(new_filename);  // Don't forget to free the memory when done
    }

    return 0;
}
