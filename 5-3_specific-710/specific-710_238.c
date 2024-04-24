#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define CHUNK_SIZE 1024 // Chunk size for dynamically growing buffer

char *read_input(const char *file)
{
    int fd;
    int read_stat;
    size_t i = 0; // Size type for storing buffer index
    char *tmp = malloc(sizeof(char) * CHUNK_SIZE); // Allocate initial buffer
    char buffer[1];

    if (!tmp)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    if ((fd = open(file, O_RDONLY)) == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read_stat = read(fd, buffer, 1)))
    {
        tmp[i++] = buffer[0];
        if (i % CHUNK_SIZE == 0)
        {
            char *new_tmp = realloc(tmp, (i + CHUNK_SIZE) * sizeof(char));
            if (!new_tmp)
            {
                perror("Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
            tmp = new_tmp;
        }
    }
    tmp[i] = '\0';

    if (close(fd) == -1)
    {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    return tmp;
}
