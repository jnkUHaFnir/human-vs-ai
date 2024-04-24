#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* file;
} RAII_File;

RAII_File open_file(const char* filename, const char* mode) {
    FILE* fp = fopen(filename, mode);
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    RAII_File raii_file = { .file = fp };
    return raii_file;
}

void close_file(RAII_File* raii_file) {
    if (raii_file->file != NULL) {
        fclose(raii_file->file);
        raii_file->file = NULL;
    }
}

int main() {
    RAII_File raii_fp = open_file("test.txt", "r");
    
    if (other_condition) {
        perror("other error occurred!");
        // Resource cleanup will be automatically managed when raii_fp goes out of scope
        return EXIT_FAILURE;
    }
    
    // Use the file handle as needed
    
    // File handle will be automatically closed when raii_fp goes out of scope

    return EXIT_SUCCESS;
}
