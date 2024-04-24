#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *read_input(const char *file) {
    int    fd;
    int    i = 0;
    char   *tmp = NULL;
    char   buffer;

    if ((fd = open(file, O_RDONLY)) == -1) {
        perror("Error");
        return NULL;
    }

    // Dynamically allocate memory for tmp
    tmp = (char *)malloc(sizeof(char));
    if (tmp == NULL) {
        perror("Memory allocation failed");
        close(fd);
        return NULL;
    }

    while (read(fd, &buffer, 1) > 0) {
        tmp = (char *)realloc(tmp, (i + 1) * sizeof(char));
        if (tmp == NULL) {
            perror("Memory allocation failed");
            close(fd);
            return NULL;
        }
        tmp[i++] = buffer;
    }
    
    tmp = (char *)realloc(tmp, (i + 1) * sizeof(char));
    if (tmp == NULL) {
        perror("Memory allocation failed");
        close(fd);
        return NULL;
    }
    
    tmp[i] = '\0';

    if (close(fd) == -1) {
        perror("Error");
        free(tmp);
        return NULL;
    }

    return tmp;
}

int main() {
    char *result = read_input("input.txt");
    if (result != NULL) {
        printf("File content: %s\n", result);
        free(result);
    }

    return 0;
}
