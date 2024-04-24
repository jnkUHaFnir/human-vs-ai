#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* file;
} RAII_File;

RAII_File* create_RAII_File(const char* filename, const char* mode) {
    RAII_File* raii_file = malloc(sizeof(RAII_File));
    if (raii_file) {
        raii_file->file = fopen(filename, mode);
        if (!raii_file->file) {
            free(raii_file);
            return NULL;
        }
    }
    return raii_file;
}

void destroy_RAII_File(RAII_File* raii_file) {
    if (raii_file) {
        fclose(raii_file->file);
        free(raii_file);
    }
}

int main() {
    RAII_File* raii_file = create_RAII_File("test.txt", "r");
    if (!raii_file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // Use the file handle as needed

    destroy_RAII_File(raii_file);

    return EXIT_SUCCESS;
}
