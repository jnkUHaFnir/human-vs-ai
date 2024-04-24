#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenate(const char* s1, const char* s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    
    char* result = malloc(len1 + len2 + 1);   // +1 for the null-terminator
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    strcpy(result, s1);
    strcpy(result + len1, s2);

    return result;
}

int main() {
    const char* var = "World";
    const char* foo = "Hello";
    const char* bar = "Concatenation";

    char* message = concatenate("TEXT ", var);
    printf("Message: %s\n", message);
    free(message);

    char* message2 = concatenate(concatenate("TEXT ", foo), concatenate(" TEXT ", bar));
    printf("Message2: %s\n", message2);
    free(message2);

    return 0;
}
