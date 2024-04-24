#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char* read_file_contents(const char* filename) {
    struct stat st;
    
    if (stat(filename, &st) != 0) {
        perror("Error reading file size");
        return NULL;
    }

    if (st.st_size > (4ULL * 1024 * 1024 * 1024)) {
        fprintf(stderr, "File size is too large to read into memory\n");
        return NULL;
    }

    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char* buffer = (char*)malloc(st.st_size + 1); // Allocate memory for file contents
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    size_t bytesRead = fread(buffer, 1, st.st_size, file); // Read file contents
    buffer[bytesRead] = '\0'; // Add null terminator at the end
    fclose(file);

    return buffer;
}

int main() {
    const char* filename = "example.txt";
    char* fileContents = read_file_contents(filename);
    if (fileContents) {
        // Perform operations with fileContents
        printf("File contents: %s\n", fileContents);
        
        // Free allocated memory after use
        free(fileContents);
    }

    return 0;
}
