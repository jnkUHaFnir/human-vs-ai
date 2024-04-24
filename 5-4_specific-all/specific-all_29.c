#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* file_ptr;
} RAII_File;

RAII_File open_file(const char* filename, const char* mode) {
    RAII_File raii_file;
    raii_file.file_ptr = fopen(filename, mode);
    return raii_file;
}

void close_file(RAII_File* raii_file) {
    if (raii_file->file_ptr) {
        fclose(raii_file->file_ptr);
        raii_file->file_ptr = NULL;
    }
}

// Usage example
int main() {
    // Automatically close the file handle when it goes out of scope
    {
        RAII_File file = open_file("test.txt", "r");
        if (other_condition) {
            perror("other error occurred!");
            return EXIT_FAILURE;
        }
        // File operations go here
    }
    // File handle is automatically closed when 'file' goes out of scope

    return 0;
}
