#include <stdlib.h>

char *read_input(const char *file)
{
    int fd;
    int read_stat;
    int i = 0;

    char *tmp = (char *)malloc(1024 * sizeof(char));
    if (tmp == NULL)
    {
        printf("Memory allocation error");
        exit(1);
    }

    if ((fd = open(file, O_RDONLY)) == -1)
    {
        printf("Error opening file");
        exit(1);
    }

    char buffer[1];
    while ((read_stat = read(fd, buffer, 1)))
    {
        tmp[i++] = buffer[0];

        if (i % 1024 == 0)
        {
            char *new_tmp = (char *)realloc(tmp, (i + 1024) * sizeof(char));
            if (new_tmp == NULL)
            {
                printf("Memory reallocation error");
                free(tmp);
                exit(1);
            }
            tmp = new_tmp;
        }
    }

    tmp[i] = '\0';

    if (close(fd) == -1)
    {
        printf("Error closing file");
        exit(1);
    }

    return tmp;
}
