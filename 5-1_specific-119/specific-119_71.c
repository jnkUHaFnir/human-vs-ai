#include <stdio.h>
#include <string.h>

int main() {
    char var[] = "variable";
    char foo[] = "foo";
    char bar[] = "bar";
    
    // Allocate memory for the concatenated strings
    char message[100]; // Adjust the size as needed
    char message2[100]; // Adjust the size as needed

    // Concatenate strings using snprintf
    snprintf(message, sizeof(message), "TEXT %s", var);
    snprintf(message2, sizeof(message2), "TEXT %s TEXT %s", foo, bar);

    // Print the concatenated strings
    printf("message: %s\n", message);
    printf("message2: %s\n", message2);

    return 0;
}
