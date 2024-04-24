#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int isFileSizeAcceptable(const char* filePath) {
    struct stat st;
    
    if (stat(filePath, &st) == 0) {
        // Check if the size exceeds the threshold (e.g., 4GB for this example)
        if (st.st_size > (4LL * 1024 * 1024 * 1024)) {
            printf("File is too large.\n");
            return 0; // Not acceptable
        } else {
            return 1; // Acceptable
        }
    }
    perror("Could not determine file size");
    return -1; // Error
}
#define CHUNK_SIZE 1024 // Example chunk size; adjust based on your needs

void processFileInChunks(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    unsigned char buffer[CHUNK_SIZE]; // Adjust the buffer size according to your requirements
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(unsigned char), CHUNK_SIZE, file)) > 0) {
        // Process the chunk here (e.g., compare, log)
    }

    fclose(file);
}
