#include <stdio.h>
#include <string.h>

void Ex6() {
    char string[80]; // Changed from char* string[80] to char string[80]
    scanf("%79s", string); // Modified to fix potential buffer overflow issue

    char* newString = removeDup(string);
    puts(newString);

    // Free dynamically allocated memory
    free(newString);
}

char* removeDup(char *string) {
    int i, c = 0;
    char* newString = (char*)malloc(strlen(string) + 1); // Allocate memory for the new string

    for (i = 0; i < strlen(string) - 1; i++) { // Adjusted loop to avoid out of bounds access
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }

    newString[c++] = string[strlen(string) - 1]; // Add the last character to the new string
    newString[c] = '\0'; // Add null terminator to the end of the new string

    return newString;
}
