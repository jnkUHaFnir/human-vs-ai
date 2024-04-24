#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char* read_file_contents(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    struct stat file_stat;
    if (fstat(fileno(file), &file_stat) != 0) {
        perror("Error getting file size");
        fclose(file);
        return NULL;
    }
    
    if (file_stat.st_size > (4 * 1024 * 1024 * 1024)) { // 4GB limit
        fprintf(stderr, "File size exceeds the limit of 4 GB\n");
        fclose(file);
        return NULL;
    }

    char* buffer = (char*)malloc(file_stat.st_size + 1); // +1 for null terminator
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, file_stat.st_size, file);
    buffer[bytes_read] = '\0'; // Null-terminate the string

    if (ferror(file) != 0) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return buffer;
}

int main() {
    const char* filename = "example.txt";
    char* file_contents = read_file_contents(filename);

    if (file_contents != NULL) {
        // Use file_contents for comparison or logging
        printf("File contents: %s\n", file_contents);

        free(file_contents);
    } else {
        // Handle error
        // Add appropriate error handling or logging here
    }

    return 0;
}
