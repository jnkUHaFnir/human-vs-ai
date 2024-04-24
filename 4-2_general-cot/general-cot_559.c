#include <stdio.h>
#include <stdlib.h>

char* read_file_contents(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = (char*)malloc(file_size + 1);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    size_t result = fread(buffer, 1, file_size, file);
    if (result != file_size) {
        fprintf(stderr, "Error reading file\n");
        fclose(file);
        free(buffer);
        return NULL;
    }

    buffer[file_size] = '\0'; // Null-terminate the buffer

    fclose(file);
    return buffer;
}

int main() {
    const char *filename = "example.txt";
    char *file_contents = read_file_contents(filename);
    if (file_contents) {
        // Compare the file contents with another character array
        // Log to a file if needed
        
        // Free the memory allocated for file_contents
        free(file_contents);
    }

    return 0;
}
