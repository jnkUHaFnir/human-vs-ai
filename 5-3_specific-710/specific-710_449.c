#include <stdio.h>
#include <string.h>

int main() {
    char var[] = "variable";
    char foo[] = "foo_value";
    char bar[] = "bar_value";

    char message[50]; // Make sure this buffer is large enough to hold the concatenated string

    sprintf(message, "TEXT %s", var);
    printf("Message: %s\n", message);

    char message2[100]; // Make sure this buffer is large enough to hold the concatenated string

    sprintf(message2, "TEXT %s TEXT %s", foo, bar);
    printf("Message2: %s\n", message2);

    return 0;
}
