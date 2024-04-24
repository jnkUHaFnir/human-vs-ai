#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    size_t len;
    size_t capacity;
} StringBuilder;

void sb_init(StringBuilder *sb, size_t initial_capacity) {
    sb->str = malloc(initial_capacity);
    if (sb->str == NULL) {
        // Handle allocation failure
        exit(1);
    }
    sb->str[0] = '\0';
    sb->len = 0;
    sb->capacity = initial_capacity;
}

void sb_append(StringBuilder *sb, const char *append_str) {
    size_t append_len = strlen(append_str);
    if (sb->len + append_len + 1 >= sb->capacity) {
        size_t new_capacity = sb->capacity;
        while (sb->len + append_len + 1 >= new_capacity) {
            new_capacity *= 2;
        }

        char *new_str = realloc(sb->str, new_capacity);
        if (new_str == NULL) {
            // Handle reallocation failure
            exit(1);
        }
        sb->str = new_str;
        sb->capacity = new_capacity;
    }

    // Append the new string
    memcpy(sb->str + sb->len, append_str, append_len);
    sb->len += append_len;
    sb->str[sb->len] = '\0';  // Ensure null-terminated
}

void sb_free(StringBuilder *sb) {
    free(sb->str);
    sb->str = NULL;
    sb->capacity = 0;
    sb->len = 0;
}

// Example of usage
int main() {
    int freezeCount = -1;
    StringBuilder sb;
    sb_init(&sb, 32);  // Start with a reasonable capacity.

    // ... build string out of variable-length data
    // for (SolObject object : this) {
    //   sb_append(&sb, object.toString());
    // }

    // ... some parts are conditional
    if (freezeCount < 0) sb_append(&sb, "]");
    else sb_append(&sb, ")");

    printf("%s\n", sb.str);

    sb_free(&sb);
    return 0;
}
