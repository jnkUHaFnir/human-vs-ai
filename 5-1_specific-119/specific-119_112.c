#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE *fp;
} FileRAII;

FileRAII openFile(const char *filename, const char *mode) {
    FileRAII file;
    file.fp = fopen(filename, mode);
    return file;
}

void closeFile(FileRAII *file) {
    if (file->fp) {
        fclose(file->fp);
        file->fp = NULL;
    }
}

// Usage example
int main() {
    FileRAII file = openFile("test.txt", "r");
    
    if (other_condition) {
        perror("other error occurred!");
        closeFile(&file);
        return EXIT_FAILURE;
    }

    // File operations go here

    closeFile(&file);

    return EXIT_SUCCESS;
}
