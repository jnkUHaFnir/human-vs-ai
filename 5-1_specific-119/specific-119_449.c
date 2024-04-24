#include <stdio.h>
#include <string.h>

int main() {
    char message[100]; // Make sure this is large enough to hold the concatenated string
    char message2[100]; // Make sure this is large enough to hold the concatenated string

    char var[] = "variable";
    char foo[] = "foo";
    char bar[] = "bar";

    // Concatenate "TEXT " and var into message
    strcpy(message, "TEXT ");
    strncat(message, var, sizeof(message) - strlen(message) - 1); // -1 to leave space for null terminator

    // Concatenate "TEXT " and foo, then concatenate " TEXT " and bar into message2
    strcpy(message2, "TEXT ");
    strncat(message2, foo, sizeof(message2) - strlen(message2) - 1);
    strncat(message2, " TEXT ", sizeof(message2) - strlen(message2) - 1);
    strncat(message2, bar, sizeof(message2) - strlen(message2) - 1);

    printf("message: %s\n", message);
    printf("message2: %s\n", message2);

    return 0;
}
