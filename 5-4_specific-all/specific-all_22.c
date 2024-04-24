#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
    int numStrings = 5; // Number of strings
    char **arrayOfStrings = (char **)malloc(numStrings * sizeof(char *));

    if (arrayOfStrings == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < numStrings; i++) {
        arrayOfStrings[i] = (char *)malloc((MAX_LENGTH + 1) * sizeof(char)); // +1 for null terminator

        if (arrayOfStrings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }

        // You can now use arrayOfStrings[i] as a string
        strcpy(arrayOfStrings[i], "Example String");
    }

    // Don't forget to free the memory when you're done
    for (int i = 0; i < numStrings; i++) {
        free(arrayOfStrings[i]);
    }
    free(arrayOfStrings);

    return 0;
}
