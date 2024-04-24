#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char var[] = "VAR";
    char foo[] = "FOO";
    char bar[] = "BAR";

    char message[50]; // Allocate enough memory for the concatenated string
    strcpy(message, "TEXT "); // Start with the initial string
    strcat(message, var); // Concatenate var to the message

    char message2[100]; // Allocate enough memory for the concatenated string
    strcpy(message2, "TEXT "); // Start with the initial string
    strcat(message2, foo); // Concatenate foo to the message2
    strcat(message2, " TEXT "); // Concatenate " TEXT " to the message2
    strcat(message2, bar); // Concatenate bar to the message2

    printf("message: %s\n", message);
    printf("message2: %s\n", message2);

    return 0;
}
