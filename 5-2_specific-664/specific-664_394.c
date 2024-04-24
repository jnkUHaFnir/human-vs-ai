#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 100

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} StringBuilder;

void StringBuilder_Init(StringBuilder *sb) {
    sb->data = (char *)malloc(sizeof(char) * INITIAL_CAPACITY);
    sb->length = 0;
    sb->capacity = INITIAL_CAPACITY;
    sb->data[0] = '\0';
}

void StringBuilder_Destroy(StringBuilder *sb) {
    free(sb->data);
}

void StringBuilder_Append(StringBuilder *sb, const char *str) {
    size_t str_len = strlen(str);
    size_t new_length = sb->length + str_len;

    if (new_length + 1 > sb->capacity) {
        while (new_length + 1 > sb->capacity) {
            sb->capacity *= 2;
        }
        sb->data = (char *)realloc(sb->data, sizeof(char) * sb->capacity);
    }

    strncat(sb->data, str, sb->capacity - sb->length);
    sb->length += str_len;
}

int main() {
    StringBuilder sb;
    StringBuilder_Init(&sb);

    for (int i = 0; i < 200000; i++) {
        char temp[12]; // Assuming a maximum of 12 characters for an integer
        snprintf(temp, sizeof(temp), "%d \n", i);
        StringBuilder_Append(&sb, temp);
    }

    char substr[56];
    memcpy(substr, sb.data, 56);
    substr[55] = '\0'; // Ensure null termination
    printf("%s", substr);

    StringBuilder_Destroy(&sb);

    return 0;
}
