#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char *s = "This is a test";
    char *newstring = malloc(strlen(s) + 1); // Allocate memory for the new string

    int j = 0; // Initialize a variable to keep track of the index in the newstring

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 't' && s[i + 1] == 'e') {
            newstring[j++] = 'g';
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // Skip the next character 'e'
        } else {
            newstring[j++] = s[i];
        }
    }

    newstring[j] = '\0'; // Add null terminator to the end of the new string

    printf("%s\n", newstring);

    free(newstring); // Free the memory allocated for newstring

    return 0;
}
