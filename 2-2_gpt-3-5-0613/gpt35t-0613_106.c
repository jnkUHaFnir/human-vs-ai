#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate initial memory for the result string
    char* result = malloc(sizeof(char));
    result[0] = '\0'; // Initialize the result string

    // .. build string out of variable-length data
    // You need to replace this loop with your own logic
    char* objectToString = "someData"; // example object.toString()
    strcat(result, objectToString);

    // .. some parts are conditional
    int freezeCount = 0; // example freezeCount value
    char* delimiter = (freezeCount < 0) ? "]" : ")";
    strcat(result, delimiter);

    // Print the final result
    printf("Result: %s\n", result);

    // Free the allocated memory
    free(result);
    return 0;
}
