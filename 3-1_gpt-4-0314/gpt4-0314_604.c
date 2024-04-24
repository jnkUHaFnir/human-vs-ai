#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace_substring(const char *source, const char *old_str, const char *new_str) {
    if (!source || !old_str || !new_str) return NULL;

    int count = 0;
    const char *tmp = source;

    while ((tmp = strstr(tmp, old_str))) {
        count++;
        tmp += strlen(old_str);
    }

    if (count == 0) return strdup(source);

    size_t buffer_len = strlen(source) + (count * (strlen(new_str) - strlen(old_str))) + 1;
    char *buffer = (char *)malloc(buffer_len * sizeof(char));
    if (!buffer) return NULL;
    
    char *current = buffer;
    tmp = source;

    while (count--) {
        char *ptr = strstr(tmp, old_str);
        size_t skip = ptr - tmp;

        strncpy(current, tmp, skip);
        current += skip;
        strncpy(current, new_str, strlen(new_str));
        current += strlen(new_str);

        tmp = ptr + strlen(old_str);
    }
    
    strcpy(current, tmp);
    buffer[buffer_len - 1] = '\0';

    return buffer;
}

int main() {
    const char *source = "Hello World. We are in the beautiful world.";
    const char *old_str = "World";
    const char *new_str = "Earth";

    char *result = replace_substring(source, old_str, new_str);
    if (result) {
        printf("Original: %s\n", source);
        printf("Modified: %s\n", result);
        free(result);
    } else {
        printf("Failed to replace substring\n");
    }

    return 0;
}
