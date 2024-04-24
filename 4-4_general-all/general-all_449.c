#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
    if (result == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

int main() {
    const char *var = "variable";
    const char *foo = "foo";
    const char *bar = "bar";

    char *message = concat("TEXT ", var);
    if (message == NULL) {
        // Handle concatenation failure
        return 1;
    }

    printf("Concatenated message: %s\n", message);
    free(message); // Don't forget to free the allocated memory

    char *message2 = concat(concat("TEXT ", foo), concat(" TEXT ", bar));
    if (message2 == NULL) {
        // Handle concatenation failure
        return 1;
    }

    printf("Concatenated message2: %s\n", message2);
    free(message2); // Don't forget to free the allocated memory

    return 0;
}
