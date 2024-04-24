#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE *file;
} RAII_File;

RAII_File open_file(const char *filename, const char *mode) {
    RAII_File raii_file;
    raii_file.file = fopen(filename, mode);
    if (raii_file.file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return raii_file;
}

void close_file(RAII_File *raii_file) {
    if (raii_file->file) {
        fclose(raii_file->file);
        raii_file->file = NULL; // Reset to NULL after closing
    }
}

int main() {
    RAII_File file_handle = open_file("test.txt", "r");
    
    // Other conditions
    if (other_condition) {
        perror("other error occurred!");
        close_file(&file_handle); // Ensure file handle is closed before returning
        return EXIT_FAILURE;
    }

    close_file(&file_handle); // Close file handle if everything is successful
    return EXIT_SUCCESS;
}
