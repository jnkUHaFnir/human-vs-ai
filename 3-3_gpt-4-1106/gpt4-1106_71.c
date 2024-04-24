#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Your original variables
    char* var = "someVariable";
    char* foo = "fooVariable";
    char* bar = "barVariable";

    // Buffer for the first message
    char message[256]; // Make sure this is large enough to hold the result
    snprintf(message, sizeof(message), "TEXT %s", var); // Safely format the string

    // Buffer for the second message
    char message2[256]; // Again, ensure it's large enough to concatenate everything
    // Concatenate foo and bar into message2
    snprintf(message2, sizeof(message2), "TEXT %s TEXT %s", foo, bar);

    printf("%s\n", message);
    printf("%s\n", message2);

    return 0;
}
