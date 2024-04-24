#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* result = (char*)malloc(1); // Allocate memory for empty string
    result[0] = '\0'; // Null-terminate the string

    // .. build string out of variable-length data
    char str[20]; // example variable-length data
    sprintf(str, "%d", 42); // example conversion of int to string
    result = (char*)realloc(result, strlen(result) + strlen(str) + 1); // Allocate memory for new string
    strcat(result, str); // Concatenate the string

    // .. some parts are conditional
    int freezeCount = -1; // example conditional variable
    if (freezeCount < 0) {
        result = (char*)realloc(result, strlen(result) + 2); // Allocate memory for new brackets
        strcat(result, "]"); // Append closing bracket
    } else {
        result = (char*)realloc(result, strlen(result) + 2); // Allocate memory for new brackets
        strcat(result, ")"); // Append closing parenthesis
    }

    printf("Result: %s\n", result);

    free(result); // Free dynamically allocated memory

    return 0;
}
