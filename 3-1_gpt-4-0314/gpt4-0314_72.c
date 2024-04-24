#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *var = "World!";
    char *foo = "How";
    char *bar = "are you?";

    // allocate memory for message
    char *message = (char *) malloc(strlen("TEXT ") + strlen(var) + 1);
    strcpy(message, "TEXT ");
    strcat(message, var);
    printf("%s\n", message);

    // allocate memory for message2
    char *message2 = (char *) malloc(strlen("TEXT ") + strlen(foo) + strlen(" TEXT ") + strlen(bar) + 1);
    strcpy(message2, "TEXT ");
    strcat(message2, foo);
    strcat(message2, " TEXT ");
    strcat(message2, bar);
    printf("%s\n", message2);

    // free allocated memory
    free(message);
    free(message2);

    return 0;
}
