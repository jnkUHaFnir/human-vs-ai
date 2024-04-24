#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_last_3_chars(const char* mystr) {
    char* tmp = (char*)malloc(strlen(mystr) - 2); // Allocate memory for the modified string

    if (tmp == NULL) {
        return NULL; // Memory allocation failed
    }

    strncpy(tmp, mystr, strlen(mystr) - 3); // Copy characters excluding the last 3

    tmp[strlen(mystr) - 3] = '\0'; // Add terminating null character

    return tmp;
}

int main() {
    const char* input = "filename.txt";
    char* result = remove_last_3_chars(input);

    if (result != NULL) {
        printf("Modified string: %s\n", result);
        free(result); // Free dynamically allocated memory
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
