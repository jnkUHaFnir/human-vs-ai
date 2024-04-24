#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    const char *s = "This is a test";
    int length = strlen(s);
    char *newstring = malloc(length + 1); // +1 for null terminator

    int j = 0; // Index for the newstring

    for (int i = 0 ; i < length ; i++) {
        if (s[i] == 't' && s[i+1] == 'e') {
            newstring[j] = 'g';
            newstring[j+1] = 'h';
            newstring[j+2] = 'o';
            j += 3;
            i++; // Skip the next character 'e'
        } else {
            newstring[j] = s[i];
            j++;
        }
    }

    newstring[j] = '\0'; // Add null terminator to the end

    printf("%s\n", newstring);

    free(newstring);

    return 0;
}
