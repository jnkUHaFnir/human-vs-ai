#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* filePtr;
} RAII_File;

RAII_File* openFile(const char* filename, const char* mode) {
    FILE* filePtr = fopen(filename, mode);
    if (filePtr == NULL) {
        perror("Error opening file");
        return NULL;
    }

    RAII_File* raiiFile = (RAII_File*)malloc(sizeof(RAII_File));
    if (raiiFile == NULL) {
        fclose(filePtr);
        perror("Memory allocation failed");
        return NULL;
    }

    raiiFile->filePtr = filePtr;
    return raiiFile;
}

void closeFile(RAII_File* raiiFile) {
    if (raiiFile != NULL) {
        fclose(raiiFile->filePtr);
        free(raiiFile);
    }
}

int main() {
    RAII_File* raiiFile = openFile("test.txt", "r");
    if (raiiFile == NULL) {
        return EXIT_FAILURE;
    }

    if (other_condition) {
        // Handle other error as needed
        perror("other error occurred!");
        closeFile(raiiFile);
        return EXIT_FAILURE;
    }

    // Use the file handle as needed

    closeFile(raiiFile);
    return EXIT_SUCCESS;
}
