#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *result = (char *)malloc(1); // Allocate memory for an empty string
    result[0] = '\0'; // Ensure the string is null-terminated

    // Build string out of variable-length data
    // For demonstration purposes, I'm just using some sample objects
    char object[10];
    for (int i = 0; i < 5; i++) {
        sprintf(object, "%d", i); // Convert integer to string
        strcat(result, object); // Append object to result
    }

    // Some parts are conditional
    int freezeCount = -1;
    if (freezeCount < 0) {
        strcat(result, "]");
    } else {
        strcat(result, ")");
    }

    // Print the final result
    printf("%s\n", result);

    // Free memory allocated for the result
    free(result);

    return 0;
}
