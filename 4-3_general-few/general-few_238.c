#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *read_input(const char *file) {
    int fd;
    int read_stat;
    char *buffer = NULL;
    size_t file_size = 0;

    if ((fd = open(file, O_RDONLY)) == -1) {
        perror("Error opening file");
        return NULL;
    }

    // Get the size of the file
    off_t file_len = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    // Allocate memory based on the file size
    buffer = (char *)malloc(file_len + 1);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    while ((read_stat = read(fd, buffer + file_size, file_len - file_size))) {
        if (read_stat == -1) {
            perror("Error reading file");
            free(buffer);
            close(fd);
            return NULL;
        }
        file_size += read_stat;
    }

    buffer[file_size] = '\0';

    if (close(fd) == -1) {
        perror("Error closing file");
        free(buffer);
        return NULL;
    }

    return buffer;
}
