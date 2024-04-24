#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *s = "This is a test";
    int len = strlen(s);
    char *newstring = (char *)malloc(len * 2); // Allocate memory for new string

    if (newstring == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int j = 0; // Index for the new string

    for (int i = 0; i < len - 1; i++) {
        if (s[i] == 't' && s[i+1] == 'e') {
            newstring[j++] = 'g';
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // Skip the next character 'e'
        }
        else {
            newstring[j++] = s[i];
        }
    }

    // Copy the last character if it's not part of "te"
    if (s[len - 1] != 't' || s[len - 2] != 'e') {
        newstring[j++] = s[len - 1];
    }

    newstring[j] = '\0'; // Null-terminate the new string

    printf("%s\n", newstring);

    free(newstring); // Free allocated memory

    return 0;
}
