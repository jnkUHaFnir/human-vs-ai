#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define INITIAL_SIZE 1024  // Initial buffer size.
#define READ_SIZE 128      // Size of each read operation.

char *read_input(const char *file)
{
    int fd;
    ssize_t read_stat;
    size_t total_read = 0; // Total bytes read.
    size_t buf_size = INITIAL_SIZE;
    char *buffer = malloc(buf_size);
    char temp_buf[READ_SIZE];
    
    if (!buffer)
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    if ((fd = open(file, O_RDONLY)) == -1)
    {
        printf("Error: Cannot open file\n");
        return NULL;
    }

    while ((read_stat = read(fd, temp_buf, READ_SIZE)) > 0)
    {
        // Check if we need to expand our buffer
        if (total_read + read_stat > buf_size)
        {
            buf_size *= 2; // Double the buffer size
            char *new_buffer = realloc(buffer, buf_size);
            if (!new_buffer)
            {
                printf("Error: Memory reallocation failed\n");
                close(fd);
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
        memcpy(buffer + total_read, temp_buf, read_stat);
        total_read += read_stat;
    }

    // Handling read errors
    if (read_stat == -1)
    {
        printf("Error: Reading file\n");
        close(fd);
        free(buffer);
        return NULL;
    }

    // Null-terminate the string
    if (total_read >= buf_size)
    {
        char *new_buffer = realloc(buffer, buf_size + 1); // Plus null-terminator
        if (!new_buffer)
        {
            printf("Error: Memory reallocation failed\n");
            close(fd);
            free(buffer);
            return NULL;
        }
        buffer = new_buffer;
    }
    buffer[total_read] = '\0';

    if (close(fd) == -1)
    {
        printf("Error: Closing file\n");
        free(buffer);
        return NULL;
    }

    return buffer;
}

// Make sure to add the appropriate error checking and handling as necessary
// Note: This example uses the POSIX defined functions open(), read(), and close().
// It's necessary to compile with libraries that support these calls.
