#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char *read_input(const char *file) {
    int         fd;
    int         read_stat;
    struct stat file_stat;
    char        *content;
    size_t      total_read = 0;
    size_t      buffer_size = 1024; // Start with a reasonable buffer size.
    
    // Open the file
    if ((fd = open(file, O_RDONLY)) == -1) {
        perror("Error opening file");
        return NULL;
    }
    
    // Get the file size (if available)
    if (fstat(fd, &file_stat) == -1) {
        perror("Error getting file size");
        close(fd);
        return NULL;
    }
    
    // Allocate initial buffer
    content = malloc(buffer_size);
    if (!content) {
        perror("Memory allocation failed");
        close(fd);
        return NULL;
    }
    
    // Read the file in chunks
    while ((read_stat = read(fd, content + total_read, buffer_size - total_read - 1)) > 0) {
        total_read += read_stat;
        // Check if we have reached the buffer limit and need more space
        if (total_read == buffer_size - 1) {
            buffer_size *= 2; // Double the buffer size
            char *new_content = realloc(content, buffer_size);
            if (!new_content) {
                perror("Memory reallocation failed");
                free(content);
                close(fd);
                return NULL;
            }
            content = new_content;
        }
    }
    // Check for read error
    if (read_stat == -1) {
        perror("Error reading file");
        free(content);
        close(fd);
        return NULL;
    }
    
    // Null terminate the string
    content[total_read] = '\0';
    
    // Close the file descriptor
    if (close(fd) == -1) {
        perror("Error closing file");
        free(content);
        return NULL;
    }
    
    // Optionally shrink the buffer to fit the content
    char *shrinked_content = realloc(content, total_read + 1);
    if (shrinked_content) {
        content = shrinked_content;
    }
    
    return content;
}

// Usage example
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    char *file_content = read_input(argv[1]);
    
    if (file_content) {
        printf("File content:\n%s", file_content);
        free(file_content); // Important to free the allocated memory
    } else {
        fprintf(stderr, "Failed to read file.\n");
    }
    
    return 0;
}
