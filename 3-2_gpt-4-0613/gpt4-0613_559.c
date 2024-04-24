#include <stdio.h>
#include <stdlib.h>

char *readFile(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("fopen");
        return NULL;
    }

    if (fseek(file, 0, SEEK_END) == -1)
    {
        perror("fseek");
        fclose(file);
        return NULL;
    }

    long length = ftell(file);
    if (length == -1)
    {
        perror("ftell");
        fclose(file);
        return NULL;
    }

    char *buffer = malloc(length + 1);
    if (!buffer)
    {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    if (fseek(file, 0, SEEK_SET) == -1)
    {
        perror("fseek");
        free(buffer);
        fclose(file);
        return NULL;
    }

    size_t readLength = fread(buffer, 1, length, file);
    if (readLength != length)
    {
        free(buffer);
        fclose(file);
        return NULL;
    }

    buffer[length] = '\0';
    fclose(file);
    return buffer;
}
