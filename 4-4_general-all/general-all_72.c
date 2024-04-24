#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *safeConcatenate(const char *s1, const char *s2) {
    // Calculate the total length of the concatenated string
    size_t totalLength = strlen(s1) + strlen(s2) + 1; // +1 for the null terminator

    // Allocate memory for the concatenated string
    char *result = (char *)malloc(totalLength);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Copy the first string into the result
    strcpy(result, s1);

    // Concatenate the second string to the result
    strncat(result, s2, totalLength - strlen(s1) - 1); // -1 to ensure space for null terminator

    return result;
}

int main() {
    const char *var = "variable";
    const char *foo = "foo";
    const char *bar = "bar";

    char *message = safeConcatenate("TEXT ", var);
    printf("message: %s\n", message);
    free(message); // Don't forget to free the allocated memory

    char *message2_temp = safeConcatenate("TEXT ", foo);
    char *message2 = safeConcatenate(message2_temp, " TEXT ");
    free(message2_temp); // Free the temporary result
    message2_temp = safeConcatenate(message2, bar);
    free(message2); // Free the previous result before reassigning
    message2 = message2_temp;
    printf("message2: %s\n", message2);
    free(message2); // Don't forget to free the allocated memory

    return 0;
}
