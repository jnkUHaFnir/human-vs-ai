#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *s = "This is a test";
    int length = strlen(s);
    char *newstring = (char *)malloc((length + 1) * sizeof(char)); // Allocate memory for new string and add space for null terminator

    if (newstring == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    int j = 0; // Index for newstring

    for (int i = 0; i < length; i++) {
        if (s[i] == 't' && s[i + 1] == 'e') {
            newstring[j++] = 'g';
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // Skip next character 'e'
        } else {
            newstring[j++] = s[i];
        }
    }

    newstring[j] = '\0'; // Null terminator

    printf("%s\n", newstring);

    free(newstring); // Free allocated memory

    return 0;
}
