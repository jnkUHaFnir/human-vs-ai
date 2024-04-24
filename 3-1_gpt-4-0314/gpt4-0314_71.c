#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char var[] = "World";
    char foo[] = "John";
    char bar[] = "Doe";

    // Allocate memory for message and message2
    char *message = (char *) malloc(strlen("TEXT ") + strlen(var) + 1); // +1 for null terminator
    char *message2 = (char *) malloc(strlen("TEXT ") + strlen(foo) + strlen(" TEXT ") + strlen(bar) + 1);

    if (message == NULL || message2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Concatenate the strings
    strcpy(message, "TEXT ");
    strcat(message, var);

    strcpy(message2, "TEXT ");
    strcat(message2, foo);
    strcat(message2, " TEXT ");
    strcat(message2, bar);

    printf("message: %s\n", message);
    printf("message2: %s\n", message2);

    // Free the allocated memory
    free(message);
    free(message2);

    return 0;
}
