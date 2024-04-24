#include <stdio.h>

#define MAX_LEN 100

int main() {
    char message[MAX_LEN];
    char foo[] = "foo";
    char bar[] = "bar";

    snprintf(message, MAX_LEN, "TEXT %s", foo);
    printf("Message: %s\n", message);

    char message2[MAX_LEN * 2];
    snprintf(message2, sizeof(message2), "TEXT %s TEXT %s", foo, bar);
    printf("Message2: %s\n", message2);

    return 0;
}
