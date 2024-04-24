#include <stdio.h>
#include <stdlib.h>

// RAII file handle struct
typedef struct {
    FILE* handle;
} RAII_FILE;

// RAII file handle constructor
RAII_FILE* open_file(const char* filename, const char* mode) {
    RAII_FILE* raii_file = (RAII_FILE*)malloc(sizeof(RAII_FILE));
    if (raii_file) {
        raii_file->handle = fopen(filename, mode);
        if (!raii_file->handle) {
            perror("Error opening file");
            free(raii_file);
            return NULL;
        }
    }
    return raii_file;
}

// RAII file handle destructor
void close_file(RAII_FILE* raii_file) {
    if (raii_file) {
        fclose(raii_file->handle);
        free(raii_file);
    }
}

// Example usage
int main() {
    RAII_FILE* raii_fp = open_file("test.txt", "r");
    if (!raii_fp) {
        // Handle error
        return EXIT_FAILURE;
    }

    // Other operations with file handle

    // Automatically closes file when raii_fp goes out of scope
    close_file(raii_fp);

    return EXIT_SUCCESS;
}
