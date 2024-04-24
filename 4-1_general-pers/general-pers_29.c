#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* file;
} FileRAII;

FileRAII openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    FileRAII raii = {file};
    return raii;
}

void closeFile(FileRAII* raii) {
    if (raii->file != NULL) {
        fclose(raii->file);
        raii->file = NULL;
    }
}

int main() {
    FileRAII file = openFile("test.txt", "r");
    
    if (other_condition) {
        perror("other error occurred!");
        closeFile(&file);
        return EXIT_FAILURE;
    }

    // File operations here

    closeFile(&file);

    return EXIT_SUCCESS;
}
