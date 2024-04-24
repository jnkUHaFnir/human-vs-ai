#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* remove_last_3_chars(const char* mystr) {
    size_t len = strlen(mystr);
    char *result = (char*)malloc(len - 2); // allocate memory for the modified string
    
    if (result == NULL) {
        return NULL; // handle memory allocation failure
    }

    strncpy(result, mystr, len - 3); // copy the string without last 3 characters
    result[len - 3] = '\0'; // null-terminate the string
    
    return result;
}

int main() {
    const char* filename = "example.txt";
    char* new_filename = remove_last_3_chars(filename);
    
    if (new_filename != NULL) {
        printf("Original filename: %s\n", filename);
        printf("Modified filename: %s\n", new_filename);
        
        free(new_filename); // free allocated memory when done using it
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
