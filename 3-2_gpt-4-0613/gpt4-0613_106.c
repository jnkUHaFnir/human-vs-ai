#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* buffer;
    size_t length;
    size_t capacity;
} String_Builder;

String_Builder* string_builder_new() {
    // Initialize with some capacity of your choosing
    size_t initial_capacity = 100;
    String_Builder* sb = (String_Builder*)malloc(sizeof(String_Builder));
    sb->buffer = (char*)malloc(initial_capacity);
    sb->buffer[0] = '\0'; // Start with an empty string
    sb->length = 0;
    sb->capacity = initial_capacity;
    return sb;
}

void string_builder_append(String_Builder* sb, const char* str) {
    size_t str_len = strlen(str);
    // If necessary, expand capacity
    if (sb->length + str_len >= sb->capacity) {
        while (sb->length + str_len >= sb->capacity) {
            sb->capacity *= 2;
        }
        sb->buffer = (char*)realloc(sb->buffer, sb->capacity);
    }
    // Copy str into buffer at current length and update length
    memcpy(sb->buffer + sb->length, str, str_len);
    sb->length += str_len;
    sb->buffer[sb->length] = '\0'; // Ensure null termination
}

char* string_builder_to_string(String_Builder* sb) {
    // Optionally shrink buffer to fit
    sb->buffer = (char*)realloc(sb->buffer, sb->length + 1);
    sb->capacity = sb->length + 1;
    return sb->buffer;
}

void string_builder_free(String_Builder* sb) {
    free(sb->buffer);
    free(sb);
}

int main() {
    String_Builder* sb = string_builder_new();
    string_builder_append(sb, "Hello, ");
    string_builder_append(sb, "world!");
    char* result = string_builder_to_string(sb);
    printf("%s\n", result);
    free(result);
    string_builder_free(sb);

    return 0;
}
