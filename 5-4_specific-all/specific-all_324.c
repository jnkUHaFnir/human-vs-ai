#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
    int x = 5; // Number of strings
    char** stringArray = (char**)malloc(x * sizeof(char*)); // Allocate memory for array of string pointers

    if (stringArray == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    for (int i = 0; i < x; i++) {
        stringArray[i] = (char*)malloc(MAX_LENGTH * sizeof(char)); // Allocate memory for each string
        if (stringArray[i] == NULL) {
            printf("Memory allocation failed");
            return 1;
        }
        strcpy(stringArray[i], "Hello"); // Example string assignment, you can modify as needed
    }

    // Use the stringArray...

    // Don't forget to free the allocated memory
    for (int i = 0; i < x; i++) {
        free(stringArray[i]);
    }
    free(stringArray);

    return 0;
}
