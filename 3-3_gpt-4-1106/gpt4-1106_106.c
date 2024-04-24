#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t capacity;
    size_t length;
} StringBuilder;

// Initialize a StringBuilder with a certain capacity
void sb_init(StringBuilder *sb, size_t capacity) {
    sb->data = malloc(capacity);
    if(sb->data == NULL) {
        // Handle allocation error
        exit(1);
    }
    sb->data[0] = '\0';
    sb->capacity = capacity;
    sb->length = 0;
}

// Increase the capacity of the StringBuilder
void sb_grow(StringBuilder *sb, size_t min_capacity) {
    size_t new_capacity = sb->capacity;
    while (new_capacity < min_capacity) {
        new_capacity *= 2; // Double the capacity
    }
    sb->data = realloc(sb->data, new_capacity);
    if (sb->data == NULL) {
        // Handle reallocation error
        exit(1);
    }
    sb->capacity = new_capacity;
}

// Append a string to the StringBuilder
void sb_append(StringBuilder *sb, const char *str) {
    size_t str_len = strlen(str);
    if(sb->length + str_len >= sb->capacity) {
        sb_grow(sb, sb->length + str_len + 1);
    }
    strcpy(sb->data + sb->length, str);
    sb->length += str_len;
}

// Free the memory used by a StringBuilder
void sb_free(StringBuilder *sb) {
    free(sb->data);
    sb->data = NULL;
    sb->capacity = 0;
    sb->length = 0;
}

int main() {
    StringBuilder result;
    sb_init(&result, 32); // Initialize with an estimated capacity

    // Use a hypothetical way to iterate over the elements
    for (size_t i = 0; i < object_count; i++) {
        sb_append(&result, object[i].toString());
        // Add more appends as needed based on logic
    }

    // Add conditional parts
    if (freezeCount < 0) {
        sb_append(&result, "]");
    } else {
        sb_append(&result, ")");
    }

    printf("Resulting string: %s\n", result.data);

    sb_free(&result);
    return 0;
}
