char *buf[len];
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        // Use proper arguments
        return 1;
    }

    const char *file1 = argv[1];
    const char *file2 = argv[2];

    int fd1;
    int fd2;
    size_t nbytes;
    ssize_t bytes_read, bytes_written;

    fd1 = open(file1, O_RDONLY);

    fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644 );

    nbytes = 4096; // Choose the size of the buffer, for example, 4096 bytes
    char *buf = malloc(nbytes); // Allocate memory for the buffer

    while ((bytes_read = read(fd1, buf, nbytes)) > 0) {
        bytes_written = write(fd2, buf, bytes_read); // Write only the bytes that were read, not nbytes
        if (bytes_written != bytes_read) {
            // Handle the error, possibly with perror() or a custom message
            break;
        }
    }

    // Free the allocated memory
    free(buf);

    close(fd1);
    close(fd2);

    return 0;
}
