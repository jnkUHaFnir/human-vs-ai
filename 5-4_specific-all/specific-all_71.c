#include <stdio.h>
#include <string.h>

int main() {
    char message[100]; // Make sure this buffer is large enough to hold the concatenated strings

    char var[] = "variable";
    snprintf(message, sizeof(message), "TEXT %s", var);
    printf("Concatenated message: %s\n", message);

    char foo[] = "foo";
    char bar[] = "bar";
    char message2[100]; // Make sure this buffer is large enough to hold the concatenated strings
    snprintf(message2, sizeof(message2), "TEXT %s TEXT %s", foo, bar);
    printf("Concatenated message 2: %s\n", message2);

    return 0;
}
