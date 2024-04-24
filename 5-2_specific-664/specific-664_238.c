#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char *read_input(const char *file) {
    int fd;
    int read_stat;
    char *tmp = NULL;
    size_t i = 0;
    char buffer[1];

    if ((fd = open(file, O_RDONLY)) == -1) {
        printf("Error opening file\n");
        return NULL;
    }

    while ((read_stat = read(fd, buffer, 1))) {
        if (read_stat == -1) {
            printf("Error reading file\n");
            close(fd);
            free(tmp);
            return NULL;
        }
        
        char *new_tmp = realloc(tmp, i + 1);
        if (new_tmp == NULL) {
            printf("Error allocating memory\n");
            free(tmp);
            close(fd);
            return NULL;
        }
        tmp = new_tmp;

        tmp[i++] = buffer[0];
    }

    tmp = realloc(tmp, i + 1);
    if (tmp == NULL) {
        printf("Error allocating memory\n");
        close(fd);
        return NULL;
    }

    tmp[i] = '\0';

    if (close(fd) == -1) {
        printf("Error closing file\n");
    }

    return tmp;
}
