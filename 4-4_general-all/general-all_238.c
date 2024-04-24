#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define CHUNK_SIZE 1024

char *read_input(const char *file)
{
    int fd;
    int read_stat;
    int i = 0;
    char *tmp = NULL;
    char buffer[CHUNK_SIZE];

    if ((fd = open(file, O_RDONLY)) == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read_stat = read(fd, buffer, CHUNK_SIZE)) > 0)
    {
        char *temp = realloc(tmp, i + read_stat + 1); // +1 for null terminator
        if (temp == NULL)
        {
            perror("Memory reallocation failed");
            free(tmp);
            close(fd);
            exit(EXIT_FAILURE);
        }
        tmp = temp;
        for (int j = 0; j < read_stat; j++)
        {
            tmp[i++] = buffer[j];
        }
    }
    tmp[i] = '\0'; // Null-terminate the string

    if (read_stat == -1)
    {
        perror("Error reading file");
        free(tmp);
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1)
    {
        perror("Error closing file");
        free(tmp);
        exit(EXIT_FAILURE);
    }

    return tmp;
}
