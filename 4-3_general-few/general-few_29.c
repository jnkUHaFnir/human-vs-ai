#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* fp;
} RAII_FILE;

RAII_FILE* create_raii_file(const char* filename, const char* mode) {
    RAII_FILE* raii_file = malloc(sizeof(RAII_FILE));
    if (raii_file) {
        raii_file->fp = fopen(filename, mode);
    }
    return raii_file;
}

void release_raii_file(RAII_FILE* raii_file) {
    if (raii_file) {
        if (raii_file->fp) {
            fclose(raii_file->fp);
        }
        free(raii_file);
    }
}

int main() {
    RAII_FILE* raii_fp = create_raii_file("test.txt", "r");
    if (!raii_fp || !raii_fp->fp) {
        perror("Failed to open file!");
        release_raii_file(raii_fp);
        return EXIT_FAILURE;
    }

    if (other_condition) {
        perror("other error occurred!");
        release_raii_file(raii_fp);
        return EXIT_FAILURE;
    }

    // Use the file handle

    release_raii_file(raii_fp);
    return EXIT_SUCCESS;
}
