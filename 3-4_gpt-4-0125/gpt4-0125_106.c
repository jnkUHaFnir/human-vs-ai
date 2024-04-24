#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buffer;
    size_t length;
    size_t capacity;
} StringBuilder;

// Initialization function
StringBuilder* sb_init() {
    StringBuilder* sb = malloc(sizeof(StringBuilder));
    sb->capacity = 64; // initial capacity
    sb->length = 0;
    sb->buffer = malloc(sb->capacity * sizeof(char));
    sb->buffer[0] = '\0'; // Null-terminate the empty string
    return sb;
}

// Appending function
void sb_append(StringBuilder* sb, const char* str) {
    size_t str_len = strlen(str);
    size_t new_len = sb->length + str_len;
    if (new_len >= sb->capacity) {
        // Increase capacity
        sb->capacity = (new_len + 1) * 2;
        sb->buffer = realloc(sb->buffer, sb->capacity);
    }
    
    // Concatenate the new string
    strcat(sb->buffer, str);
    sb->length = new_len;
}

// Cleanup function
void sb_free(StringBuilder* sb) {
    free(sb->buffer);
    sb->buffer = NULL;
    free(sb);
}

int main(void) {
    StringBuilder* sb = sb_init();
    sb_append(sb, "Hello");
    sb_append(sb, ", ");
    sb_append(sb, "world!");
    printf("%s\n", sb->buffer); // Print the concatenated string
    sb_free(sb); // Free the resources
    
    return 0;
}
