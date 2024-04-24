#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    const char *s = "This is a test";
    int len = strlen(s);
    char *newstring = malloc(len + 1); // Allocate space for the new string and null terminator

    int j = 0; // Index for newstring

    for (int i = 0; i < len - 1; i++) {
        if (s[i] == 't' && s[i+1] == 'e') {
            newstring[j++] = 'g';
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // Skip the 'e' in the original string
        } else {
            newstring[j++] = s[i];
        }
    }

    // Copy the last character if it's not 'e'
    if (s[len - 1] != 'e') {
        newstring[j++] = s[len - 1];
    }

    newstring[j] = '\0'; // Add null terminator to end the string

    printf("%s\n", newstring);

    free(newstring); // Don't forget to free the allocated memory

    return 0;
}
