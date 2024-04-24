#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char *ft_strdup(const char *s)
{
    // assuming you have the implementation for this function
}

char *read_input(const char *file)
{
    int fd;
    int read_stat;
    int i;
    int buffer_size = 1024;
    char *tmp = (char *)malloc(buffer_size);
    char buffer[1];

    if (!tmp)
    {
        printf("Error: memory allocation failed\n");
        return NULL;
    }

    i = 0;
    if ((fd = open(file, O_RDONLY)) == -1)
        printf("Error: file open failed\n");

    while ((read_stat = read(fd, buffer, 1)))
    {
        tmp[i++] = buffer[0];
        if (i == buffer_size)
        {
            buffer_size *= 2;
            tmp = (char *)realloc(tmp, buffer_size);
            if (!tmp)
            {
                printf("Error: memory reallocation failed\n");
                return NULL;
            }
        }
    }
    tmp[i] = '\0';
    if (close(fd) == -1)
        printf("Error: file close failed\n");

    return (ft_strdup(tmp));
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <file-to-read>\n", argv[0]);
        return 1;
    }

    char *file_contents = read_input(argv[1]);
    if (file_contents)
    {
        printf("%s\n", file_contents);
        free(file_contents);
    }

    return 0;
}
