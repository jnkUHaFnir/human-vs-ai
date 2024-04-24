#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    const char* s = "This is a test";
    // Allocate more space for the new string (considering the replacement, +2 for "gho" - "te", +1 for '\0')
    char* newstring = malloc(strlen(s) + 2 + 1); // +3 in total, for the string "This is a ghost\0"

    if (newstring == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }

    int j = 0; // Index for newstring
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 't' && s[i+1] == 'e') { // When 'te' is found
            newstring[j++] = 'g'; // Replace with "gho"
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // Skip the next character in the original string, since it has been processed
        } else { // For all other characters
            newstring[j++] = s[i];
        }
    }

    newstring[j] = '\0'; // Don't forget to null-terminate the new string

    printf("%s\n", newstring);

    free(newstring); // Free the allocated memory once done

    return 0;
}
