#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Example variables
    char var[] = "variable";
    char foo[] = "foo_content";
    char bar[] = "bar_content";

    // Allocate memory for message
    char *message = (char *)malloc(strlen("TEXT ") + strlen(var) + 1);

    // Concatenate strings into message
    strcpy(message, "TEXT ");
    strcat(message, var);

    printf("%s\n", message); // Output: TEXT variable
    free(message);

    // Allocate memory for message2
    char *message2 = (char *)malloc(strlen("TEXT ") + strlen(foo) + strlen(" TEXT ") + strlen(bar) + 1);

    // Concatenate strings into message2
    strcpy(message2, "TEXT ");
    strcat(message2, foo);
    strcat(message2, " TEXT ");
    strcat(message2, bar);

    printf("%s\n", message2); // Output: TEXT foo_content TEXT bar_content
    free(message2);

    return 0;
}
