#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE_LIMIT 4294967296 // 4 GB

char* read_file_contents(const char* filename) {
    struct stat file_stat;
    FILE* file;
    char* buffer = NULL;

    if (stat(filename, &file_stat) != 0) {
        perror("Error getting file status");
        return NULL;
    }

    if (file_stat.st_size > MAX_FILE_SIZE_LIMIT) {
        fprintf(stderr, "File size exceeds limit\n");
        return NULL;
    }

    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    buffer = (char*)malloc(file_stat.st_size + 1); // +1 for null terminator
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    if (fread(buffer, 1, file_stat.st_size, file) != file_stat.st_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    buffer[file_stat.st_size] = '\0'; // null-terminate the buffer

    fclose(file);

    return buffer;
}

int main() {
    const char* filename = "example.txt";

    char* file_contents = read_file_contents(filename);
    if (file_contents != NULL) {
        // Perform comparisons and logging here

        // Don't forget to free the memory allocated for file_contents
        free(file_contents);
    }

    return 0;
}
