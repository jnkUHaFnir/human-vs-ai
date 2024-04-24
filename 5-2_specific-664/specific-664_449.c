#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2) {
    size_t len = strlen(s1) + strlen(s2) + 1;
    char *result = (char *)malloc(len);
    if (result) {
        snprintf(result, len, "%s%s", s1, s2);
    }
    return result;
}

int main() {
    const char *var = "variable";
    const char *foo = "foo";
    const char *bar = "bar";

    char *message = concat("TEXT ", var);
    if (message) {
        printf("message: %s\n", message);
        free(message);
    }

    char *message2 = concat(concat("TEXT ", foo), concat(" TEXT ", bar));
    if (message2) {
        printf("message2: %s\n", message2);
        free(message2);
    }

    return 0;
}
