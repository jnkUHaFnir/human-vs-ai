#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1, fd2;
    size_t nbytes;
    ssize_t bytes_read;

    fd1 = open(file1, O_RDONLY); // Open in read-only mode

    if (fd1 == -1) {
        perror("Error opening file1");
        return 1;
    }

    fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd2 == -1) {
        perror("Error opening file2");
        close(fd1);
        return 1;
    }

    // Dynamically allocate memory using malloc
    char *buf = (char *)malloc(BUFSIZ);

    if (buf == NULL) {
        perror("Error allocating memory");
        close(fd1);
        close(fd2);
        return 1;
    }

    nbytes = BUFSIZ;
    bytes_read = read(fd1, buf, nbytes);

    if (bytes_read == -1) {
        perror("Error reading from file1");
        free(buf);
        close(fd1);
        close(fd2);
        return 1;
    }

    if (write(fd2, buf, bytes_read) != bytes_read) {
        perror("Error writing to file2");
        free(buf);
        close(fd1);
        close(fd2);
        return 1;
    }

    free(buf);
    close(fd1);
    close(fd2);

    return 0;
}
