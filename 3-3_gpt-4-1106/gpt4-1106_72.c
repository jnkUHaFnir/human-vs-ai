#include <stdio.h>
#include <string.h>

int main() {
    const char *var = "some_variable_content";
    const char *foo = "foo_content";
    const char *bar = "bar_content";
    
    // Calculate the required buffer sizes including the null-terminator
    size_t messageSize = strlen("TEXT ") + strlen(var) + 1;
    size_t message2Size = strlen("TEXT ") + strlen(foo) + strlen(" TEXT ") + strlen(bar) + 1;
    
    // Allocate the buffers with the required size
    char message[messageSize];
    char message2[message2Size];
    
    // Initialize the buffers with the first string
    strcpy(message, "TEXT ");
    strcpy(message2, "TEXT ");
    
    // Concatenate the rest of the strings
    strcat(message, var);
    strcat(message2, foo);
    strcat(message2, " TEXT ");
    strcat(message2, bar);

    // Now you can use message and message2
    printf("Message 1: %s\n", message);
    printf("Message 2: %s\n", message2);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *var = "some_variable_content";
    const char *foo = "foo_content";
    const char *bar = "bar_content";
    
    // Allocate buffer dynamically
    size_t messageSize = strlen("TEXT ") + strlen(var) + 1;
    char *message = (char *)malloc(messageSize);
    
    size_t message2Size = strlen("TEXT ") + strlen(foo) + strlen(" TEXT ") + strlen(bar) + 1;
    char *message2 = (char *)malloc(message2Size);
    
    if (!message || !message2) {
        // Handle the error if malloc failed
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    
    // Initialize and concatenate strings
    strcpy(message, "TEXT ");
    strcat(message, var);
    
    strcpy(message2, "TEXT ");
    strcat(message2, foo);
    strcat(message2, " TEXT ");
    strcat(message2, bar);
    
    // Use the messages
    printf("Message 1: %s\n", message);
    printf("Message 2: %s\n", message2);
    
    // Free dynamically allocated memory
    free(message);
    free(message2);

    return 0;
}
