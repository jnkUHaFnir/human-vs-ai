#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    char var[] = "VARIABLE";
    char foo[] = "FOO";
    char bar[] = "BAR";

    snprintf(message, sizeof(message), "TEXT %s", var);
    printf("message: %s\n", message);

    snprintf(message, sizeof(message), "TEXT %s TEXT %s", foo, bar);
    printf("message2: %s\n", message);

    return 0;
}
