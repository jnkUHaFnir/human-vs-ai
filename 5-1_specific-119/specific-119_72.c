#include <stdio.h>

int main() {
    char message[100]; // Make sure to allocate enough space for the concatenated string

    char var[] = "variable";
    snprintf(message, sizeof(message), "TEXT %s", var);

    char foo[] = "foo";
    char bar[] = "bar";
    char message2[100]; // Make sure to allocate enough space for the concatenated string
    snprintf(message2, sizeof(message2), "TEXT %s TEXT %s", foo, bar);

    printf("message: %s\n", message);
    printf("message2: %s\n", message2);

    return 0;
}
