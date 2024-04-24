#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// Function to read file contents into a character array
char* read_file_contents(const char* filename, size_t* file_size) {
    struct stat st;
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        return NULL;
    }

    if (stat(filename, &st) != 0) {
        fprintf(stderr, "Error getting file size.\n");
        fclose(file);
        return NULL;
    }

    if (st.st_size > SIZE_MAX) { // Check if file size exceeds SIZE_MAX
        fprintf(stderr, "File size is too large.\n");
        fclose(file);
        return NULL;
    }

    *file_size = (size_t)st.st_size;
    char* buffer = (char*)malloc(*file_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    if (fread(buffer, 1, *file_size, file) != *file_size) {
        fprintf(stderr, "Error reading file.\n");
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return buffer;
}

int main() {
    size_t file_size;
    char* file_contents = read_file_contents("encrypted_file.txt", &file_size);
    if (file_contents) {
        // Process the file contents

        // Free the allocated memory when done
        free(file_contents);
    }

    return 0;
}
