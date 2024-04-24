#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 16

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} StringBuilder;

void StringBuilder_init(StringBuilder *sb) {
    sb->data = (char *)malloc(INITIAL_CAPACITY * sizeof(char));
    sb->capacity = INITIAL_CAPACITY;
    sb->length = 0;
}

void StringBuilder_append(StringBuilder *sb, const char *str) {
    size_t str_len = strlen(str);
    if (sb->length + str_len + 1 > sb->capacity) {
        while (sb->length + str_len + 1 > sb->capacity) {
            sb->capacity *= 2;
        }
        sb->data = (char *)realloc(sb->data, sb->capacity * sizeof(char));
    }
    strcpy(sb->data + sb->length, str);
    sb->length += str_len;
}

void StringBuilder_free(StringBuilder *sb) {
    free(sb->data);
    sb->capacity = 0;
    sb->length = 0;
}

int main() {
    StringBuilder sb;
    StringBuilder_init(&sb);

    // Build string out of variable-length data
    for (int i = 0; i < 5; i++) {
        char buffer[10];
        sprintf(buffer, "%d ", i);
        StringBuilder_append(&sb, buffer);
    }

    // Some parts are conditional
    int freezeCount = 1;
    if (freezeCount < 0) {
        StringBuilder_append(&sb, "]");
    } else {
        StringBuilder_append(&sb, ")");
    }

    printf("%s\n", sb.data);

    StringBuilder_free(&sb);

    return 0;
}
