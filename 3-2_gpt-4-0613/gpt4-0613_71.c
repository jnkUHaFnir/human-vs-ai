#include <stdio.h>
#include <string.h>

int main() {
    char var[] = "some text";
    char foo[] = "foo";
    char bar[] = "bar";

    char message[100]; // Declare a large enough array to hold the result
    strcpy(message, "TEXT "); // Copy initial "TEXT " into message
    strcat(message, var); // Concatenate var to message

    char message2[100]; // Declare another large enough array for the second sentence
    strcpy(message2, "TEXT "); // Copy initial "TEXT " into message2
    strcat(message2, foo); // Concatenate foo to message2
    strcat(message2, " TEXT ");// Concatenate " TEXT " to message2
    strcat(message2, bar); // Concatenate bar to message2

    printf("Message: %s\n", message);
    printf("Message2: %s\n", message2);

    return 0;
}
