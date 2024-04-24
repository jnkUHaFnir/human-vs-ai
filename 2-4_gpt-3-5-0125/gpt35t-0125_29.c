#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* file;
} RAIIFile;

RAIIFile* openFile(const char* filename, const char* mode) {
    FILE* fp = fopen(filename, mode);
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    RAIIFile* raiiFile = (RAIIFile*)malloc(sizeof(RAIIFile));
    raiiFile->file = fp;
    
    return raiiFile;
}

void closeFile(RAIIFile* raiiFile) {
    if (raiiFile) {
        fclose(raiiFile->file);
        free(raiiFile);
    }
}

void readFile(RAIIFile* raiiFile) {
    if (!raiiFile) {
        return;
    }

    // Read from the file
    char buffer[100];
    while (fgets(buffer, 100, raiiFile->file)) {
        printf("%s", buffer);
    }
}

int main() {
    RAIIFile* raiiFile = openFile("test.txt", "r");
    if (!raiiFile) {
        return EXIT_FAILURE;
    }

    // Use the file
    readFile(raiiFile);

    // File will be closed automatically when raiiFile goes out of scope
    return EXIT_SUCCESS;
}
