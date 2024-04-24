#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a, *b, *c;
    size_t cnt;
} str_t;

void save(const str_t * const str, const char *name) {
    FILE* f;
    size_t i;
    char buffer[32];
    char *end_ptr;
    size_t total_length = 0;
    size_t buffer_size = 1024 * 1024 * 10; // 10MB buffer
    char *big_buffer = malloc(buffer_size);
    if (big_buffer == NULL) {
        // Handle memory allocation failure
        return;
    }

    if (str->cnt == 0) {
        free(big_buffer);
        return;
    }

    f = fopen(name, "w");
    if (f == NULL) {
        free(big_buffer);
        return;
    }

    char *current_ptr = big_buffer;
    for (i = 0; i < str->cnt; i++) {
        // This assumes the integers are not longer than 10 digits
        // Adapt buffer sizes if necessary based on your input range
        end_ptr = current_ptr;
        end_ptr += sprintf(end_ptr, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        total_length = (size_t)(end_ptr - current_ptr);
        current_ptr = end_ptr;

        // If the buffer is getting full, write to disk and reset pointers
        if (current_ptr >= big_buffer + buffer_size - 100) {
            fwrite(big_buffer, 1, total_length, f);
            current_ptr = big_buffer;
            total_length = 0;
        }
    }

    // Write any remaining data in the buffer to disk
    if (total_length > 0) {
        fwrite(big_buffer, 1, total_length, f);
    }

    fclose(f);
    free(big_buffer);
}

// The rest of your program...
