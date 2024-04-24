#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    const char *s = "This is a test";
    char *newstring = malloc(strlen(s) + 1); // Allocate memory for new string

    int j = 0; // Index for new string

    for (int i = 0 ; s[i] != '\0' ; i++) {
        if (s[i] == 't' && s[i+1] == 'e') {
            newstring[j++] = 'g';
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // Skip the next character as it has been replaced
        }
        else {
            newstring[j++] = s[i]; // Copy character from original string to new string
        }
    }
    newstring[j] = '\0'; // Add NULL terminator to mark end of string

    printf("%s\n", newstring);

    free(newstring); // Free the dynamically allocated memory

    return 0;
}
