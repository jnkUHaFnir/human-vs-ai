#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* fp;
} FileRAII;

FileRAII openFile(const char* filename, const char* mode) {
    FileRAII file;
    file.fp = fopen(filename, mode);
    if (file.fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

void closeFile(FileRAII file) {
    if (file.fp != NULL) {
        fclose(file.fp);
    }
}

void readFileContent(FileRAII file) {
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file.fp) != NULL) {
        printf("%s", buffer);
    }
}

int main() {
    FileRAII file = openFile("test.txt", "r");

    // Perform operations with the file
    if (other_condition) {
        perror("other error occurred!");
        return EXIT_FAILURE;
    }

    // Example: reading file content
    readFileContent(file);

    closeFile(file); // File handle is closed automatically when the FileRAII variable goes out of scope

    return EXIT_SUCCESS;
}
