#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(const char *string) {
    int i = strlen(string) - 1; // Start from the last valid index of the input string
    int j = 0;

    // Allocate memory for the temp string and copy the input string into it
    char* temp = (char*)malloc(strlen(string) + 1); // Allocate memory for the new string
    strcpy(temp, string); // Copy the input string into temp

    // Swapping characters to reverse the string
    while (j < i) {
        char tmp = temp[j];
        temp[j] = temp[i];
        temp[i] = tmp;
        j++;
        i--;
    }

    return temp;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1; // Returning error code 1 to indicate incorrect usage
    }

    char* reversedString = flip_string(argv[1]);
    printf("Reversed string: %s\n", reversedString);

    // Free the allocated memory
    free(reversedString);

    return 0;
}
