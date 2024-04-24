#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 100

char *read_input(const char *file) {
    int fd;
    ssize_t read_stat;
    char buffer[BUFFER_SIZE];
    char *tmp = NULL;
    size_t tmp_size = 0;
    
    if ((fd = open(file, O_RDONLY)) == -1) {
        perror("Error opening file");
        return NULL;
    }

    while ((read_stat = read(fd, buffer, BUFFER_SIZE)) > 0) {
        char *temp = realloc(tmp, tmp_size + read_stat + 1);  // +1 for null terminator
        if (temp == NULL) {
            perror("Error reallocating memory");
            free(tmp);
            close(fd);
            return NULL;
        }

        tmp = temp;
        memcpy(tmp + tmp_size, buffer, read_stat);
        tmp_size += read_stat;
    }
    
    if (read_stat == -1) {
        perror("Error reading file");
        free(tmp);
        close(fd);
        return NULL;
    }

    tmp[tmp_size] = '\0';

    if (close(fd) == -1) {
        perror("Error closing file");
        free(tmp);
        return NULL;
    }

    return tmp;
}
