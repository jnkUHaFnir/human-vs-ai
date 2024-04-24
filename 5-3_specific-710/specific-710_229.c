#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    const char *s = "This is a test";
    char *newstring = malloc(strlen(s) + 1); // Allocate memory for new string and +1 for null terminator
    size_t newstring_index = 0; // Index for new string

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 't' && s[i + 1] == 'e') {
            newstring[newstring_index++] = 'g';
            newstring[newstring_index++] = 'h';
            newstring[newstring_index++] = 'o';
            i++; // Skip one extra character as we have replaced "te" with "gho"
        } else {
            newstring[newstring_index++] = s[i];
        }
    }

    newstring[newstring_index] = '\0'; // Add null terminator to the end of the new string

    printf("%s\n", newstring);

    // Don't forget to free the allocated memory
    free(newstring);

    return 0;
}
