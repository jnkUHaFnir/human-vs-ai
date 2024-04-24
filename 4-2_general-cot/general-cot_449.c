#include <stdio.h>
#include <string.h>

int main() {
    char var[] = "variable";
    char foo[] = "foo";
    char bar[] = "bar";
    
    char message[50]; // Make sure to allocate enough space to store the concatenated strings
    
    strcpy(message, "TEXT ");
    strcat(message, var);
    
    printf("Message: %s\n", message);
    
    char message2[50]; // Make sure to allocate enough space to store the concatenated strings
    
    strcpy(message2, "TEXT ");
    strcat(message2, foo);
    strcat(message2, " TEXT ");
    strcat(message2, bar);
    
    printf("Message2: %s\n", message2);
    
    return 0;
}
