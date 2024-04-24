#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *s = "This is a test";
    char *newstring = malloc(strlen(s) + 1); // Allocate memory for the new string

    int new_index = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 't' && s[i + 1] == 'e') {
            newstring[new_index++] = 'g';
            newstring[new_index++] = 'h';
            newstring[new_index++] = 'o';
            i++; // Skip 'e' as it is already handled
        } else {
            newstring[new_index++] = s[i];
        }
    }
    newstring[new_index] = '\0'; // Null-terminate the new string

    printf("%s\n", newstring);

    free(newstring); // Free the allocated memory

    return 0;
}
