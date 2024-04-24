#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_last_three_characters(const char* mystr) {
    size_t len = strlen(mystr);
    if (len <= 3) {
        // If the string has less than or equal to three characters, return an empty string or handle as desired.
        return strdup("");
    }
    
    char* tmp = malloc(len - 2); // Allocate memory for the modified string
    strncpy(tmp, mystr, len - 3); // Copy all characters except the last three
    tmp[len - 3] = '\0'; // Null-terminate the string
    
    return tmp;
}

int main() {
    const char* filename = "testfile.txt";
    char* modified = remove_last_three_characters(filename);
    printf("Modified file name: %s\n", modified);
    
    free(modified); // Don't forget to free the dynamically allocated memory
    
    return 0;
}
