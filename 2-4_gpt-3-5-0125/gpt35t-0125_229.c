#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {

    char *s = "This is a test";
    char *newstring = (char *)malloc(strlen(s) + 1); // Allocate memory including space for null terminator

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 't' && s[i + 1] == 'e') {
            newstring[j++] = 'g';
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // Skip the next character ('e')
        } else {
            newstring[j++] = s[i];
        }
    }
    newstring[j] = '\0'; // Null-terminate the new string

    printf("%s\n", newstring);

    free(newstring); // Don't forget to free the allocated memory

    return 0;
}
