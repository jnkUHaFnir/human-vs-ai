#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenate_string(char **dest, const char *src) {
    if (!*dest) {
        *dest = malloc(strlen(src) + 1);
        strcpy(*dest, src);
    } else {
        *dest = realloc(*dest, strlen(*dest) + strlen(src) + 1);
        strcat(*dest, src);
    }
    return *dest;
}

int main() {
    char *result = NULL;

    // Example loop for concatenate strings
    for (int i = 0; i < 5; i++) {
        concatenate_string(&result, "Hello ");
    }

    printf("%s\n", result);
    free(result);

    return 0;
}
