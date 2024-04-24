#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* file;
} RAII_File;

RAII_File* create_RAII_file(const char* filename, const char* mode) {
    RAII_File* raii_file = (RAII_File*)malloc(sizeof(RAII_File));
    if (raii_file != NULL) {
        raii_file->file = fopen(filename, mode);
        if (raii_file->file == NULL) {
            free(raii_file);
            return NULL;
        }
    }
    return raii_file;
}

void close_RAII_file(RAII_File* raii_file) {
    if (raii_file != NULL) {
        if (raii_file->file != NULL) {
            fclose(raii_file->file);
        }
        free(raii_file);
    }
}

int main() {
    RAII_File* raii_fp = create_RAII_file("test.txt", "r");
    if (raii_fp == NULL) {
        perror("File opening error");
        return EXIT_FAILURE;
    }

    if (other_condition) {
        perror("Other error occurred!");
        close_RAII_file(raii_fp);
        return EXIT_FAILURE;
    }

    // File processing code here

    close_RAII_file(raii_fp);

    return EXIT_SUCCESS;
}
