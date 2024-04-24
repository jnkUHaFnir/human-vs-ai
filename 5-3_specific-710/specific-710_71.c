#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main() {
    const char *var = "123";
    const char *foo = "456";
    const char *bar = "789";

    char *message = concat("TEXT ", var);
    printf("%s\n", message);
    free(message); // Don't forget to free the dynamically allocated memory

    char *message2 = concat(concat("TEXT ", foo), concat(" TEXT ", bar));
    printf("%s\n", message2);
    free(message2); // Don't forget to free the dynamically allocated memory

    return 0;
}
