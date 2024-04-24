#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    if (/* other_condition */) {
        perror("Other error occurred!");
        fclose(fp);  // Make sure to close the file handle before returning
        return EXIT_FAILURE;
    }

    // Your file operations here

    fclose(fp);  // Close the file handle when done
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* file;
} FileHandle;

FileHandle* FileHandle_open(const char* filename, const char* mode) {
    FileHandle* fh = malloc(sizeof(FileHandle));
    if (fh == NULL) {
        return NULL; // Memory allocation failed
    }

    fh->file = fopen(filename, mode);
    if (fh->file == NULL) {
        free(fh); // Clean up
        return NULL; // File opening failed
    }

    return fh;
}

void FileHandle_close(FileHandle* fh) {
    if (fh != NULL) {
        if (fh->file != NULL) {
            fclose(fh->file);
        }
        free(fh);
    }
}

int main() {
    FileHandle* fh = FileHandle_open("test.txt", "r");
    if (fh == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // Use fh->file

    FileHandle_close(fh); // Always release the resource

    return EXIT_SUCCESS;
}
