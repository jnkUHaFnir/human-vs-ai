#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define CHUNK_SIZE 1024

char    *read_input(const char *file)
{
    int         fd;
    ssize_t     read_stat;
    ssize_t     total_read = 0;
    char        *tmp = malloc(CHUNK_SIZE);
    char        buffer[CHUNK_SIZE];

    if (!tmp) {
        printf("Memory allocation error");
        return NULL;
    }

    if ((fd = open(file, O_RDONLY)) == -1) {
        printf("Error opening file");
        free(tmp);
        return NULL;
    }

    while ((read_stat = read(fd, buffer, CHUNK_SIZE)) > 0) {
        if (total_read + read_stat >= CHUNK_SIZE) {
            char *new_tmp = realloc(tmp, total_read + read_stat + CHUNK_SIZE);
            if (!new_tmp) {
                printf("Memory allocation error");
                free(tmp);
                close(fd);
                return NULL;
            }
            tmp = new_tmp;
        }

        memcpy(tmp + total_read, buffer, read_stat);
        total_read += read_stat;
    }

    if (read_stat == -1) {
        printf("Error reading file");
        free(tmp);
        close(fd);
        return NULL;
    }

    tmp[total_read] = '\0';
    if (close(fd) == -1) {
        printf("Error closing file");
    }

    return tmp;
}
