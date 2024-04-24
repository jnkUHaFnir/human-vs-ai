#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE (4 * 1024 * 1024 * 1024) // 4 GB limit

char* readFileContents(const char* filename, size_t* fileSize) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size < 0) {
        fclose(file);
        perror("Error getting file size");
        return NULL;
    }

    // Check if file size exceeds limit
    if(size > MAX_FILE_SIZE) {
        fclose(file);
        fprintf(stderr, "File size exceeds limit of 4GB\n");
        return NULL;
    }

    *fileSize = (size_t)size;

    // Allocate memory for file contents
    char* buffer = (char*)malloc(*fileSize);
    if (buffer == NULL) {
        fclose(file);
        perror("Error allocating memory");
        return NULL;
    }

    // Read file contents into buffer
    size_t bytesRead = fread(buffer, 1, *fileSize, file);

    if (bytesRead != *fileSize) {
        fclose(file);
        free(buffer);
        perror("Error reading file");
        return NULL;
    }

    fclose(file);
    return buffer;
}

int main() {
    const char* filename = "example.txt";
    size_t fileSize;
    char* fileContents = readFileContents(filename, &fileSize);

    if (fileContents != NULL) {
        // Use the fileContents array for comparison or other purposes

        // Don't forget to free the allocated memory when done
        free(fileContents);
    }

    return 0;
}
