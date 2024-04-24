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

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 't' && s[i+1] == 'e') {
            newstring[j++] = 'g';
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // Skip 'e' as we have already processed 'te'
        } else {
            newstring[j++] = s[i];
        }
    }
    newstring[j] = '\0'; // Null-terminate the new string

    printf("%s\n", newstring);

    free(newstring); // Free allocated memory

    return 0;
}
