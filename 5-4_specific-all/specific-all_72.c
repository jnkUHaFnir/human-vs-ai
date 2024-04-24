#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *var = "variable";
    char *foo = "foo";
    char *bar = "bar";

    // Calculate the length needed for the concatenated string
    // Adding extra space for "TEXT " and " TEXT " and null terminator
    int total_length = strlen("TEXT ") + strlen(var) + 1;
    char *message = (char *)malloc(total_length * sizeof(char));

    // Concatenate the strings using snprintf
    snprintf(message, total_length, "TEXT %s", var);

    printf("Concatenated message: %s\n", message);

    // Free the allocated memory
    free(message);

    // Concatenate multiple strings
    total_length = strlen("TEXT ") + strlen(foo) + strlen(" TEXT ") + strlen(bar) + 1;
    char *message2 = (char *)malloc(total_length * sizeof(char));

    // Concatenate multiple strings using snprintf
    snprintf(message2, total_length, "TEXT %s TEXT %s", foo, bar);

    printf("Concatenated message2: %s\n", message2);

    // Free the allocated memory
    free(message2);

    return 0;
}
