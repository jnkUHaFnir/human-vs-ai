#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *read_input(const char *file) {
    int fd;
    int read_stat;
    int i = 0;
    char *tmp = NULL;
    char buffer[1];

    if ((fd = open(file, O_RDONLY)) == -1) {
        printf("Error: Could not open file\n");
        return NULL;
    }

    while ((read_stat = read(fd, buffer, 1)) > 0) {
        char *new_tmp = realloc(tmp, i + 2);
        if (new_tmp == NULL) {
            printf("Error: Out of memory\n");
            free(tmp);
            close(fd);
            return NULL;
        }
        tmp = new_tmp;
        tmp[i++] = buffer[0];
    }

    if (read_stat < 0) {
        printf("Error: Failed to read file\n");
        free(tmp);
        close(fd);
        return NULL;
    }

    tmp[i] = '\0';

    if (close(fd) == -1) {
        printf("Error: Failed to close file\n");
        free(tmp);
        return NULL;
    }

    return tmp;
}
