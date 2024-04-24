#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *append_string(char *str, const char *substr) {
    size_t new_len = strlen(str) + strlen(substr) + 1;
    str = realloc(str, new_len);
    if (str) {
        strcat(str, substr);
        return str;
    } else {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

int main() {
    char *result = malloc(1);  // Starting with an initial empty string.
    result[0] = '\0';

    // Building the string with variable-length data
    if (/* some_condition */) {
        result = append_string(result, "some_string");
    }

    if (/* another_condition */) {
        result = append_string(result, "another_string");
    }

    printf("Resulting string: %s\n", result);
    free(result);
    return 0;
}
