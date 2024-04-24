#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main() {
    const char *var = "VAR";
    const char *foo = "FOO";
    const char *bar = "BAR";
    
    char *message = concat("TEXT ", var);
    printf("Message: %s\n", message);
    free(message);
    
    char *message2 = concat(concat("TEXT ", foo), concat(" TEXT ", bar));
    printf("Message2: %s\n", message2);
    free(message2);
    
    return 0;
}
