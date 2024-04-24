#include <stdio.h>
#include <string.h>

int main() {
    char var[] = "variable";
    char foo[] = "foo";
    char bar[] = "bar";
    char message[100]; // Make sure the buffer is large enough to hold the concatenated string

    // Concatenate "TEXT " and var safely
    strcpy(message, "TEXT ");
    strncat(message, var, sizeof(message) - strlen(message) - 1);

    printf("Concatenated message: %s\n", message);

    // Another example for concatenating multiple strings
    char message2[100]; // Make sure the buffer is large enough

    snprintf(message2, sizeof(message2), "TEXT %s TEXT %s TEXT %s", foo, bar, var);

    printf("Concatenated message2: %s\n", message2);

    return 0;
}
