#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE (4 * 1024 * 1024 * 1024) // 4 GB threshold

char* read_file_contents(const char* filename, long* file_size) {
    struct stat st;
    if (stat(filename, &st) != 0) {
        perror("Error getting file status");
        return NULL;
    }

    *file_size = st.st_size;

    if (*file_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File size exceeds maximum limit\n");
        return NULL;
    }

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char* buffer = (char*)malloc(*file_size + 1);
    if (buffer == NULL) {
        fclose(file);
        perror("Error allocating memory");
        return NULL;
    }

    size_t read_size = fread(buffer, 1, *file_size, file);
    buffer[read_size] = '\0'; // Null-terminate the string

    fclose(file);

    return buffer;
}

int main() {
    const char* filename = "your_file.txt";
    long file_size;
    char* file_contents = read_file_contents(filename, &file_size);

    if (file_contents != NULL) {
        // Do operations with file_contents
        printf("Successfully read file contents: %s\n", file_contents);

        // Free allocated memory
        free(file_contents);
    }

    return 0;
}
