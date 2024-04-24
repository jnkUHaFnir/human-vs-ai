#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *s = "This is a test";
    char *newstring = malloc(strlen(s) + 1); // Allocate memory for new string

    if (newstring == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    int j = 0; // Index for newstring

    for (int i = 0 ; s[i] != '\0' ; i++) {
        if (s[i] == 't' && s[i+1] == 'e') {
            newstring[j++] = 'g'; // Append 'g' to newstring
            newstring[j++] = 'h'; // Append 'h' to newstring
            newstring[j++] = 'o'; // Append 'o' to newstring
            i++; // Skip 'e' as it has been replaced
        } else {
            newstring[j++] = s[i]; // Copy character from s to newstring
        }
    }

    newstring[j] = '\0'; // Add null terminator to newstring

    printf("%s\n", newstring);

    // Free dynamically allocated memory
    free(newstring);

    return 0;
}
