#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *var = "VarString";
    char *foo = "FooString";
    char *bar = "BarString";

    // Calculate necessary length for message including null terminator
    int message_len = strlen("TEXT ") + strlen(var) + 1;
    char *message = malloc(message_len); // Allocate memory for message
    if (message != NULL) {
        strcpy(message, "TEXT "); // Initialize message with the first string
        strcat(message, var); // Concatenate var to message
        printf("%s\n", message);
        free(message); // Don't forget to free the allocated memory
    } else {
        // Handle malloc failure
    }

    // For message2, calculate necessary length including null terminator
    int message2_len = strlen("TEXT ") + strlen(foo) + strlen(" TEXT ") + strlen(bar) + 1;
    char *message2 = malloc(message2_len); // Allocate memory for message2
    if (message2 != NULL) {
        strcpy(message2, "TEXT "); // Initialize message2
        strcat(message2, foo); // Concatenate foo
        strcat(message2, " TEXT "); // Concatenate " TEXT "
        strcat(message2, bar); // Concatenate bar
        printf("%s\n", message2);
        free(message2); // Free the allocated memory
    } else {
        // Handle malloc failure
    }

    return 0;
}
