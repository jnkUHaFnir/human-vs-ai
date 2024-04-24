#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* fp;
} RAIIFile;

RAIIFile* createRAIIFile(const char* filename, const char* mode) {
    RAIIFile* raiiFile = malloc(sizeof(RAIIFile));
    if (raiiFile != NULL) {
        raiiFile->fp = fopen(filename, mode);
    }
    return raiiFile;
}

void closeRAIIFile(RAIIFile* raiiFile) {
    if (raiiFile != NULL) {
        if (raiiFile->fp != NULL) {
            fclose(raiiFile->fp);
        }
        free(raiiFile);
    }
}

int main() {
    RAIIFile* raiiFile = createRAIIFile("test.txt", "r");
    if (raiiFile == NULL || raiiFile->fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Use the file pointer:
    // For example, read from the file
    // fread(...);

    closeRAIIFile(raiiFile);
    return EXIT_SUCCESS;
}
