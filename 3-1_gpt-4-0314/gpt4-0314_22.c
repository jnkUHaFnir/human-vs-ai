#include <stdio.h>
#include <stdlib.h>
int numStrings = x; // x is the number of strings you want in your array
int maxLength = 50; // Maximum length of each string, including null character
char **stringArray = (char**)malloc(numStrings * sizeof(char*));
if (stringArray == NULL) {
    printf("Error: Memory allocation failed.\n");
    exit(1);
}
for (int i = 0; i < numStrings; i++) {
    stringArray[i] = (char*)malloc(maxLength * sizeof(char));
    // Check if allocation was successful
    if (stringArray[i] == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numStrings = 10; // Example: Array of 10 strings
    int maxLength = 50; // Maximum length of each string, including null character
    char **stringArray;

    stringArray = (char**)malloc(numStrings * sizeof(char*));
    if (stringArray == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < numStrings; i++) {
        stringArray[i] = (char*)malloc(maxLength * sizeof(char));
        if (stringArray[i] == NULL) {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
    }

    // Your code to manipulate the string array
    // ...

    // Free the allocated memory
    for (int i = 0; i < numStrings; i++) {
        free(stringArray[i]);
    }
    free(stringArray);

    return 0;
}
