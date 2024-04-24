#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE 4294967296  // 4GB

char* readFileContents(const char *filename, size_t *size) {
    struct stat st;
    if (stat(filename, &st) != 0) {
        perror("Failed to get file stats");
        return NULL;
    }
    
    if (st.st_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File is too large. Maximum supported file size is 4GB.\n");
        return NULL;
    }
    
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    
    char *buffer = (char *)malloc(st.st_size);
    if (!buffer) {
        perror("Failed to allocate memory for file contents");
        fclose(file);
        return NULL;
    }
    
    size_t bytesRead = fread(buffer, 1, st.st_size, file);
    if (bytesRead < st.st_size) {
        if (feof(file)) {
            fprintf(stderr, "Unexpected end of file.\n");
        } else if (ferror(file)) {
            perror("Error reading file");
        }
        free(buffer);
        fclose(file);
        return NULL;
    }
    
    *size = st.st_size;
    fclose(file);
    return buffer;
}

// Usage example
int main() {
    const char *filename = "yourfile.enc";
    size_t fileSize = 0;
    char *fileContents = readFileContents(filename, &fileSize);

    if (fileContents) {
        // Process the file contents...
        
        // Don't forget to free the memory when done!
        free(fileContents);
    }

    return 0;
}
