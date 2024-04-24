#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char var[] = "var";
    char foo[] = "foo";
    char bar[] = "bar";

    char* message = malloc(strlen(var) + 6);  // Allocate memory for "TEXT " + var + null terminator
    strcpy(message, "TEXT ");
    strcat(message, var);
    
    printf("Message: %s\n", message);
  
    free(message);  // Don't forget to free the allocated memory

    char* message2 = malloc(strlen(foo) + strlen(bar) + 14);  // Allocate memory for "TEXT " + foo + " TEXT " + bar + null terminator
    strcpy(message2, "TEXT ");
    strcat(message2, foo);
    strcat(message2, " TEXT ");
    strcat(message2, bar);
    
    printf("Message2: %s\n", message2);

    free(message2);  // Don't forget to free the allocated memory

    return 0;
}
