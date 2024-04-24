#include <stdio.h>
#include <stdlib.h>

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > 4 * 1024 * 1024) { // 4 GB limit
        fclose(file);
        fprintf(stderr, "File size exceeds limit\n");
        return NULL;
    }

    char* contents = (char*)malloc(file_size + 1); // +1 for null terminator
    if (contents == NULL) {
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    size_t bytes_read = fread(contents, 1, file_size, file);
    if (bytes_read != file_size) {
        fclose(file);
        free(contents);
        fprintf(stderr, "Error reading file\n");
        return NULL;
    }

    contents[file_size] = '\0'; // Null-terminate the string

    fclose(file);
    return contents;
}

int main() {
    const char* filename = "example.txt";
    char* file_contents = read_file(filename);
    
    if (file_contents != NULL) {
        // Use file_contents as needed
        
        // Don't forget to free the memory allocated for file_contents
        free(file_contents); 
    }

    return 0;
}
